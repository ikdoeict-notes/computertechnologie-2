const byte ledArray[] = {2,3,4,5};
byte teller = 0x00;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int x=0; x<4; x++){
    pinMode(ledArray[x],OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
   byte t = teller;
   for (int x=0; x<4; x++){
    if( t % 2 == 0) digitalWrite(ledArray[x], LOW);
    else digitalWrite(ledArray[x], HIGH);
    t /= 2; 
  }
  teller += 0x1;
  teller %= 0x10;
  delay(1000);
}
