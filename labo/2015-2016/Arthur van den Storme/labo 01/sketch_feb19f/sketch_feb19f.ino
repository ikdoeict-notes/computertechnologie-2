const byte ledArray[] = {2,3,4,5};
int richting = 1;
int teller = 0;

void setup() {
  // put your setup code here, to run once:
 for (int x=0; x<4; x++){
    pinMode(ledArray[x],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:  
    digitalWrite(ledArray[teller], HIGH);
    delay(500);
    digitalWrite(ledArray[teller],  LOW);
    delay(50);
    teller += richting;
    if(teller == 3 || teller == 0) richting*=-1;     
}
