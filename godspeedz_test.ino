int ledPin = 8;        //LED light pin
int motionSensor = 2;         //motionSensor pin
int sensorVal = LOW;       //no motion is detected
//int sensorVal = 0;           //variable that stores the motionSensor status


void setup() {
  pinMode(ledPin, OUTPUT);       //assigning the LED as an output
  pinMode(motionSensor, INPUT);    //assigning the PIR as the input
  Serial.begin(9600);       
}

void loop() {
  sensorVal = digitalRead(motionSensor);    
  if (sensorVal == HIGH) {          //if motionSensor is high,
    digitalWrite(ledPin, HIGH); //the LED will turn on
//    delay(100);            

    if (sensorVal == LOW) {
      Serial.println("Groceries have been detected!");
      sensorVal = HIGH;         //updating the variable state to HIGH
    }
  }
  else {
    digitalWrite(ledPin, LOW);   //LED turns off
//    delay(100);

    if (sensorVal == HIGH) {
      Serial.println("Groceries have been moved");  //updating variable state to LOW
      sensorVal = LOW;
    }
  }
}
