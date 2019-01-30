/*
  tv_remote_based_automatic_door

  This example shows how to create a automated Door
  

  

  created June 2018
  by M.Himamsu
  modified June 2018
  by M.Himamsu 


*/




#include <IRremote.h>

const int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;
int himam=0;
int pushButton = 4;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
    pinMode(2, OUTPUT);   //Motor 1 
   pinMode(3, OUTPUT);    //Motor 1
    pinMode(4, INPUT);     //Door opening switch
      pinMode(5, OUTPUT);  //Motor 2
        pinMode(7, INPUT);   //Door Checking Switch or heat sink piece
          pinMode(9, OUTPUT); //Motor 2
}

void loop(){
  while(1)
  {
    if(digitalRead(7)==1)
    { digitalWrite(9, HIGH);
    delay(100);
      
      } digitalWrite(9,LOW);
  if (irrecv.decode(&results)){
        Serial.println(results.value, DEC);
        delay(500);
        irrecv.resume();
         if (results.value == 2060)
         {
          if(himam==0)
          {
            int b = digitalRead(pushButton);
          // print out the state of the button:
             Serial.println(b);
              delay(1);
              while(b==0)
              {
                digitalWrite(5, HIGH);
                   b = digitalRead(pushButton);
                Serial.println(b);
                }
                
          //Serial.println("qwertyuiop");
          analogWrite(A0,150);
             delay(1000);
             
           digitalWrite(2, HIGH);  
           delay(1000); 
        digitalWrite(2,LOW);
        analogWrite(A0,0);
        analogWrite(5,0);
        delay(5000);
        himam=1;
        continue;
          }
          if(himam==1)
          { analogWrite(A0,150);
            delay(1000);
            digitalWrite(5, HIGH); 
            digitalWrite(3, HIGH);    
                  delay(1000);                     
             digitalWrite(3, LOW);
             analogWrite(A0,0);
                digitalWrite(5, LOW);
             
            himam=0;
            continue;
            }
          
          }
  }
  }
}

