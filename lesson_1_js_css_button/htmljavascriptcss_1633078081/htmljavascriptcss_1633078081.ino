#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);    //Webserver Object
const char* ssid = "TP-Link_BC4E";
const char* password =  "16510135";
byte tries = 10;  // Попыткок подключения к точке доступа

const char * htmlMessage = " <!DOCTYPE html> "
                           "<html lang=\"ru\"> "
                           "<head>"
                           "<meta http-equiv=\"Content-type\" content=\"text/html; charset=utf-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">"
                           "<title>HTML ESP8266</title>"
                           "</head>"
                           "<body> "
                           "<p>Это Основная страница только в формате HTML. Пожалуйста, выберите кнопку ниже.</p>"
                           "<a href=\"/javascript\">Javascript Код</a>"
                           "</br>"
                           "<a href=\"/cssButton\">CSS Код</a>"
                           "</body> "
                           "</html> ";

const char * javascriptCode = " <!DOCTYPE html> "
                              "<html lang=\"ru\"> "
                              "<head>"
                              "<meta http-equiv=\"Content-type\" content=\"text/html; charset=utf-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">"
                              "<title>script получить сообщение от ESP8266</title>"
                              "</head>"
                              "<body> "
                              "<p>Нажмите на кнопку, чтобы получить сообщение от ESP8266:</p> "
                              "<button onclick=\"buttonFunction()\">Сообщение</button> "
                              "<script>"
                              "function buttonFunction() { "
                              " alert(\"Привет от ESP8266!\"); "
                              "} "
                              "</script>"
                              "</body> "
                              "</html> ";

const char * cssButton = "<!DOCTYPE html>"
                         "<html lang=\"ru\"> "
                         "<head>"
                         "<meta http-equiv=\"Content-type\" content=\"text/html; charset=utf-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">"
                         "<title>style ESP8266</title>"
                         "<style>"
                         ".button {"
                         "background-color: #990033;"
                         "border: none;"
                         "color: white;"
                         "padding: 7px 15px;"
                         "text-align: center;"
                         "cursor: pointer;"
                         "} "
                         ".button:hover {"
                         "background-color: #c26175;"
                         "}"
                         "</style>"
                         "</head>"
                         "<body>"
                         "<input type=\"button\" class=\"button\" value=\"Нажми меня\">"
                         "</body>"
                         "</html>";

void setup() {
  Serial.begin(9600);                                             //Открыть последовательное соединение
  WiFi.begin(ssid, password);

  while (--tries && WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Non Connecting to WiFi..");
  }
  else
  {
    // Иначе удалось подключиться отправляем сообщение
    // о подключении и выводим адрес IP
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }

  delay(500);
  Serial.println("Waiting to connect…");

  server.on("/", []() {                     //Определите функцию обработки корневого пути (HTML-сообщение)
    server.send(200, "text/html", htmlMessage);
  });

  server.on("/javascript", []() { //Определите функцию обработки для пути javascript
    server.send(200, "text/html", javascriptCode);
  });

  server.on("/cssButton", []() { //Определите функцию обработки для пути CSS
    server.send(200, "text/html", cssButton);
  });

  server.begin(); //Start the server
  Serial.println("Server listening");
}

void loop() {
  server.handleClient(); //Обработка входящих запросов
}
