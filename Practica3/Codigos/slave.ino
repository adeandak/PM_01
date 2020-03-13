#include <Wire.h>

int fward=7;
int bward=6;
int enable=2;
int vel=0;
int dir=0;

void setup() {
//  Wire.begin(8);
//  Wire.onReceive(reception);
  Serial.begin(4800);
  pinMode(fward,OUTPUT);
  pinMode(bward,OUTPUT);
  pinMode(enable,OUTPUT);
  analogWrite(bward,0);
  analogWrite(fward,0);
  digitalWrite(enable,LOW);
}

void loop() {
  if(Serial.available()>1){
    dir=Serial.read();
    vel=Serial.read();
  }
  switch (dir) {
  case 0:
    //freno pasivo
    digitalWrite(enable,LOW);
    break;
  case 1:
    //avanzar hacia delante
    analogWrite(fward,0);
    analogWrite(bward,vel);
    digitalWrite(enable,HIGH);
    break;
  case 2:
    //avanzar hacia atras
    analogWrite(fward,vel);
    analogWrite(bward,0);
    digitalWrite(enable,HIGH);
    break;
  case 3:
    //freno activo
    pinMode(bward,OUTPUT);
    pinMode(enable,OUTPUT);
    analogWrite(bward,vel);
    analogWrite(fward,vel);
    digitalWrite(enable,HIGH);
    break;
  }
}
