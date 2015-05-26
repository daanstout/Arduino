int input = A0;
int val = 0;
int M1 = 5;
int E1 = 4;
int M2 = 6;
int E2 = 7;
int snelheid = 0;
int trainPos = 0;

void setup(){
  Serial.begin(9600);
  pinMode(input, INPUT);
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
  digitalWrite(E2, 5);
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
  if(Serial.available() > 0){
    Serial.println("test");
    char ch = Serial.read();
    if(ch == 'l'){
      Serial.println("test2");
      BBPBandLeft();
    }else if(ch == 'r'){
      BBPBandRight();
    }else if(ch == 'g'){
      Serial.println("test2");
      BBPBandStart();
    }else if(ch == 's'){
      BBPBandStop();
    }else if(ch == 'b'){
      BBPTrainStart();
    }else if(ch == 'q'){
      BBPTrainStop();
    }else if(ch == 'u'){
      BBPTrainUp();
    }else if(ch == 'd'){
      BBPTrainDown();
    }
  }
  if(analogRead(input) > 500){
    Serial.println(analogRead(input));
    delay(1000);
    BBPBandStop();
    if(trainPos == 1){
      BBPTrainUp();
      Serial.println("up");
    }else if(trainPos == 0){
      BBPTrainDown();
      Serial.println("down");
    }
    BBPTrainStart();
    delay(1000);
    BBPBandLeft();
    BBPBandStart();
  }
}
