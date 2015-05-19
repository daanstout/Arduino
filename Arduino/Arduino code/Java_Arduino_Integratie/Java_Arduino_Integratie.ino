int E1 = 5;
int M1 = 4;
int E2 = 6;
int M2 = 7;

void setup() {
  Serial.begin(9600);
  pinMode(M1, OUTPUT);   
  pinMode(M2, OUTPUT); 
}


void linksOm(){
  digitalWrite(M2, LOW);
}

void rechtsOm(){
  digitalWrite(M2, HIGH);
}

void stopDraai(){
  analogWrite(E2, 0);
}

void startDraai(){
  analogWrite(E2, 255);
}


void loop(){
  if (Serial.available() > 0){
    String ch = Serial.readStringUntil('\n');
     if(ch == "start"){
      startDraai();
    }else if(ch == "stop"){
      stopDraai();
    }else if(ch == "links"){
      linksOm();
    }else if(ch == "rechts"){
      rechtsOm();
    }
  }
}
