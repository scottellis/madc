  madc-test
=======

Simple example program to read the Overo twl4030-madc values.

The twl4030-madc are 10-bit ADC's with a voltage input range 0 - 2.5v


  Download and Build
-------

The Makefile assumes a typical Gumstix OE cross-compile setup on a workstation.
You can export a different OETMP in your environment if you aren't using the 
default Gumstix paths.

	~$ git clone git://github.com/scottellis/madc.git
	~$ cd madc
	~/madc$ make

or for a different OETMP

	~/madc$ OETMP=/oe1 make


Copy the resulting madc-test executable to the Overo however is convenient.


  Usage
-------

Assuming you copied the madc-test program to /home/root on the Overo.

	root@overo:~# ./madc-test -h
	Usage: ./madc-test [options] [channel list]
	Options
	  -a          Request the device driver average 4 readings
	  -m          Machine readable format ch:raw:voltage
	  -h          Show this help message

	channel list  A space separated list of channel numbers 0-15.
		      If no channel list is supplied, channels 2-6 are read.

	  Example: ./madc-test -a 2 4 6


So for example

	root@overo:~# ./madc-test   
	madc[ 2] raw =  413  voltage = 1.01
	madc[ 3] raw =  405  voltage = 0.99
	madc[ 4] raw =  407  voltage = 0.99
	madc[ 5] raw =  405  voltage = 0.99
	madc[ 6] raw =  403  voltage = 0.98

Channels 2-6 had 1.0v applied with a bench power supply.


Or two channels, average of 4 reads, output in machine friendly format 

	root@overo:~# ./madc-test -a -m 2 4   
	2:615:1.50
	4:618:1.51

Channel 2 and 4 had ~1.5v applied for that test.


The exposed ADC pins on the Overo Summit/Tobi expansion headers.

	AGND   : Pin 37

	ADCIN2 : Pin 34
	ADCIN3 : Pin 38
	ADCIN4 : Pin 39
	ADCIN5 : Pin 36
	ADCIN6 : Pin 35
	ADCIN7 : Pin 33  appears to be in use, TODO: research this


