#include <Wire.h>

int aaa2[4];
int bbb2;
int ccc2;
int ddd2;
int eee2;

union {  
    float myFloat2;
    byte myFloatInBytes2[4];
    
  }myUnion2; 



void setup() {
  
  Wire.begin(9);
  Wire.setClock(400000L);
  Serial.begin(2000000);
  
  Wire.onReceive(receiveEvent2);

  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);

  pinMode(9,OUTPUT);
  digitalWrite(9,LOW);
  
}

void loop() {
  //delay(8000);

}

int i=0;
void receiveEvent2(int howMany2){

   
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
     
    aaa2[j]=Wire.read();
    //Serial.println(aaa2[j]);
   }
 
  if(i==7){
    bbb2=aaa2[0];
    myUnion2.myFloatInBytes2[0]=bbb2;
    //Serial.println("bbb2 is");
    //Serial.println(bbb2);
  }
  if(i==14){
    ccc2=aaa2[0];
    myUnion2.myFloatInBytes2[1]=ccc2;
    //Serial.println("ccc2 is");
    //Serial.println(ccc2);
  }
  if(i==21){
    ddd2=aaa2[0];
    myUnion2.myFloatInBytes2[2]=ddd2;
    //Serial.println("ddd2 is");
    //Serial.println(ddd2);
  }
  if(i==28){
    eee2=aaa2[0];
    myUnion2.myFloatInBytes2[3]=eee2;
    //Serial.println("eee2 is");
    //Serial.println(eee2);
  }

  

  if(i>27){

    float myFloat2=myUnion2.myFloat2;
    //Serial.println("my Float2 or Y is=");
    Serial.println(myFloat2);
    i=0;

    if(myFloat2>0){
    digitalWrite(4,HIGH);
    digitalWrite(9,LOW);
    //delay(myFloat2);
  }

  if(myFloat2<0){
    digitalWrite(4,LOW);
    digitalWrite(9,HIGH);
    //delay(myFloat2);
  }
  if(myFloat2==0){
    digitalWrite(4,LOW);
    digitalWrite(9,LOW);
  }

  if(myFloat2==-0){
    digitalWrite(4,LOW);
    digitalWrite(9,LOW);
  }
 }


}


