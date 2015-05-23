#include <Wire.h>

String string;
int input = A0;
int E1 = 5;
int M1 = 4;
int E2 = 6;
int M2 = 7;
int snelheid = 0;

void setup(){
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void BBPBandLeft(){
  digitalWrite(M1, LOW);
  snelheid = 150;
}

void BBPBandRight(){
  digitalWrite(M1, HIGH);
  snelheid = 150;
}

void BBPBandStart(){
  digitalWrite(E1, snelheid);
}

void BBPBandStop(){
  digitalWrite(E1, 0);
}

void BBPTrainUp(){
  digitalWrite(M2, LOW);
  snelheid = 150;
}

void BBPTrainDown(){
  digitalWrite(M2, HIGH);
  snelheid = 150;
}

void BBPTrainStart(){
  digitalWrite(E2, snelheid);
}

void BBPTrainStop(){
  digitalWrite(E2, 0);
}

void loop(){
  delay(100);
}

void receiveEvent(int howMany){
  while(Wire.available()){
    char c = Wire.read();
    string = string + c;
  }
  
  if(string == "BandLeft"){
    BBPBandLeft();
    BBPBandStart();
    delay(5000);
    BBPBandStop();
  }else if(string == "BandRight"){
    BBPBandRight();
    BBPBandStart();
    delay(5000);
    BBPBandStop();
  }else if(string == "TrainUp"){
    BBPTrainUp();
    BBPTrainStart();
    delay(1500);
    BBPTrainStop();
  }else if(string == "TrainDown"){
    BBPTrainDown();
    BBPTrainStart();
    delay(1500);
    BBPTrainStop();
  }
}
