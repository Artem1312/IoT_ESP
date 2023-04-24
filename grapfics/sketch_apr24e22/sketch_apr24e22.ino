void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  Serial.flush();
  Serial.println("sin1,sin2");
}

int shift = 0;
void loop() {
  float angle = 0;
  if (Serial.available() > 0) shift = Serial.parseInt();   
  for (angle = 0; angle <= 90; angle = angle + 0.1)
  {
    float sin1Signal = sin(angle);
    float sin2Signal = 2 * sin(angle + shift);
    Serial.print(sin1Signal);
    Serial.print(',');
    Serial.print(sin2Signal);
    Serial.println();
    delay(1);
  }
}