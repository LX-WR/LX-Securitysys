#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);// RX, TX
void setup() {
  Serial.begin(9600);
  mySerial.begin(4800);
  Serial.println("Waiting for main microcontroller...");
 pinMode(13,OUTPUT);
 pinMode(9,INPUT);
 pinMode(8,INPUT);
 pinMode(7,INPUT);
 pinMode(6,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(3,INPUT);
 pinMode(2,INPUT);
 pinMode(A5,INPUT);
 pinMode(A4,OUTPUT);
 pinMode(A3,OUTPUT);
 pinMode(A2,OUTPUT);
 digitalWrite(13,HIGH);
 delay(1000);
 digitalWrite(13,LOW);

  
 
 
}
void loop(){
  while(true){
    
    
  if(mySerial.read() == 'A'){
    Serial.println("Ready.");
    while(true){
      if(mySerial.read() == 'B'){
        digitalWrite(6, HIGH);
      }
      if(mySerial.read() == 'b'){
        digitalWrite(6, LOW);
      }
      if(mySerial.read() == 'C'){
        digitalWrite(5, HIGH);
      }
      if(mySerial.read() == 'c'){
        digitalWrite(5, LOW);
      }
      if(mySerial.read() == 'D'){
        digitalWrite(4, HIGH);
      }
      if(mySerial.read() == 'd'){
        digitalWrite(4, LOW);
      }
      if(digitalRead(9) == HIGH){
        mySerial.write('Z');
      }
       if(digitalRead(8) == HIGH){
        mySerial.write('Y');
      }
       if(digitalRead(7) == HIGH){
        mySerial.write('X');
      }
    }  
}
  }
}
