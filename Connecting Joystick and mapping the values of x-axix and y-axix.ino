/*
*Osman'scode
*This code is basically to map the values of the joystick
*Last edit : 21.07.18, 19:15 
*/
const int SW_pin = 2; // digital pin connected to switch output
int X_pin = 0; // analog pin connected to X output
int Y_pin = 1; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT); // Joystick is attached to pi no. 2
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
}


void loop() {
  int x = analogRead(X_pin) ;
  int y = analogRead(Y_pin) ; 
  x = map (x, 0, 1023, -10, 10); // mapping the x-axix values
  y = map (y, 0, 1023, -10, 10); //mapping the y-axix values 
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(x);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(y);
  Serial.print("\n\n");
  delay(500);
}
