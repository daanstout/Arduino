#include <Wire.h>

int input = A0;
int val = 0;
int M1 = 5;
int E1 = 4;
int M2 = 6;
int E2 = 7;
int snelheid = 0;
int trainPos = 0;
int c;

void setup(){
  Serial.begin(9600);
  pinMode(input, INPUT);
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
}

void BBPBandLeft(){
  digitalWrite(E1, LOW);
  snelheid = 150;
}

void BBPBandRight(){
  digitalWrite(E1, HIGH);
  snelheid = 150;
}

void BBPBandStart(){
  Serial.println("check");
  digitalWrite(M1, snelheid);
  Serial.println("check2");
}

void BBPBandStop(){
  digitalWrite(M1, 0);
}

void BBPTrainUp(){
  digitalWrite(E2, 0);
  snelheid = 1;
}

void BBPTrainDown(){
  digitalWrite(E2, 3);
  snelheid = 1;
}

void BBPTrainStop(){
  digitalWrite(M2, LOW);
}

void BBPTrainStart(){
  Serial.println("start");
  if(trainPos == 0){
    trainPos = 1;
  }else if(trainPos == 1){
    trainPos = 0;
  }
  digitalWrite(M2, HIGH);
  delay(400);
  BBPTrainStop();
}

void loop(){
  delay(100);
}

void receiveEvent(int howMany){
  while(Wire.available()){
    c = Wire.read();
  }
  BBPBandLeft();
  BBPBandStart();
  if(c == trainPos){
    boolean bandLoop = true;
    while(bandLoop){
      if(analogRead(input) < 700){
        delay(1000);
        bandLoop = false;
      }
    }
    BBPBandStop();
  }else if(c != trainPos){
    boolean bandLoop = true;
    while(bandLoop){
      if(analogRead(input) < 700){
        BBPBandStop();
        if(trainPos == 1){
          BBPTrainUp();
        }else if(trainPos == 0){
          BBPTrainDown();
        }
        BBPTrainStart();
        BBPBandStart();
        bandLoop = false;
      }
    }
    BBPBandStop();
  }
}
