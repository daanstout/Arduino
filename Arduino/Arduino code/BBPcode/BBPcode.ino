#include <Wire.h>

int input = A0;
int val = 0;
int M1 = 5;
int E1 = 4;
int M2 = 6;
int E2 = 7;
int ledA = 1;
int ledB = 2;
int snelheid = 0;
String trainPos = "up";
String c;
String d;
const int buzzerPin = 9;
const int songLength = 13;
char notes[] = "cdcd     cdcd"; // a space represents a rest
int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};
int tempo = 150;

void setup(){
  Serial.begin(9600);
  pinMode(input, INPUT);
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  pinMode(buzzerPin, OUTPUT);
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

int frequency(char note){
  int i;
  const int numNotes = 8;
  
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (i = 0; i < numNotes; i++){
    if (names[i] == note){
      return(frequencies[i]);
    }
  }
  return(0);
}

void buzzer(){
  int i, duration;

  for (i = 0; i < songLength; i++){
    duration = beats[i] * tempo;

    if (notes[i] == ' '){
      delay(duration);
    }else{
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);
    }
    delay(tempo/10);
  }
}

void loop(){
  delay(100);
}

void receiveEvent(int howMany){
  while(Wire.available()){
    c = Wire.readStringUntil(',');
    d = Wire.readStringUntil('\n');
  }
  String trainStart;
  if(c == "1"){
    trainStart = "up";
  }else if(c == "0"){
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
  if(d != "0"){
    buzzer();
  }
}
