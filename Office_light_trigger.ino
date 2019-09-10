*/
By: Je'aime Powell 
Rev 1 - 9/10/19

Office Light Trigger

Activates servo to wave arm to turn back on the motion
controlled light

Pin Connections
D13 - Intel Galileo LED Pin
D9 - Servo
A1 - Photoresistor
*/

#include <Servo.h>
Servo servo1;

int led = 13; // Intel Galileo LED Pin


void setup() {
Serial.begin(9600);
servo1.attach(9); // Servo is connected on D9
delay(200);
// Photoresistor Pin = A1
pinMode(A1,INPUT); 
servo1.detach();
pinMode(led,OUTPUT);

}

void loop() {

digitalWrite(led,HIGH);
delay(1000);
digitalWrite(led,LOW);
delay(1000);
Serial.print("Photoresister reading=");
Serial.println(analogRead(A1));
// If the light turns off wave the arm.
if (analogRead(A1) > 70){
     servo1.attach(9);
      delay(1000);
      servo1.write(0);
      servo1.detach();
     }
delay(3000);
}
