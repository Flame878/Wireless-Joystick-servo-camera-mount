#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
RF24 radio(9, 10);
const byte address[6] = "00001";
Servo servoM;
const int servoPin = 5;
struct RecievedData{
  int xVal;
};
RecievedData receieveData;
void setup() {
Serial.begin(9600);  
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_LOW);
radio.startListening();
servoM.attach(servoPin);
}

void loop() {
if (radio.available()){
  
  radio.read(&receieveData, sizeof(receieveData));
  servoM.write(receieveData.xVal);
  Serial.print("RecievedAngle");
  Serial.println(receieveData.xVal);
}
}