const int digital = 2; // Цифровой вход пин 2
const int analog = A0; // Аналоговый вход пин A0
 
 
void setup()
{
  pinMode(digital, INPUT);
  Serial.begin(9600);
}
 
int degr = 0;

void loop()
{
  /*
  Serial.print("Digital: ");
  Serial.println(digitalRead(digital)); // Цифровой сигнал с датчика
  Serial.print(", Analog: ");
  Serial.println(analogRead(analog)); // Аналоговый сигнал с датчика
  delay(50);
  */
  Serial.print(analogRead(analog));
  Serial.print(',');
  Serial.print(digitalRead(digital));
  Serial.print(',');
  //Serial.print(sin(radians(degr)));
  //Serial.print(',');
  //Serial.println(2*sin(radians(degr+90)));
  //Serial.print(',');
  Serial.println(3*sin(radians(degr+180)));
  degr++;
}