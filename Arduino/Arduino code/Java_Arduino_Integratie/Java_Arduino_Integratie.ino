void setup() {
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void naarLinks(){
  Serial.println("Ik ga nu naar links");
}

void naarRechts(){
  Serial.println("Ik ga nu naar rechts");
}

void ledAan(){
  digitalWrite(7, HIGH);
}

void ledUit(){
  digitalWrite(7, LOW);
}

void loop(){
  if (Serial.available() > 0){
    String recv = Serial.readStringUntil('\n');

    if (recv == "naarLinks"){
      naarLinks();
    }
    if (recv == "naarRechts"){
      naarRechts();
    }
    if (recv == "ledAan"){
      ledAan();
    }
    if (recv == "ledUit"){
      ledUit();
    }
  }
}
