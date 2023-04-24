void setup() {
  Serial.begin(9600);
}

void loop() {
  //Triangular wave
  for (float i = 0; i <= 100; i = i + 5)
  {
    Serial.println(i);
    delay(1);
  }
  for (float i = 100; i >= 0; i = i - 5)
  {
    Serial.println(i);
    delay(1);
  }
}