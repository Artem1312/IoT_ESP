int sensor_pin = 4; // D2, цифровой ПИН подключения датчика
int data;

void setup() {
  Serial.begin(115200); //  Устанавливаем скорость соединения с последовательным портом
}

void loop() {
  data = digitalRead(sensor_pin);
  if (data == 1){
    Serial.println("Нажата");
  } else{
    Serial.println("Не нажата");
  }
  delay(1000);
}