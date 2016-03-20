const byte ledArray[] = {2,3,4,5};
const byte buttonArray[] = {9,10,11};
bool actief = false;
unsigned long time;
int teller = 0;

void setup() {
  // put your setup code here, to run once:  
  for (int x=0; x<4; x++){
    pinMode(ledArray[x],OUTPUT);
  }
  for (int x=0; x<3; x++){
    pinMode(buttonArray[x],INPUT_PULLUP);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(actief){
    if((millis()-time) > 1000){
          actief = false;
    }
     if(!digitalRead(buttonArray[2])== HIGH){
      digitalWrite(ledArray[0], LOW);
      delay(10);
      while(!digitalRead(buttonArray[2])){}
      delay(10);
    }
    if(!digitalRead(buttonArray[1])== HIGH){
      digitalWrite(ledArray[0], HIGH);
      delay(10);
        while(!digitalRead(buttonArray[1])){}
      delay(10);
    }
  }
  else{
    if(!digitalRead(buttonArray[0])== HIGH){
      actief = true;
      time = millis();
      delay(10);
      while(!digitalRead(buttonArray[0])){}
      delay(10);
    }
  }
}
    

   

  
    

