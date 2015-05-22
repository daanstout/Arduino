#include <Servo.h>

#define legoSensorPin 14 // digital pin D14 is analog pin A0
#define legoSensor 0 // this time we define the analog channel

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
  snelheid = 100;
}

void omhoog(){
  digitalWrite(M2, LOW);
  snelheid = 100;
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

int ReadLegoSensor(){
  pinMode(legoSensorPin, OUTPUT); //set pin as output
  digitalWrite(legoSensorPin, HIGH); //set output high
  delay(10); // wait a bit
  pinMode(legoSensorPin, INPUT); //set pin as input
  int value=analogRead(legoSensor); //read the input
  return value; //return the raw value
}


void loop(){
  if (Serial.available() > 0){
//    String ch = Serial.readStringUntil('\n');
    char ch = Serial.read();
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
      delay(5000);
      stopHorizontaal();
      omhoog();
      startVerticaal();
      delay(1000);
      stopVerticaal();
      links();
      startHorizontaal();
      delay(2000);
      stopHorizontaal();
    }
  }
  links();
  //startHorizontaal();
  int raw=ReadLegoSensor(); // we read the raw value of the sensor
  //Serial.print("Raw value: ");
  //Serial.println(map(raw, 0, 1024, 0, 100)); // and print it to the monitor
  int count = 0;
  int avg = 0;
  while(count < 5){
    avg = avg + map(raw, 0, 1024, 0, 100);
    count++;
  }
  
  if(count == 4){
     count = 0; 
  }
  
  Serial.println(avg / 5);
  avg = avg / 5;
  if(avg == 13){
    stopHorizontaal();
  }
  avg = 0;
  
}
