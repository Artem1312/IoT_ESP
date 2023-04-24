/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

//int pin = GRIO2;

void setup() {
  // инициализируем порт GPIO 2 на вывод
  pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(pin, OUTPUT);
}

// главный бесконечный цикл
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // включить светодиод (HIGH - единица)
  delay(1000);               // подождём секунду
  digitalWrite(LED_BUILTIN, LOW);    // выключить светодиод
  delay(1000);               // подождём секунду
}
