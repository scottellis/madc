/*
 * Test program to read twl4030-madc ADCs on a Gumstix Overo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdint.h>

/* 
 Copied twl4030-madc.h from kernel src include/linux/i2c 
 and needed a couple of user typedefs for the user kernel types. 
*/
typedef uint8_t u8;
typedef uint16_t u16;
 
#include "twl4030-madc.h"


int read_channel(int fd, int ch)
{
	int ret;
	struct twl4030_madc_user_parms param;
	double voltage;	

	memset(&param, 0, sizeof(param));

	param.channel = ch;

	ret = ioctl(fd, TWL4030_MADC_IOCX_ADC_RAW_READ, &param);

	if (ret < 0) {
		perror("ioctl");
		return ret;
	}

	/* 10 bit ADC, reference voltage 2.5v */
	voltage = (param.result * 2.5) / 1024.0;

	printf("madc: ch = %2d status = %d  result = %4u  voltage = %0.2lf\n",
		param.channel, param.status, param.result, voltage);

	return param.status;
}

void read_all_channels(int fd)
{
	int i;

	for (i = 0; i < TWL4030_MADC_MAX_CHANNELS; i++)
		read_channel(fd, i);
}

int main(int argc, char **argv)
{
	int fd, i, ch, done;

	done = 0;

	fd = open("/dev/twl4030-madc", O_RDWR | O_NONBLOCK, 0);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	if (argc < 2) {
		printf("Usage: %s <channel list, space separated>\n", argv[0]);
		printf("       %s all\n", argv[0]);
		exit(0);
	}
	else if (argc == 2) {
		/* special case, check for 'all' */
		if (!strcmp(argv[1], "all")) {
			read_all_channels(fd);
			done = 1;
		}
	}

	if (!done) {
		for (i = 1; i < argc; i++) {
			ch = atoi(argv[i]);	
				
			if (ch >= 0 && ch < TWL4030_MADC_MAX_CHANNELS)
				read_channel(fd, ch);
			else
				printf("Bad channel number %d\n", ch);
		}
	}

	close(fd);

	return 0;
}

