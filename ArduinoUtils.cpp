#include "ArduinoUtils.h"

double getTemperature(int8_t delayTime) {

	if (delayTime == -1) {
		delayTime = 6;
	}

	unsigned int wADC;
	double t;

	// The internal temperature has to be used
	// with the internal reference of 1.1V.
	// Channel 8 can not be selected with
	// the analogRead function yet.

	// Set the internal reference and mux.
	ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
	ADCSRA |= _BV(ADEN);	// enable the ADC

	delay(delayTime);	// wait for voltages to become stable.

	ADCSRA |= _BV(ADSC);	// Start the ADC

	// Detect end-of-conversion
	while (bit_is_set(ADCSRA, ADSC)) ;

	// Reading register "ADCW" takes care of how to read ADCL and ADCH.
	wADC = ADCW;

	// The offset of 324.31 could be wrong. It is just an indication.
	t = (wADC - 324.31) / 1.22;

	// The returned temperature is in degrees Celsius.
	return (t);
}

String getBitString(uint8_t in) {

	String bitString = "";
	for (byte mask = 0x80; mask; mask >>= 1) {
		if (mask & in) {
			bitString += '1';
		} else {
			bitString += '0';
		}
	}

	return (bitString);

}

void clearSerialConsole(bool flush) {

	Serial.write(27);	// ESC command
	Serial.print("[2J");	// clear screen command
	Serial.write(27);
	Serial.print("[H");	// cursor to home command

	if (flush) {
		Serial.flush();
	}
}

void scanI2CDevices(void) {
	Serial.println();
	Serial.println("I2C scanner. Scanning ...");
	byte count = 0;

	Wire.begin();
	for (byte i = 8; i < 120; i++) {
		Wire.beginTransmission(i);
		if (Wire.endTransmission() == 0) {
			Serial.print("Found address: ");
			Serial.print(i, DEC);
			Serial.print(" (0x");
			Serial.print(i, HEX);
			Serial.println(")");
			count++;
			delay(1);	// maybe unneeded?
		}		// end of good response
	}			// end of for loop
	Serial.println("Done.");
	Serial.print("Found ");
	Serial.print(count, DEC);
	Serial.println(" device(s).");
}
