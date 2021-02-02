#include <Arduino.h>

/*
 * Function prototypes.
 */
float getVoltage(int pin);

/*
 * Simple program to output the current temperature via serial
 * using the TMP36 sensor.
 */

// TMP36 signal pin on analog pin 0
int temperaturePin = 0;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  float temperature = getVoltage(temperaturePin);

  temperature = (temperature - 0.5) * 100;

  float temperatureF = (temperature * 1.8) + 32;

  Serial.print(temperature, 2);
  Serial.print(" C, ");
  Serial.print(temperatureF, 2);
  Serial.println(" F");

  delay(2000);
}

float getVoltage(int pin) {
  return (analogRead(pin) * 0.004882814);
}
