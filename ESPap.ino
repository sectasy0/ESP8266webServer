#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>;

#include <ESP8266WebServer.h>

const char *ssid = "***** ***";
const char *password = "wiadomoktowiadomokogowiadomoco";

ESP8266WebServer server(80);

void runWebServer() {
  server.on("/",[]() {
    server.send(200, "text/html", "connected");
  });
  
  server.begin();
  Serial.println("info(webserver): HTTP server started");
}

void setup() {
   delay(1000);
   Serial.begin(9600);
   Serial.println();
   Serial.println("info(ap): configuring access point...");
   
   WiFi.softAP(ssid, password);
   IPAddress myIP = WiFi.softAPIP();
   Serial.print("info(ap): Access point successfuly runned; AP IP address ");
   Serial.println(myIP);

   runWebServer();
}

void loop() {
   server.handleClient();
}
