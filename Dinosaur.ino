/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 modified 19 Jun 2016 by Clement Levallois

 This example code is in the public domain.

 http://www.clementlevallois.net/dinosaur

 */

int sensorPin = A0;    // input pin for the light sensor
int ledPinR = 10; // right eye of the dino
int ledPinL = 6; // left eye of the dino
int buzzPin = 9; // voice of the dino

int sensorValue;  // variable to store the value coming from the light sensor


void setup() {
  pinMode(buzzPin,OUTPUT);
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinL,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:

  sensorValue = analogRead(sensorPin);
  Serial.print("before: ");
  Serial.println(sensorValue);

  sensorValue = map(sensorValue, 290, 1000, 0, 255);
  sensorValue = constrain(sensorValue, 0, 255);

  if (sensorValue < 220){
    sensorValue = 0;
  }
  else{
    sensorValue = 300;
  }
  Serial.print("after: ");
  Serial.println(sensorValue);
  
  // turn the ledPin on
  analogWrite(ledPinR, sensorValue);
  analogWrite(ledPinL, sensorValue);
    if (sensorValue>0){
    int count;
    for (int i = sensorValue;i <sensorValue+200;i++){
      tone(buzzPin, i, 10);
      modulate(i);
      delay(1);
      count = i;    
     }
    for (int i = count;i > sensorValue;i--){
      tone(buzzPin, i, 10);    
      modulate(i);
      delay(1);
    }
  }
  delay(3000);
}

void modulate (int freq){
    for (int j = freq;j <freq+10;j++){
      tone(buzzPin, j, 20);
      delay(10);
     }
    for (int j = freq+10;j >freq;j--){
      tone(buzzPin, j, 20);
      delay(10);
     }
}  

