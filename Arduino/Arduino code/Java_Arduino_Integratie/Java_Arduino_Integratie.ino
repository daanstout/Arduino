int E1 = 5;
int M1 = 4;
int E2 = 6;
int M2 = 7;

void setup() {
  Serial.begin(9600);
  pinMode(M1, OUTPUT);   
  pinMode(M2, OUTPUT); 
}


void omlaag(){
  digitalWrite(M2, LOW);
}

void omhoog(){
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
//    String ch = Serial.readStringUntil('\n');
    char ch = Serial.read();
    if(ch == 'g'){
      startDraai();
    }else if(ch == 's'){
      stopDraai();
    }else if(ch == 'd'){
      omlaag();
    }else if(ch == 'u'){
      omhoog();
    }
  }
}
