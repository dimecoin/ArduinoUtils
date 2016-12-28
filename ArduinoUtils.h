#ifndef ARDUINO_UTILS_H
#define ARDUINO_UTILS_H

#include <Arduino.h>
#include <Wire.h>


/** Gets the internal temp of the MPU.
 * We have to wait for readings (voltage) to stablize.  If you get bad values, try increasing delay
 * delay = -1 : use default of 6 ms, this is typically fastest you can query.
 * delay = X: use your own value, increase higher if you get bad readings.
 * WARNING: this will block for delay milliseconds.
 *
 * Taken from : http://playground.arduino.cc/Main/InternalTemperatureSensor
 */
double getTemperature(int8_t delayTime);

/**
 * Takes a byte and gives you a nice (padded) string of binary to make printing binary pretty.
 * 
 * Partailly taken from : http://forum.arduino.cc/index.php?topic=46320.msg335376#msg335376
 */
String getBitString(uint8_t byte);

/** Clears serial console screen 
 * optionally, force a flush()
 * Source: http://stackoverflow.com/a/15559322
 **/

void clearSerialConsole(bool flush);

/**
 * Scans for I2C devices and prints to serial console.
 * Assumes you have a working Serial setup.
 * source: https://arduino-info.wikispaces.com/LCD-Blue-I2C
 */

void scanI2CDevices(void);

#endif
