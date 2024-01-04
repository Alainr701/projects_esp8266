//For example recommended tool: https://arduinojson.org/v6/assistant/
//This example used Object and Array of Objects
#include <Arduino.h>
#include <ArduinoJson.h>

void setup(){
    Serial.begin(9600);

    //Object
    Person person("John", 30);
    Serial.println(person.toJsonString());
    String jsonObjString = person.toJsonString();
    Serial.println(jsonObjString);
    //Array of objects
    std::vector<Person> persons;
    // persons.push_back(Person("John", 30));
    persons.emplace_back("John", 30);
    persons.emplace_back("Jane", 25);
    persons.emplace_back("Bob", 40);
    DynamicJsonDocument doc = createJsonArray(persons);
    String jsonString;
    serializeJson(doc, jsonString);
    Serial.println(jsonString);
}
void loop(){
    
}
//Class Model
class Person{
    public:
        String name;
        int age;
    Person(String name, int age): name(name), age(age){}
    String toJsonString(){
        StaticJsonDocument<96> doc;
        doc["name"] = name;
        doc["age"] = age;
        String jsonString;
        serializeJson(doc, jsonString);
        return jsonString;
    }
};

DynamicJsonDocument createJsonArray(const std::vector<Person>& objects) {
    DynamicJsonDocument doc(1024); // change 
    JsonArray array = doc.to<JsonArray>();
    for (const auto& object : objects) {
        JsonObject obj = array.createNestedObject();
        obj["name"] = object.name;
        obj["age"] = object.age;
    }
    return doc;
}



