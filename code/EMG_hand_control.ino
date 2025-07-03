#include <Servo.h>
Servo servo1;


const int servoPin1 = 8;
const int analogPin = A7;
const float threshold_to_move = 2.3;
float analogValue = 0.0;
int sum = 0;
const int inactivity_time = 3000; // 5 seconds of inactivity open hand once again back to normal state
int recent_signal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin1, OUTPUT);
  
  servo1.attach(servoPin1);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(analogPin);
  //Serial.println(analogValue); // this works fine without delay (GOOD)
  float voltage = analogValue * (5.0 / 1023.0);
  float newvoltage = 2 + voltage; 
  static unsigned long start_time = 0;
  Serial.println(newvoltage);  // this works make threshold value 3.0! (GOOD)
  
  if (newvoltage>threshold_to_move) { // this if closes the hand - this section works now threshold is perfect maybe 0.1 higher at 3.4 - (GOOD)
    //Serial.println(newvoltage);
    if (millis() - recent_signal > 500) {
      sum++;
      recent_signal = millis();
      //Serial.print("Signal detected! Count:" );
     //Serial.println(sum);
      
    } 
  }


  if (millis() - recent_signal > inactivity_time) { //this accounts for inactivity time after 5 seconds of inactivity sum goes to 0 or "resets" then the hand will open
    sum = 0;
    //Serial.print("Signal not detected! Count: " );
    //Serial.println(sum);
    delay(5000);
  }


  if (sum == 1) {
      servo1.write(180);
    
      //Serial.print("Hand closed! Signal count is at: ");
      //Serial.println(sum);
      delay(1000);
    }  
    else if (sum == 2) {
      servo1.write(0);
      
      //Serial.print("Hand open! Signal count is at: ");
      //Serial.println(sum);
      delay(1000);
      sum = 0;
      
    } 
    else if (sum == 0) {
      //Serial.println("Hand open! Inactivtity time exceeded threshold, signal count is now at: ");
      //Serial.println(sum);
      delay(5000);
    }
} 
