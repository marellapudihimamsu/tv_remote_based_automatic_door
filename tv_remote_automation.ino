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
    pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
    pinMode(4, INPUT);
      pinMode(5, OUTPUT);
        pinMode(7, INPUT);
          pinMode(9, OUTPUT);
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
                
          Serial.println("qwertyuiop");
          analogWrite(A0,150);
             delay(1000);
             
           digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
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
            digitalWrite(3, HIGH);    // turn the LED off by making the voltage LOW
                  delay(1000);                       // wait for a second
             digitalWrite(3, LOW);
             analogWrite(A0,0);
                digitalWrite(5, LOW);
             //delay(5000);
            himam=0;
            continue;
            }
          
          }
  }
  }
}

