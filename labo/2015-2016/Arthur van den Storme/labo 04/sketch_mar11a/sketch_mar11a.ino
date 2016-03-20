const byte ledArray[] = {2,3,4,5};
const byte buttonArray[] = {9,10,11};
int toggled = HIGH;
int teller = 0;
int knop = 0;
int tijd = 0;

void setup() {
  // put your setup code here, to run once:
  tijd = millis();
  
  for (int x=0; x<4; x++){
    pinMode(ledArray[x],OUTPUT);
  }

  for (int x=0; x<3; x++){
    pinMode(buttonArray[x],INPUT_PULLUP);
  }
  digitalWrite(ledArray[0],HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(!digitalRead(buttonArray[0])== HIGH){
      naarRechts();
      delay(10);
      while(!digitalRead(buttonArray[0])){
           if((millis()-tijd) >= 2000){
            naarRechts();
            delay(200);
           }
      }
      delay(10);
    }

    if(!digitalRead(buttonArray[1])== HIGH){
      reset();
      delay(10);
        while(!digitalRead(buttonArray[1])){}
      delay(10);
    }

    if(!digitalRead(buttonArray[2])== HIGH){
      naarLinks();
      delay(10);
      while(!digitalRead(buttonArray[2])){
          
      }
      delay(10);
    }

  
    
}

void naarLinks(){
  teller++;
  if(teller == 4){
    digitalWrite(ledArray[0], HIGH);
    digitalWrite(ledArray[3], LOW);
    teller =0;
  }
  else{
    digitalWrite(ledArray[teller], HIGH);
    digitalWrite(ledArray[teller-1], LOW);
  }
}

void naarRechts(){
  teller--;
  if(teller == -1){
    digitalWrite(ledArray[3], HIGH);
    digitalWrite(ledArray[0], LOW);
    teller =3;
  }
  else{
    digitalWrite(ledArray[teller], HIGH);
    digitalWrite(ledArray[teller+1], LOW);
  }
}

void reset(){
  digitalWrite(ledArray[0], HIGH);
  digitalWrite(ledArray[1], LOW);
  digitalWrite(ledArray[2], LOW);
  digitalWrite(ledArray[3], LOW);
  teller = 0;
}

