#include <Wire.h>

int aaa[4];
int bbb;
int ccc;
int ddd;
int eee;

union {  
    float myFloat;
    byte myFloatInBytes[4];
    
  }myUnion; 

//uuu myUnion={myFloatInBytes[0],myFloatInBytes[1],myFloatInBytes[2],myFloatInBytes[3]};


void setup() {
  
  Wire.begin(8);
  Wire.setClock(400000L);
  Serial.begin(2000000);

  
  Wire.onReceive(receiveEvent);

  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);

  pinMode(9,OUTPUT);
  digitalWrite(9,LOW);
  
}

void loop() {
  //delay(8000);

}

int i=0;
void receiveEvent(int howMany){

   
  while (1<Wire.available()){
    char c=Wire.read();
    //Serial.print(c);
    //Serial.println("i =");
    //Serial.println(i);
    i=i+1;
  }

   
  
  //myUnion.myFloat=x;

  //aaa=Wire.read();
  //Serial.println(aaa);
  

   for(int j=0;j<4;j++){
     
    aaa[j]=Wire.read();
    //Serial.println(aaa[j]);
   }
 
  if(i==6){
    bbb=aaa[0];
    myUnion.myFloatInBytes[0]=bbb;
    //Serial.println("bbb is");
    //Serial.println(bbb);
  }
  if(i==12){
    ccc=aaa[0];
    myUnion.myFloatInBytes[1]=ccc;
    //Serial.println("ccc is");
    //Serial.println(ccc);
  }
  if(i==18){
    ddd=aaa[0];
    myUnion.myFloatInBytes[2]=ddd;
    //Serial.println("ddd is");
    //Serial.println(ddd);
  }
  if(i==24){
    eee=aaa[0];
    myUnion.myFloatInBytes[3]=eee;
    //Serial.println("eee is");
    //Serial.println(eee);
  }

  

  if(i>23){

    float myFloat=myUnion.myFloat;
    //Serial.println("my Float or X is=");
    Serial.println(myFloat);
    i=0;
     if(myFloat>0){
    digitalWrite(4,HIGH);
    digitalWrite(9,LOW);
    //delay(myFloat);
  }

  if(myFloat<0){
    digitalWrite(4,LOW);
    digitalWrite(9,HIGH);
    //delay(myFloat);
  }

  if(myFloat==0){
    digitalWrite(4,LOW);
    digitalWrite(9,LOW);
  }

  if(myFloat==-0){
    digitalWrite(4,LOW);
    digitalWrite(9,LOW);
  }
  
 }

 


}


