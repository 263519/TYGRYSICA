<<<<<<< HEAD
#include <WiFi.h>
 

const char* ssid 
const char* password
const uint16_t port 
const char * host 
 HardwareSerial SerialPort(1);
void setup()
{
 SerialPort.begin(115200, SERIAL_8N1, 20, 21); // Zmieniono parametr SERIAL 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
 
}
 
void loop()
{
    WiFiClient client;
 
    if (!client.connect(host, port)) {
 
        Serial.println("Connection to host failed");
 
        delay(1000);
        return;
    }
 
    Serial.println("Connected to server successful!");
 
    client.print("Hello from ESP32!");
     if (SerialPort.available()) {
            String buffer = SerialPort.readString();
            client.print(buffer);
    }
    Serial.println("Disconnecting...");
    client.stop();
 
    delay(10000);
}
=======
#include <WiFi.h>
 

const char* ssid 
const char* password
const uint16_t port 
const char * host 
 HardwareSerial SerialPort(1);
void setup()
{
 SerialPort.begin(115200, SERIAL_8N1, 20, 21); // Zmieniono parametr SERIAL 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
 
}
 
void loop()
{
    WiFiClient client;
 
    if (!client.connect(host, port)) {
 
        Serial.println("Connection to host failed");
 
        delay(1000);
        return;
    }
 
    Serial.println("Connected to server successful!");
 
    client.print("Hello from ESP32!");
     if (SerialPort.available()) {
            String buffer = SerialPort.readString();
            client.print(buffer);
    }
    Serial.println("Disconnecting...");
    client.stop();
 
    delay(10000);
}
>>>>>>> 3b54aeb (pid first try)
