#include <Servo.h>

#define legoSensorPin 14
#define legoSensor 0

Servo myservo;

int pos = 0;
int inputa = A0;
int inputb = A1;
int E1 = 5;
int M1 = 4;
int E2 = 6;
int M2 = 7;
int snelheid = 0;
int val = 0;

void setup(){
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(inputa, INPUT);
  myservo.attach(9);
}

int stringtoInt(String intToString){
  if(intToString == "0"){
    return 0;
  }else if(intToString == "1"){
    return 1;
  }else if(intToString == "2"){
    return 2;
  }else if(intToString == "3"){
    return 3;
  }else if(intToString == "4"){
    return 4;
  }else if(intToString == "5"){
    return 5;
  }else{
    return 0;
  }
}

void TSPLiftUp(){
  digitalWrite(M2, LOW);
  snelheid = 100;
}

void TSPLiftDown(){
  digitalWrite(M2, HIGH);
}

void TSPLiftStart(){
  digitalWrite(E2, snelheid);
}

void TSPLiftStop(){
  digitalWrite(E2, 0);
}

void TSPRunLiftUp(int hoeveel){
  TSPLiftUp();
  TSPLiftStart();
  int aantalUp = 0;
  while(aantalUp<hoeveel){
    if(analogRead(inputb < 700)){
      aantalUp = aantalUp + 1;
    }
    delay(500);
  }
  TSPLiftStop();
}

void TSPRunLiftDown(int hoeveel){
  TSPLiftDown();
  TSPLiftStart();
  int aantalDown = 0;
  while(aantalDown<hoeveel){
    if(analogRead(inputb < 700)){
      aantalDown = aantalDown + 1;
    }
    delay(500);
  }
  TSPLiftStop();
}

void TSPCarLeft(){
  digitalWrite(M1, HIGH);
  snelheid = 100;
}

void TSPCarRight(){
  digitalWrite(M1, LOW);
  snelheid = 100;
}

void TSPCarStart(){
  digitalWrite(E1, snelheid);
}

void TSPCarStop(){
  digitalWrite(E1, 0);
}

void TSPRunCarRight(int hoeveel){
  TSPCarRight();
  TSPCarStart();
  int aantalRight = 0;
  while(aantalRight<hoeveel){
    if(analogRead(inputa < 700)){
      aantalRight = aantalRight + 1;
    }
    delay(500);
  }
  TSPCarStop();
}

void TSPRunCarLeft(int hoeveel){
  TSPCarLeft();
  TSPCarStart();
  int aantalLeft = 0;
  while(aantalLeft<hoeveel){
    if(analogRead(inputa < 700)){
      aantalLeft = aantalLeft + 1;
    }
    delay(500);
  }
  TSPCarStop();
}

void TSPServoOut(){
  for(pos = 0; pos < 180; pos += 1){
    myservo.write(pos);
    delay(20);
  }
}

void TSPServoIn(){
  for(pos = 180; pos >= 1; pos -= 1){
    myservo.write(pos);
    delay(20);
  }
}

void loop(){
  if(Serial.available() > 0){
    String ch = Serial.readStringUntil('\n');
    if(ch == "TSPLiftUp"){
      while(!Serial.available() > 0){
        delay(500);
      }
      String aantal = Serial.readStringUntil('\n');
      int hoeveel = stringtoInt(aantal);
      TSPRunLiftUp(hoeveel);
    }else if(ch == "TSPLiftDown"){
      while(!Serial.available() > 0){
        delay(500);
      }
      String aantal = Serial.readStringUntil('\n');
      int hoeveel = stringtoInt(aantal);
      TSPRunLiftDown(hoeveel);
    }else if(ch == "TSPCarLeft"){
      while(!Serial.available() > 0){
        delay(500);
      }
      String aantal = Serial.readStringUntil('\n');
      int hoeveel = stringtoInt(aantal);
      TSPRunCarLeft(hoeveel);
    }else if(ch == "TSPCarRight"){
      while(!Serial.available() > 0){
        delay(500);
      }
      String aantal = Serial.readStringUntil('\n');
      int hoeveel = stringtoInt(aantal);
      TSPRunCarRight(hoeveel);
    }else if(ch == "ServoIn"){
      TSPServoIn();
    }else if(ch == "ServoOut"){
      TSPServoOut();
    }else if(ch == "BBPBandLeft"){
      // code om de band naar links te laten gaan
    }else if(ch == "BBPBandRight"){
      // code om de band naar rechts te laten gaan
    }else if(ch == "BBPTrainUp"){
      // code om de trein omhoog te laten gaan
    }else if(ch == "BBPTrainDown"){
      // code om de trein omlaag te laten gaan
    }
  }
}
