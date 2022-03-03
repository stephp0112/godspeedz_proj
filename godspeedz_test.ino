int ledPin = 8;        //LED light pin
int sensor = 2;         //sensor pin
int state = LOW;       //no motion is detected
int val = 0;           //variable that stores the sensor status


void setup() {
  pinMode(ledPin, OUTPUT);       //assigning the LED as an output
  pinMode(sensor, INPUT);    //assigning the PIR as the input
  Serial.begin(9600);       
}

void loop() {
  val = digitalRead(sensor);    
  if (val == HIGH) {          //if sensor is high,
    digitalWrite(ledPin, HIGH); //the LED will turn on
    delay(500);            

    if (state == LOW) {
      Serial.println("Groceries have been detected!");
      state = HIGH;         //updating the variable state to HIGH
    }
  }
  else {
    digitalWrite(ledPin, LOW);   //LED turns off
    delay(500);

    if (state == HIGH) {
      Serial.println("Groceries have been moved");  //updating variable state to LOW
      state = LOW;
    }
  }
}
