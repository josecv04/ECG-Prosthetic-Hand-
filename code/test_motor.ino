#include <Servo.h> 
Servo servo1;

int servoPin1 = 8;

void setup() {
  // put your setup code here, to run once:
servo1.attach(servoPin1);
}
void loop() {
  // put your main code here, to run repeatedly:
servo1.write(0);
delay(5000);
servo1.write(180);
delay(5000);
}
