#ifndef ARDUINO_UTILS_H
#define ARDUINO_UTILS_H

#include <Arduino.h>
/** Gets the internal temp of the MPU.
 * We have to wait for readings (voltage) to stablize.  If you get bad values, try increasing delay
 * delay = -1 : use default, fast possiable 
 * delay = X: use your own value, increase higher if you get bad readings.
 * WARNING: this will block for delay milliseconds.
 */
double getTemperature(int8_t delayTime);

#endif
