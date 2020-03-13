#include <Wire.h>

int freno=24;
int xpin=A3;
int valor=0;
int vel=0;
int dir=0;

void setup() {
  //Wire.begin();
  Serial.begin(4800);
  pinMode(freno,INPUT);
}

void loop() {
  valor= analogRead(xpin);

  if (digitalRead(freno)==HIGH){
    vel=255;
    dir=3;
  }else{
    //va de 0 a 255 o de 0 a -255
    if (valor>330.5 && valor<336.5){
      dir = 0;
      vel= 0;
    }else{
      dir=1;
      valor=valor-333.5;
      if (valor<0){
        valor=-valor;
        dir=2;
      }
      vel=(valor*255)/66.5;
      if (vel>255){
        vel=255;
      }
    }
  }
  
//  Wire.beginTransmission(8);
//  Wire.write(dir);
//  Wire.write(vel);
//  Wire.endTransmission();

  Serial.write(dir);
  delay(100);
  Serial.write(vel);
  delay(100);
}
