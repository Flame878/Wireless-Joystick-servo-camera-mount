#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10);
#define xPin A2
const int swPin = 2;
const byte address[6] = "00001";
int currentAngle = 90;
int reset = 90;
struct SendValues{
  int xVal;
};
SendValues Sendval;
void setup() {
pinMode(swPin, INPUT_PULLUP);
Serial.begin(9600);  
radio.begin();
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_LOW);
radio.stopListening();
}

void loop() {
Sendval.xVal = analogRead(xPin);
int deadZoneLow = 450;
int deadZoneHigh = 570;
int SwP = digitalRead(swPin);
if (Sendval.xVal > deadZoneHigh) {
  currentAngle += 1;
}
else if (Sendval.xVal < deadZoneLow) {
  currentAngle -= 1;
}

if (SwP == LOW){
  currentAngle = reset;
}

currentAngle = constrain(currentAngle, 0, 180);
Sendval.xVal = currentAngle;

radio.write(&Sendval, sizeof(Sendval));
Serial.print("Sending X: ");
Serial.println(Sendval.xVal);
delay(20);

}
