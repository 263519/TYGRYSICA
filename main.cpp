#include <WiFi.h>
#include <HardwareSerial.h>

#define INTERNAL_LED 8

const char* ssid = "aszycha";
const char* password = "koty1515";

WiFiServer server(80);
HardwareSerial SerialPort(1);
String header;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  SerialPort.begin(115200, SERIAL_8N1, 20, 21); // Zmieniono parametr SERIAL 
  Serial.begin(9600);

  delay(1000);
  pinMode(INTERNAL_LED, OUTPUT);
  WiFi.mode(WIFI_STA); // Optional
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to the WiFi network");
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // Print a message out in the serial port
    String currentLine = "";                // Make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // Loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // If there's bytes to read from the client,
        char c = client.read();             // Read a byte, then
        Serial.write(c);                    // Print it out the serial monitor
        header += c;
        if (c == '\n') {                    // If the byte is a newline character
          // If the current line is blank, you got two newline characters in a row.
          // That's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            client.println("<body><h1>ESP32 Web Server</h1>");
            client.println("Roll: ");
            String dataString;
            if (SerialPort.available()) {
              dataString = SerialPort.readString();
              // client.println(buffer);
            }
float data[5];
int index = 0;
int commaIndex = dataString.indexOf(',');
int lastIndex = commaIndex;

// Find the index of the first comma after the initial character
commaIndex = dataString.indexOf(',', commaIndex + 1);
while (index < 5) {
  int nextCommaIndex = dataString.indexOf(',', commaIndex + 1);
  if (nextCommaIndex == -1) {
    nextCommaIndex = dataString.length();
  }
  data[index] = dataString.substring(commaIndex + 1, nextCommaIndex).toFloat();
  commaIndex = nextCommaIndex;
  index++;
}
            // float latitude, longitude;
            // int temperature, humidity;
            // char temperatureUnit;

            // // Find the index of the first comma
            // int firstCommaIndex = data.indexOf(',');

            // // Extract latitude substring
            // String latitudeStr = data.substring(2, firstCommaIndex);
            // // Convert latitude string to float
            // latitude = latitudeStr.toFloat();

            // // Find the index of the second comma
            // int secondCommaIndex = data.indexOf(',', firstCommaIndex + 1);

            // // Extract longitude substring
            // String longitudeStr = data.substring(firstCommaIndex + 2, secondCommaIndex);
            // // Convert longitude string to float
            // longitude = longitudeStr.toFloat();

            // // Find the index of the third comma
            // int thirdCommaIndex = data.indexOf(',', secondCommaIndex + 1);

            // // Extract temperature substring
            // String temperatureStr = data.substring(secondCommaIndex + 2, thirdCommaIndex);
            // // Convert temperature string to integer
            // temperature = temperatureStr.toInt();

            // // Find the index of the fourth comma
            // int fourthCommaIndex = data.indexOf(',', thirdCommaIndex + 1);

            // // Extract humidity substring
            // String humidityStr = data.substring(thirdCommaIndex + 1, fourthCommaIndex);
            // // Convert humidity string to integer
            // humidity = humidityStr.toInt();

            // // Find the index of the fifth comma
            // int fifthCommaIndex = data.lastIndexOf(',');

            // // Extract temperature unit substring
            // String temperatureUnitStr = data.substring(fourthCommaIndex + 1, fifthCommaIndex);

            // temperatureUnit = temperatureUnitStr.toInt();
            // Remove any leading/trailing spaces
            //temperatureUnitStr.trim();
            // Convert temperature unit string to char
           // temperatureUnit = temperatureUnitStr[0];

            // Output the extracted data
            // Serial.print("Latitude: ");
            // Serial.println(latitude);
            // Serial.print("Longitude: ");
            // Serial.println(longitude);
            // Serial.print("Temperature: ");
            // Serial.println(temperature);
            // Serial.print("Humidity: ");
            // Serial.println(humidity);
            // Serial.print("Temperature Unit: ");
            // Serial.println(temperatureUnit);
            client.println("Roll: ");
            // Send the data to the client
            client.println("<input type=\"number\" id=\"latitude\" name=\"roll\" value=\"" + String(data[0]) + "\" readonly><br>");
            client.println("Pitch: ");
            client.println("<input type=\"number\" id=\"longitude\" name=\"pitch\" value=\"" + String(data[1]) + "\" readonly><br>");
            client.println("Sharp distance: ");
            client.println("<input type=\"number\" id=\"temperature\" name=\"sharp\" value=\"" + String(data[2]) + "\" readonly><br>");
            client.println("ToF1: ");
            client.println("<input type=\"number\" id=\"humidity\" name=\"tof1\" value=\"" + String(data[3]) + "\" readonly><br>");
            client.println("ToF2: ");
            client.println("<input type=\"text\" id=\"temperatureUnit\" name=\"tof2\" value=\"" + String(data[4]) + "\" readonly><br>");

            client.println("</body></html>");
            client.println();
            break;
          } else { // If you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // If you got anything else but a carriage return character,
          currentLine += c;      // Add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
