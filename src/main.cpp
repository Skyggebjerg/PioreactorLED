#include <Arduino.h>

#include <M5Unified.h>

int sensorPin =
    32;  // set the input pin on ATOM for the potentiometer.

int last_sensorValue =
    100;  // Stores the value last read by the sensor.
int cur_sensorValue = 0;  // Stores the value currently read by the sensor.
int led = 26;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is

void setup() {
    M5.begin();        // Init M5Stack.
    Serial.begin(115200);
    //M5.Power.begin();  // Init power 
    pinMode(sensorPin, INPUT);  // Sets the specified pin to input mode.
    pinMode(led, OUTPUT);
}

void loop() {
    cur_sensorValue = analogRead(sensorPin);  // read the value from the sensor
    cur_sensorValue = 4095 - cur_sensorValue;
    brightness = cur_sensorValue/16;
        analogWrite(led, brightness);
      Serial.println(cur_sensorValue);
      Serial.println(brightness);

            delay(50);
}

