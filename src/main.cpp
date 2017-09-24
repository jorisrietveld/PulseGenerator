/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-09-2017 22:35
 * License: GPLv3 - General Public License version 3
 */
#include <Arduino.h>
#include <Streaming.h>
/*
#define PORT_PULSE 7
#define PIN_POTENTIOMETER A5
#define POTENTIOMETER_FLOOR 1
#define POTENTIOMETER_CEILING 10

uint64_t delayDuration = 1000;
uint64_t lastFlip=0;
bool state = LOW;
uint16_t rawPotValue = 0;
uint8_t scaledPotValue = 0;
uint64_t currentRange = 1000; // default 0 - 10 Hz 1000 ms - 100 ms

IRrecv pulseGeneratorReceiver(2);

void generateLowFrequentyPulses()
{
    uint64_t now = millis();
    if (now - lastFlip >= delayDuration )
    {
        lastFlip = now;
        state = !state;
        digitalWrite(7, state);
    }
}

void measurePotentiometer()
{
    rawPotValue = analogRead( PIN_POTENTIOMETER);
    scaledPotValue = map( rawPotValue, 0, 1024, POTENTIOMETER_FLOOR, POTENTIOMETER_CEILING );
    delayDuration = (1000 / scaledPotValue);
}

void setup()
{
    pinMode( PORT_PULSE, OUTPUT);
    pinMode( PIN_POTENTIOMETER, INPUT);
    Serial.begin(9600);
}

void loop()
{
    measurePotentiometer();
    generateLowFrequentyPulses();
}*/
#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
    Serial.begin(9600);
    // In case the interrupt driver crashes on setup, give a clue
    // to the user what's going on.
    Serial.println("Enabling IRin");
    irrecv.enableIRIn(); // Start the receiver
    Serial.println("Enabled IRin");
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        irrecv.resume(); // Receive the next value
    }
    delay(100);
}