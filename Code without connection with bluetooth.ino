/*
 
 */
#include <Servo.h>
#include "pitches.h"
int melody[] = {
  NOTE_E4, NOTE_C4,
};
int noteDurations[] = {
  2,2,
};
#define redPin  10
#define bluePin  11 
#define SW_pin  2 // digital pin connected to switch output
#define X_pin  0 // analog pin connected to X output
#define Y_pin  1 // analog pin connected to Y output
#define in3 4 // DC Motor no. 1 
#define in4 5 // DC Motor no. 1
#define in1 6 // DC Motor no. 2
#define in2 7 // DC Motor no. 2
#define motor 10
Servo myservo;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(motor , OUTPUT)
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  myservo.attach(9);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);

 }
void loop() {
  ControllingTheDCMotor();
  ControllingTheServoMotor();
  }
//
void ControllingTheDCMotor()
{
  int x = analogRead(X_pin) ; 
  x = map (x, 0, 1023, -10, 10);
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(x);
  Serial.print("\n");
if(x > -1)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
     
}

else if( x == 0 || x == -1 )
{
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);   
}

else()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

}  
//
void ControllingTheServoMotor()
{
  int y = analogRead(Y_pin) ; 
  y = map (y, 0, 1023, 0, 180);
  myservo.write(y) ;
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(y);
  Serial.print("\n\n");
  delay(500);
if(y > 90)
  {
    digitalWrite(redPin, HIGH); // turn the red light on
delay(50); // wait 50 ms

digitalWrite(redPin, LOW); // turn the red light off
delay(50); // wait 50 ms

digitalWrite(redPin, HIGH); // turn the red light on
delay(50); // wait 50 ms

digitalWrite(redPin, LOW); // turn the red light off
delay(50); // wait 50 ms

digitalWrite(redPin, HIGH); // turn the red light on
delay(50); // wait 50 ms

digitalWrite(redPin, LOW); // turn the red light off
delay(50); // wait 50 ms

delay(100);

digitalWrite(bluePin, HIGH); // turn the blue light on
delay(50); // wait 50 ms

digitalWrite(bluePin, LOW); // turn the blue light off
delay(50); // wait 50 ms

digitalWrite(bluePin, HIGH); // turn the blue light on
delay(50); // wait 50 ms

digitalWrite(bluePin, LOW); // turn the blue light off
delay(50); // wait 50 ms

digitalWrite(bluePin, HIGH); // turn the blue light on
delay(50); // wait 50 ms

digitalWrite(bluePin, LOW); // turn the blue light off
delay(50); // wait 50 ms

  for (int thisNote = 0; thisNote < 2; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }

  }
else if( y == 89 || y == 90)
  {
    
  }
else
  {
    digitalWrite(motor, HIGH) ;
    delay(100) ;
  }
}

/*
// 
void PushButtonForPolice()
{}

//
void CircleMovementUsingPushButton() 
{}

//
void TurningTheFanUsingPushButton ()
{}

    /*digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
    delay(1000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
    delay(1000);
*/
