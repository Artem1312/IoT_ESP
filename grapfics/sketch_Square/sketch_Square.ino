void setup() {
  Serial.begin(9600);
}

void loop() {
  //Sawtooth Wave
  for (float i = 0; i <= 70; i = i + 5)
  {
    Serial.println(i);
    delay(5);
  }
}