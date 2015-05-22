#include <Servo.h>

Servo myservo;

int pos = 0;
int E1 = 5;
int M1 = 4;
int E2 = 6;
int M2 = 7;
int snelheid;

void setup() {
  Serial.begin(9600);
  pinMode(M1, OUTPUT);   
  pinMode(M2, OUTPUT);
  myservo.attach(9);
}

void links(){
  digitalWrite(M1, HIGH);
  snelheid = 25;
}

void rechts(){
  digitalWrite(M1, LOW);
  snelheid = 255;
}

void startHorizontaal(){
  digitalWrite(E1, snelheid);
}

void stopHorizontaal(){
  digitalWrite(E1, 0);
}

void omlaag(){
  digitalWrite(M2, HIGH);
  snelheid = 150;
}

void omhoog(){
  digitalWrite(M2, LOW);
  snelheid = 200;
}

void stopVerticaal(){
  analogWrite(E2, 0);
}

void startVerticaal(){
  analogWrite(E2, snelheid);
}

void servoOut(){
  for(pos = 0; pos < 180; pos += 1){
    myservo.write(pos);
    delay(20);
  }
}

void servoIn(){
  for(pos = 200; pos>=1; pos-=1){                                
    myservo.write(pos);
    delay(20);
  }
}

void loop(){
  if (Serial.available() > 0){
    String ch = Serial.readStringUntil('\n');
//    char ch = Serial.read();
    if(ch == 'g'){
      startVerticaal();
    }else if(ch == 's'){
      stopVerticaal();
    }else if(ch == 'd'){
      omlaag();
    }else if(ch == 'u'){
      omhoog();
    }else if(ch == 'i'){
      servoIn();
    }else if(ch == 'o'){
      servoOut();
    }else if(ch == 'l'){
      links();
    }else if(ch == 'r'){
      rechts();
    }else if(ch == 'b'){
      startHorizontaal();
    }else if(ch == 'q'){
      stopHorizontaal();
    }else if(ch == 't'){
      links();
      startHorizontaal();
      delay(1000);
      stopHorizontaal();
      omhoog();
      startVerticaal();
      delay(2000);
      stopVerticaal();
      servoOut();
      servoIn();
      omlaag();
      startVerticaal();
      delay(2000);
      stopVerticaal();
      rechts();
      startHorizontaal();
      delay(1000);
      stopHorizontaal();
    } 
  }
}
