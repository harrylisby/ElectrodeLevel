#include <Arduino.h>
#define sensorIn 2
#define electrodeLow A2
#define electrodeHigh A3
#define dischOut 5
#define chargOut 6

bool highStatus = false;
bool lowStatus = false;
bool electrodeStatus = false;


void setup() {
  pinMode(sensorIn,INPUT_PULLUP);
  pinMode(dischOut,OUTPUT);
  pinMode(chargOut,OUTPUT);
  pinMode(electrodeHigh,INPUT);
  pinMode(electrodeLow,INPUT);

  Serial.begin(9600);

}

void loop() {

  highStatus=digitalRead(electrodeHigh);
  lowStatus=digitalRead(electrodeLow);

  if(highStatus){
    electrodeStatus = true;
    if(!lowStatus){
      electrodeStatus = false;
    }
  }
  if(!lowStatus){
    electrodeStatus=false;
  }


  if((!digitalRead(sensorIn))){
    digitalWrite(chargOut,HIGH);
    digitalWrite(dischOut,HIGH);
  }else if(!electrodeStatus){
    digitalWrite(chargOut,HIGH);
    digitalWrite(dischOut,LOW);
  }else{
    digitalWrite(chargOut,LOW);
    digitalWrite(dischOut,LOW);
  }

  if(true){
    Serial.println("LOW: "+String(lowStatus)+" HIGH: "+String(highStatus));

  }

}
