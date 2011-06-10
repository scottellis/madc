/*
 *  V4L2 video capture example
 *
 *  This program can be used and distributed without restrictions.
 *
 *  Modified and hard-coded for my own camera testing.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <stdint.h>

/* copied from kernel src include/linux/i2c */
#define u8 	uint8_t
#define u16	uint16_t
 
#include "twl4030-madc.h"


int main(int argc, char **argv)
{
	int fd, i;
	struct twl4030_madc_user_parms param;

	fd = open("/dev/twl4030-madc", O_RDWR | O_NONBLOCK, 0);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	for (i = 0; i < TWL4030_MADC_MAX_CHANNELS; i++) {
		memset(&param, 0, sizeof(param));

		param.channel = i;

		if (ioctl(fd, TWL4030_MADC_IOCX_ADC_RAW_READ, &param)) {
			perror("ioctl");
			break;
		}

		printf("madc: ch = %2d  average = %d  status = %d  result = %u\n",
			param.channel, param.average, param.status, param.result);
	}

	close(fd);

	return 0;
}

