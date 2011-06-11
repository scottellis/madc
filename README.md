  madc-test
=======

Simple example program to read the Overo twl4030-madc values.

The twl4030-madc are 10-bit ADC's with a voltage input range 0 - 2.5v


  Download Code
-------

The Makefile is for an OE cross-compile setup on a workstation typical with gumstix usage.

	~$ git clone git://github.com/scottellis/madc.git
	~$ cd madc
	~/madc$ make


Copy the resulting madc-test executable to the Overo however is convenient.


  Run
-------

Assuming you copied the madc-test program to /home/root on the Overo.

	root@overo:~# ./madc-test all
	madc: ch =  0 status = 0  result =    0  voltage = 0.00
	madc: ch =  1 status = 0  result =   50  voltage = 0.12
	madc: ch =  2 status = 0  result =    6  voltage = 0.01
	madc: ch =  3 status = 0  result =    3  voltage = 0.01
	madc: ch =  4 status = 0  result =    5  voltage = 0.01
	madc: ch =  5 status = 0  result =    3  voltage = 0.01
	madc: ch =  6 status = 0  result =    3  voltage = 0.01
	madc: ch =  7 status = 0  result =  560  voltage = 1.37
	madc: ch =  8 status = 0  result =    4  voltage = 0.01
	madc: ch =  9 status = 0  result =  719  voltage = 1.76
	madc: ch = 10 status = 0  result =    0  voltage = 0.00
	madc: ch = 11 status = 0  result =    0  voltage = 0.00
	madc: ch = 12 status = 0  result =  565  voltage = 1.38
	madc: ch = 13 status = 0  result =    4  voltage = 0.01
	madc: ch = 14 status = 0  result =    2  voltage = 0.00
	madc: ch = 15 status = 0  result =    0  voltage = 0.00

To read specific channels only, pass the channels, space separated

	root@overo:~# ./madc-test 2 3 4 5 6
	madc: ch =  2 status = 0  result =  644  voltage = 1.57
	madc: ch =  3 status = 0  result =  646  voltage = 1.58
	madc: ch =  4 status = 0  result =  643  voltage = 1.57
	madc: ch =  5 status = 0  result =  647  voltage = 1.58
	madc: ch =  6 status = 0  result =  646  voltage = 1.58

(Channels 2-6 were exposed to a 1.5v signal for that test.)

The exposed ADC pins on the Overo Summit/Tobi expansion headers.

	AGND   : Pin 37

	ADCIN2 : Pin 34
	ADCIN3 : Pin 38
	ADCIN4 : Pin 39
	ADCIN5 : Pin 36
	ADCIN6 : Pin 35
	ADCIN7 : Pin 33  appears to be in use, TODO


