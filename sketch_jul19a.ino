#include <Servo.h> 
Servo BrilleL;
Servo BrilleR;

bool brillenOben = false;
 
void setup() 
{ 
  Serial.begin(9600);

  // Servo on digital Port D4 
  BrilleL.attach(D0);
  BrilleR.attach(D5);

  // AmbientLight Pin
  pinMode(A0, INPUT);
} 
 
void loop() 
{ 
  // Int value between 0 - 1024
  int ambientLight = analogRead(A0);

  if (ambientLight < 250 && brillenOben == true) {
    BrilleL.write(180);
    BrilleR.write(1);
    brillenOben = false;
    Serial.println("Brille runter");
  }
  if (ambientLight > 700 && brillenOben == false){
    BrilleL.write(1);
    BrilleR.write(180);
    brillenOben = true;
    Serial.println("Brille hoch");
  }

  Serial.println(ambientLight);
  Serial.println(brillenOben);
  delay(1000);
}