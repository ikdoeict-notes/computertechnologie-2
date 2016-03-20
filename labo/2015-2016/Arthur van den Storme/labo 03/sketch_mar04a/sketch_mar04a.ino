word temperatuur[]={0x3B47 ,0x0C87 ,0x000F ,0x0007 ,0xF387};
byte hoog , laag ;
float temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0; i < 5; i++){
    hoog = temperatuur[i] / 256;
    laag = temperatuur[i] % 256;
    temp = (hoog<<1)+(laag>>7);
    if((laag & 0x40)== 0x40) temp+=0.5;
    Serial.println(temp, DEC);
  }
}

void loop() {
  
}
