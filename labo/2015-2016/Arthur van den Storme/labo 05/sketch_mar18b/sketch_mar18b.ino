const byte ledArray[] = {2,3,4,5};
const byte buttonArray[] = {9,10,11};
bool rechts = true;
unsigned long time;
unsigned long timeK1;
int teller = 0;

void setup() {
  // put your setup code here, to run once:  
  for (int x=0; x<4; x++){
    pinMode(ledArray[x],OUTPUT);
  }
  for (int x=0; x<3; x++){
    pinMode(buttonArray[x],INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    if((millis()-time) > 200){
         if(rechts)naarRechts();
         else naarLinks();
         time=millis();
    }
    if(!digitalRead(buttonArray[0])== HIGH){
      time = millis();
      timeK1 = millis();
      delay(10);
      while(!digitalRead(buttonArray[0])){
        if((millis()-timeK1) > 1000) rechts = false;
        else rechts = true;
        if((millis()-time) > 200){
         if(rechts)naarRechts();
         else naarLinks();
         time=millis();
        }
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
    

   

  
    

