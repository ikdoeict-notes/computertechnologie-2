void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  byte b = 0x41;
  Serial.println("println");
  Serial.println(b);
  Serial.println("write: ");
  Serial.write(b); 
}

void loop() {
  // put your main code here, to run repeatedly:
 
  
}
