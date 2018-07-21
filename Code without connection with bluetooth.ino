/*Osman's code
 * The final project, it's a rc car, which controlled with a joystick. With this Joystick you are able to turn the car right and left, and to move the wheels backwards and forwards
 * The car has 2 LED's, one Buzzer, one Fan, and an ultra sonic to control the distance between the car and another objects. 
 *laast edition : 21.07.18 , 18:21
 */
#include "pitches.h"
int melody[] = {
  NOTE_E4, NOTE_C4,
};
int noteDurations[] = {
  2,2,
};
#define redPin  12 // the red LED is attached to pin no. 10
#define bluePin  11 // the blue LED is attached to pin no. 11
#define SW_pin  2 // digital pin connected to switch output , to pin no. 2
#define X_pin  0 // the X-Axix input is attached to pin no.0 
#define Y_pin  1 // the Y-Axix inout is attached to pin no.1
#define in3 4 // DC Motor no. 1 
#define in4 5 // DC Motor no. 1
#define in1 6 // DC Motor no. 2
#define in2 7 // DC Motor no. 2
#define motor 10 // the fan motor is attached to pin no. 10
void setup() {
  //defining the Inputs and the Outputs 
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(motor , OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);

 }
void loop() {
  //Calling this two functions
  controlTheBackAndForwardForTheCar();//For the movement backward and forward
  controlTheTurnOfTheCar();//For the turning left and right 
  }
//
void controlTheBackAndForwardForTheCar()
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

else
   {
       digitalWrite(in1, LOW);
       digitalWrite(in2, HIGH);
       digitalWrite(in3, LOW);
       digitalWrite(in4, HIGH);
   }

}  
//
void controlTheTurnOfTheCar()
{
  int y = analogRead(Y_pin) ; 
  y = map (y, 0, 1023, 0, 180);
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(y);
  Serial.print("\n\n");
  delay(500);
if(y > 90) //Turning the car to the right
  {
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
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
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    
  }
else // Turning the car to the left
  {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(motor, HIGH) ;
    delay(100) ;
  }
}

/*
//To turn the fan on and off, it's as a comment
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
