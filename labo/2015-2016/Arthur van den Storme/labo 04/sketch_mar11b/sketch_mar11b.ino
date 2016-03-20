const byte buttonArray[] = {9,10,11};
String waarden[]={"17.89;9.38E-3;STABLE;","17.94;9.28E-3;STABLE;",
"17.32;9.29E-2;UNSTABLE;"};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
   for (int x=0; x<3; x++){
    pinMode(buttonArray[x],INPUT_PULLUP);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    if(!digitalRead(buttonArray[0])== HIGH){
      for(int i=0; i < 4; i++){
        Serial.println(waarden[i].substring(0,5));
      }    
      delay(10);
      while(!digitalRead(buttonArray[0])){
      }
      delay(10);
    }

    if(!digitalRead(buttonArray[1])== HIGH){
      for(int i=0; i < 4; i++){
        if(waarden[i].substring(14,20) == (String)"STABLE"){
          Serial.println(waarden[i].substring(6,14));
        }
      }    
      delay(10);
        while(!digitalRead(buttonArray[1])){}
      delay(10);
    }

    if(!digitalRead(buttonArray[2])== HIGH){
      float gemiddelde = 0;
      for(int i=0; i < 4; i++){
        if(waarden[i].substring(14,20) == (String)"STABLE"){
          gemiddelde += waarden[i].substring(0,5).toFloat();
        }
      }
      Serial.println(gemiddelde/2);    
      delay(10);
      while(!digitalRead(buttonArray[2])){
      }
      delay(10);
    }
}
