#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <ArduinoJson.h>
#include <example_login/response.h>

const char *ssid = "WifiEsp8266";
const char *password = "123456789";


ESP8266WebServer server(80);
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void handleRootLogin()
{
  if (server.method() == HTTP_POST)
  {

    String requestBody = server.arg("plain");

    // Analizar el cuerpo de la solicitud como JSON
    StaticJsonDocument<200> jsonDocument;
    DeserializationError error = deserializeJson(jsonDocument, requestBody);

    if (error)
    {
      server.send(400, "application/json", Response::responseError);
      return;
    }

    String username = jsonDocument["username"].as<String>();
    String password = jsonDocument["password"].as<String>();

    if (username == "admin" && password == "123456")
    {
      server.send(200, "application/json", Response::responseValid);
    }
    else
    {
      server.send(401, "application/json", Response::responseInvalid);
    }
  }
  Serial.println("Entra");
}

void setup()
{
  Serial.begin(9600);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.println("Connected to WiFi SSID: " + String(ssid));
  server.on("/login", handleRootLogin);
  server.begin();
  Serial.println("Server started");
}

void loop()
{
  server.handleClient();
}