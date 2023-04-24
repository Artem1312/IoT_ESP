void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  Serial.flush();
  Serial.println("sin1,sin2");
}

float shift = 0;
float amp1 = 1;

void loop() {
  float angle = 0;

  if (Serial.available() > 1) {
    char key = Serial.read();
    int val = Serial.parseFloat();
    switch (key) {
      case 'a': amp1 = val; break;
      case 's': shift = val; break;
    }    
  }   
    
  for (angle = 0; angle <= 90; angle = angle + 0.1)
  {
    float sin1Signal = sin(angle);
    float sin2Signal = amp1 * sin(angle + shift);
    Serial.print(sin1Signal);
    Serial.print(',');
    Serial.print(sin2Signal);
    Serial.println();
    delay(1);
  }
}