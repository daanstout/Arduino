#include <Wire.h>

int input = A0;
int val = 0;
int M1 = 5;
int E1 = 4;
int M2 = 6;
int E2 = 7;
int snelheid = 0;
String trainPos = "up";
int c;
byte buffer[];

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
  if(trainPos == "up"){
    trainPos = "down";
  }else if(trainPos == "down"){
    trainPos = "up";
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
    c = Wire.readBytesUntil(',', buffer[], 1);
  }
  String trainStart;
  if(c == 1){
    trainStart = "up";
  }else if(c == 0){
    trainStart = "down";
  }
  BBPBandLeft();
  BBPBandStart();
  if(trainStart == trainPos){
    boolean bandLoop = true;
    while(bandLoop){
      if(analogRead(input) > 1000){
        Serial.println("pakket");
        delay(1000);
        bandLoop = false;
      }
    }
    BBPBandStop();
  }else if(trainStart != trainPos){
    boolean bandLoop = true;
    while(bandLoop){
      if(analogRead(input) > 1000){
        Serial.println("pakket");
        BBPBandStop();
        if(trainPos == "down"){
          BBPTrainUp();
        }else if(trainPos == "up"){
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
