#include <Wire.h>

int input = A0;
int val = 0;
int M1 = 4;
int E1 = 5;
int M2 = 7;
int E2 = 6;
int ledA = 1;
int ledB = 2;
int snelheid = 0;
String trainPos = "up";
char c;
String d;
String e;
const int buzzerPin = 9;
const int songLength = 13;
char notes[] = "cdcd     cdcd"; // a space represents a rest
int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};
int tempo = 5000;

void setup(){
  Serial.begin(9600);
  pinMode(input, INPUT);
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  pinMode(buzzerPin, OUTPUT);
}

void BBPBandLeft(){
  digitalWrite(M1, LOW);
  snelheid = 255;
}

void BBPBandRight(){
  digitalWrite(M1, HIGH);
  snelheid = 255;
}

void BBPBandStart(){
  Serial.println("check");
  digitalWrite(E1, snelheid);
  Serial.println("check2");
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

void BBPTrainStop(){
  digitalWrite(E2, 0);
}

void BBPTrainStart(){
  Serial.println("start");
  if(trainPos == "up"){
    trainPos = "down";
  }else if(trainPos == "down"){
    trainPos = "up";
  }
  digitalWrite(E2, snelheid);
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
  Serial.println("input gevonden");
  String string = "";
  while(Wire.available()){
    c = Wire.read();
//    Serial.print(c);
    string = string+c;
//    c = Wire.readStringUntil(',');
//    d = Wire.readStringUntil('\n');
  }
  Serial.println(string);
  if(string == "00"){
    d = "0";
    e = "0";
  }else if(string == "01"){
    d = "0";
    e = "1";
  }else if(string == "10"){
    d = "1";
    e = "0";
  }else if(string == "11"){
    d = "1";
    e = "1";
  }
  Serial.println(d);
  Serial.println(e);
//  Serial.println(string);
//  Serial.println(d);
  String trainStart;
  if(d == "1"){
    trainStart = "up";
  }else if(d == "0"){
    trainStart = "down";
  }
  
  if(trainStart != trainPos){
    if(trainPos == "down"){
      BBPTrainUp();
    }else if(trainPos == "up"){
      BBPTrainDown();
    }
    BBPTrainStart();
    delay(20000);
    BBPTrainStop();
  }
  
  BBPBandLeft();
  BBPBandStart();
  boolean bandLoop = true;
  while(bandLoop){
    if(analogRead(input) > 150){
      Serial.println("pakket");
      delay(150000);
      bandLoop = false;
    }
  }
  BBPBandStop();
  
  if(e != "0"){
    buzzer();
  }
}
