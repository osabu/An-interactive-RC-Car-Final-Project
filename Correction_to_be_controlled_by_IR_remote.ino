/*Osman's code
*That's the code for the conrolling rc car with the IR transmiter and reciver 
*You should change the hex numbers in the cases, because every remote has it's own decoding hex codes
*Last editing :  20/07/18 , 12:58 
*/
#include <IRremote.h> // library for controlling with the IR remote
#include "pins_arduino.h" // 
#define RECV_PIN 3
IRrecv irrecv(RECV_PIN);
//Pin should be PWM
#define in3 4 // DC Motor no. 1 
#define in4 5 // DC Motor no. 1
#define in1 6 // DC Motor no. 2
#define in2 7 // DC Motor no. 2
#define Buzzer 8 //The buzzer is attached to pin no.8
#define trigPin 9  
#define echoPin 10
#define redPin 11
#define Motorpin 12
#define Motorpin2 13
boolean LED = true ;  

long duration;
int distance;
boolean OnAndOff = true ; //turning on and off  
decode_results results;
void setup()
{ 
  irrecv.enableIRIn(); // Start the receiver
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);    
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT) ; 
  pinMode(Buzzer , OUTPUT) ; 
  pinMode(Motorpin , OUTPUT) ; 
  pinMode(Motorpin2 , OUTPUT) ; 

  Serial.begin(9600); 
}
void loop() {
  if (irrecv.decode(&results)) {
      switch(results.value)
      {        
        case 0xFF18E7:  //Serial.println("Forward"); // Button 2  
                          digitalWrite(in1, HIGH);
                          digitalWrite(in2, LOW);
                          digitalWrite(in3, HIGH);
                          digitalWrite(in4, LOW);
                         break;       
        case 0xFF10EF:  //Serial.println("Left"); // Button 4
                         digitalWrite(in3, LOW);
                         digitalWrite(in4, HIGH);
                         break; 
        case 0xFF38C7:  //Serial.println("Stop"); // Button 5
                          
                         digitalWrite(in1, LOW);
                         digitalWrite(in2, LOW);
                         digitalWrite(in3, LOW);
                         digitalWrite(in4, LOW);  
                         break; 
        case 0xFF5AA5:  //Serial.println("Left"); // Button 6
                         digitalWrite(in1, LOW);
                         digitalWrite(in2, HIGH);
                         break;         
       case 0xFF4AB5:  //Serial.println("Right"); // Button 8  
                         digitalWrite(in1, LOW);
                         digitalWrite(in2, HIGH);
                         digitalWrite(in3, LOW);
                         digitalWrite(in4, HIGH);
                         break;
        case 0xFF42BD : //Police LED's //Button 7
          
          if(LED == true)
          {
              digitalWrite(redPin  , HIGH) ; 
              LED = false ; 
              }
            else 
              { 
                digitalWrite(redPin , LOW) ; 
                LED = true ;
              }
                
                break ; 
        
           case 0xFF6897 : //Automatic Mode //Button 0

             digitalWrite(in1, HIGH);
             digitalWrite(in2, LOW);
             digitalWrite(in3, HIGH);
             digitalWrite(in4, LOW);
                          
              digitalWrite(trigPin, LOW);
              delayMicroseconds(2);
              // Sets the trigPin on HIGH state for 10 micro seconds
              digitalWrite(trigPin, HIGH);
              delayMicroseconds(10);
              digitalWrite(trigPin, LOW);
              // Reads the echoPin, returns the sound wave travel time in microseconds
              duration = pulseIn(echoPin, HIGH);
              // Calculating the distance
              distance= duration*0.034/2;
              // Prints the distance on the Serial Monitor
              Serial.print("Distance: ");
              Serial.println(distance);
              if (OnAndOff == true)
              {
              if(distance <= 2)
              {
                   digitalWrite(in1, LOW);
                   digitalWrite(in2, HIGH);
                   delay(1000);
                   digitalWrite(in1, HIGH);
                   digitalWrite(in2, LOW);
                   digitalWrite(in3, HIGH);
                   digitalWrite(in4, LOW);            
              }
              else 
                {
                   digitalWrite(in1, HIGH);
                   digitalWrite(in2, LOW);
                   digitalWrite(in3, HIGH);
                   digitalWrite(in4, LOW);
                               
                }
               OnAndOff = false ; 
              }
              
              else
              {
                   digitalWrite(in1, LOW);
                   digitalWrite(in2, LOW);
                   digitalWrite(in3, LOW);
                   digitalWrite(in4, LOW);  
              OnAndOff = true ; 
              }
              break ;
           case 0xFF52AD ://Music //Button 9   
               if (OnAndOff == true )
               {
                PoBuzzer() ;
                OnAndOff = false ; 
               }
               else       
               {
                digitalWrite(Buzzer , LOW) ; 
               OnAndOff = true ;
               }
           case 0xFF7A85 :           
              if(OnAndOff == true)
              {
                digitalWrite(Motorpin , HIGH) ; 
                digitalWrite(Motorpin2 , LOW) ; 
                OnAndOff = false ; 
                break ;
                }  
                else 
                {
                digitalWrite(Motorpin , LOW) ; 
                digitalWrite(Motorpin2 , LOW) ; 
                  OnAndOff = true ; 
                  break ;
                }
                        
      }  
    irrecv.resume(); // Receive the next value
  }
}

void PoBuzzer()
{
  
  digitalWrite(Buzzer , HIGH) ; 
  delay(1000) ; 
  digitalWrite(Buzzer , LOW) ; 
  delay(200) ;  
}
