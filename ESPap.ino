#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "***** ***";
const char *password = "wiadomoktowiadomokogowiadomoco";

ESP8266WebServer server(80);

void handleRoot() {
   server.send(200, "text/html", "<h1>Connected</h1>");
}

void setup() {
   delay(1000);
   Serial.begin(9600);
   Serial.println();
   Serial.print("Configuring access point...");
   
   WiFi.softAP(ssid, password);

   IPAddress myIP = WiFi.softAPIP();
   Serial.print("AP IP address: ");
   Serial.println(myIP);
   
   server.on("/", handleRoot);
   server.begin();
   Serial.println("HTTP server started");
}

void loop() {
   server.handleClient();
}