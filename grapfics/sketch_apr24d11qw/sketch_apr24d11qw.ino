void setup() {
  Serial.begin(9600);
  Serial.flush();
  Serial.println("sin,cos,tan");
}

void loop() {
  float angle = 0;

  for (angle = 0; angle <= 90; angle = angle + 0.1)
  {
    float sinSignal = sin(angle);
    float cosSignal = cos(angle);
    float tanSignal = tan(angle);
    Serial.print(sinSignal);
    Serial.print(',');
    Serial.print(cosSignal);
    Serial.print(',');
    Serial.print(tanSignal);
    Serial.println();
    delay(1);
  }
}
