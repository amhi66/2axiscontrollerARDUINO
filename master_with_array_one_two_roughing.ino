#include <Wire.h>

float digit[25]={0,300,0,600,0,900,0,1200,0,1500,0,1800,0,2100,0,2400,0};
     
float digit2[25]={0,40000,0,40000,0,40000,0,40000,0,40000,0,40000,0,40000,0,40000,0};
    
// change X and Y

//float digit[25]={0,-100,0,-56,0,-45,0,-37,0,-31,0,-26,0,-22,0,-18,0,-14,0,-11,0,-8,0,-5,0};
//float digit2[25]={0,-1,0,-3,0,-5,0,-7,0,-9,0,-11,0,-13,0,-15,0,-17,0,-19,0,-21,0,-23,0};



int aaa[4];
int aaa2[4];
float x;
float y;
unsigned long j;
int k;

void setup() {
  
  Wire.begin();
  Wire.setClock(400000L);

  Serial.begin(2000000);

  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  //pinMode(A5,INPUT);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  //digitalWrite(A5,0);
  pinMode(8,INPUT_PULLUP); // as an output.connect to gnd

  
  Serial.println("begin for 5 seconds later");
  delay(5000);

  y=5000;

  for(int i=0;i<25;i=i+1){
    
 
  x=digit[i+1]-digit[i];
  x=x*1;
  //Serial.println("x is =");
  //Serial.println(x);
  //Serial.println("i=");
  //Serial.println(i);
        
        
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
        
        
  //if(y>0){
            
       //digitalWrite(6,HIGH);
       //digitalWrite(5,LOW);    
        //}      
        
        
  //if(y<0){
            
       //digitalWrite(6,HIGH);
       //digitalWrite(5,LOW);    
        //}  
 



  union{  
    float myFloat;
    byte myFloatInBytes[4];
    
  }myUnion;  
  myUnion.myFloat=x;


  aaa[0]=myUnion.myFloatInBytes[0];
  Wire.beginTransmission(8);
  Wire.write("aaa is");
  Wire.write(aaa[0]);
  Wire.endTransmission();
  //Serial.println(aaa[0]);
  aaa[1]=myUnion.myFloatInBytes[1];
  Wire.beginTransmission(8);
  Wire.write("aaa is");
  Wire.write(aaa[1]);
  Wire.endTransmission();
  //Serial.println(aaa[1]);
  aaa[2]=myUnion.myFloatInBytes[2];
  Wire.beginTransmission(8);
  Wire.write("aaa is");
  Wire.write(aaa[2]);
  Wire.endTransmission();
  //Serial.println(aaa[2]);
  aaa[3]=myUnion.myFloatInBytes[3];
  Wire.beginTransmission(8);
  Wire.write("aaa is");
  Wire.write(aaa[3]);
  Wire.endTransmission();
  //Serial.println(aaa[3]);

  //Serial.println("delay is =");
  //Serial.println(abs(y));
        
        
  //delay(abs(y));
        
        
  
  //j=0;      
        
 // for (j=0;j<=abs(y);j=j+10) {
        
        //label1:
     //while(j<=abs(y)){
            //j=j+1000;
            
           // delay(10);
            
            endstopp();
           
               
       // }
                
        
        
          
      //  }
  
  //label:
  //digitalWrite(13,HIGH);
  //digitalWrite(A0,0);


  //digitalWrite(6,LOW);
  //digitalWrite(5,LOW);
  //delay(2000);


  y=digit2[i+1]-digit2[i];
  y=y*1;
  //Serial.println("y is =");
  //Serial.println(y);
  //Serial.println("i=");
  //Serial.println(i);

  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);


  union{  
    float myFloat2;
    byte myFloatInBytes2[4];
    
  }myUnion2;  
  myUnion2.myFloat2=y;


  aaa2[0]=myUnion2.myFloatInBytes2[0];
  Wire.beginTransmission(9);
  Wire.write("aaa2 is");
  Wire.write(aaa2[0]);
  Wire.endTransmission();
  //Serial.println(aaa2[0]);
  aaa2[1]=myUnion2.myFloatInBytes2[1];
  Wire.beginTransmission(9);
  Wire.write("aaa2 is");
  Wire.write(aaa2[1]);
  Wire.endTransmission();
  //Serial.println(aaa2[1]);
  aaa2[2]=myUnion2.myFloatInBytes2[2];
  Wire.beginTransmission(9);
  Wire.write("aaa2 is");
  Wire.write(aaa2[2]);
  Wire.endTransmission();
  //Serial.println(aaa2[2]);
  aaa2[3]=myUnion2.myFloatInBytes2[3];
  Wire.beginTransmission(9);
  Wire.write("aaa2 is");
  Wire.write(aaa2[3]);
  Wire.endTransmission();
  //Serial.println(aaa2[3]);

  //Serial.println("delay is =");
  //Serial.println(abs(x));
  delay(abs(x));

  //digitalWrite(6,LOW);
  //digitalWrite(5,LOW);
  //delay(2000);



  }

  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  //Serial.println("delay is =");
  //Serial.println(abs(y));
  delay(abs(y));
  

  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);


}

void endstopp(){
    
    j=0;
    
    //label1:
   
    while(j<=abs(y))   {
        
       delay(10);
       j=j+10; 
        
        
       k=digitalRead(8);
        
       if(k==1){
            digitalWrite(12,HIGH);
            //goto label1;
        }
        
       else{
            digitalWrite(12,LOW);
            goto label;
        }
     
    }
    
         
 
 label:
    
 return;       
   
        
          
}
void loop() {

  
}

