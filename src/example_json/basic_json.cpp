//For example recommended tool: https://arduinojson.org/v6/assistant/
//This example uses ArduinoJson 6.21.4
//@Author: Alain Ramos
#include <Arduino.h>
#include <ArduinoJson.h>
void setup()
{
    // ==========>>>>>>>> Serialize JSON
    StaticJsonDocument<96> doc;
    doc["id"] = 1123;
    doc["data"] = "Example Data";
    String jsonString;
    serializeJson(doc, jsonString);
    Serial.println(jsonString);

    // ==========>>>>>>>>Deserialize JSON
    StaticJsonDocument<96> doc2;
    String requestBody = "{\"id\": 1123, \"data\": \"Example Data\"}";
    DeserializationError error = deserializeJson(doc2, requestBody);
    if (error)
    {
        Serial.println("Error al deserializer el JSON");
        return;
    }
}

void loop()
{
}
