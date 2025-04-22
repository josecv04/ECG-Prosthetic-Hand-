int analogPin = A7;
float val = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
  //Serial.println(val);
  delay(1);
  float voltage = val * (5.0 / 1023.0);
  //Serial.println(voltage);
  float newvoltage = 2 + voltage; 
  Serial.println(newvoltage);
  delay(1);
}
