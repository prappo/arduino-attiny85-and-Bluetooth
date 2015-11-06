/*
Takes an input on the AtTiny85 from the VERY TRICKY analogue input pin 2 (as labeled in HLT tutorial)
and outputs these with Software serial to the arduino uno, or Duemillanove
Hookup 
ATTINY85 pin 3 -> Arduino Uno pin 0
ATTINY85 pin 4 -> Arduino Uno pin 1
 */


#include <SoftwareSerial.h>
// Definitions
#define rxPin 3
#define txPin 4

SoftwareSerial mySerial(rxPin, txPin);
int data;
int sensorPin = 7; //ACTUALLY PIN LABELED AS "2" on the HLT tutorial
int sensorVal = -1;

boolean switchFans = 0;


// the setup routine runs once when you press reset:
void setup() {                
  pinMode(sensorPin, INPUT);
  mySerial.begin(9600);
   pinMode(1, OUTPUT);
   pinMode(2, OUTPUT);

}

// the loop routine runs over and over asensorpingain forever:
void loop() {
if(mySerial.available()){
  data = mySerial.read();
  if(data=='7'){
    digitalWrite(1,HIGH);
  }
  else if(data == 'a'){
    digitalWrite(1,LOW);
  }
  else if(data == '6'){
    digitalWrite(2,HIGH);
  }
  else if(data == 'b'){
    digitalWrite(2,LOW);
  }
}
 
}
