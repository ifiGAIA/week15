int outputValue = 0; // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  }


void loop() {
  // read the analog in value:
  int sensorRead = analogRead(A0);
  // map it to the range of the analog out:
  
  if(sensorRead < 150) sensorRead = 150;
   if(sensorRead > 510) sensorRead = 510;
   outputValue = map(sensorRead,150, 510, 0, 255);
  // change the analog out value:
  analogWrite(9, outputValue);

  // print the results to the serial monitor:
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(200);
}

