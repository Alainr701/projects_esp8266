//Example: Hello World Web Server text/plain
//@Author: Alain Ramos
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Name_Wifi";
const char* password = "123456789";

ESP8266WebServer server(80);
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void handleRoot() {
  IPAddress ip = WiFi.localIP();
  String message = "Hello from " + ip.toString();
  server.send(200, "text/plain", message);
}

void setup() {
  Serial.begin(9600);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.println("Connected to WiFi");
  Serial.println("Name: " + String(ssid));
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();
}