void setup() {
  Serial.begin(9600);
}

void loop() {
  float angle = 0;

  for (angle = 0; angle <= 90; angle = angle + 0.1)
  {
    float sinSignal = sin(angle);
    Serial.print(sinSignal);
    Serial.println();
    delay(1);
  }
}
