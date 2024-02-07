#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* WIFI_SSID = "MB210-G";
const char* WIFI_PASSWORD = "studentMAMK";
const char* MQTT_BROKER = "172.20.49.6";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "test";

const int DHT_PIN = 26;  // Replace with your DHT11 data pin

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHT_PIN, DHT11);

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(2000);
  setupWiFi();
  client.setServer(MQTT_BROKER, MQTT_PORT);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!isnan(temperature) && !isnan(humidity)) {
    publishData(temperature, humidity);
  }

  delay(5000);  // Adjust as needed
}

void setupWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void publishData(float temperature, float humidity) {
  String payload = "{\"temperature\":" + String(temperature) + ",\"humidity\":" + String(humidity) + "}";
  client.publish(MQTT_TOPIC, payload.c_str());
}






// NEW CODE

#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>


const char* WIFI_SSID = "MB210-G";
const char* WIFI_PASSWORD = "studentMAMK";
const char* MQTT_BROKER = "172.20.49.6";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "test";
const int MEASUREMENTS = 10;

const int DHT_PIN = 26;  // Replace with your DHT11 data pin

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHT_PIN, DHT11);

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(2000);
  setupWiFi();
  client.setServer(MQTT_BROKER, MQTT_PORT);
}


void loop() {
      float temperature = 0;
   float humidity = 0;
  if (!client.connected()) {
    reconnect();

  }

for (int i = 0; i < MEASUREMENTS; i++) {
  temperature +=dht.readTemperature();
  humidity += dht.readHumidity();
   delay(1000);
}
  client.loop();
 
  temperature /= MEASUREMENTS;
  humidity /= MEASUREMENTS;

  if (!isnan(temperature) && !isnan(humidity)) {
    publishData(temperature, humidity);
  }

  delay(5000);  // Adjust as needed
}

void setupWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void publishData(float temperature, float humidity) {
  String payload = "{\"temperature\":" + String(temperature) + ",\"humidity\":" + String(humidity) + "}";
  client.publish(MQTT_TOPIC, payload.c_str());
}



// new new code

#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* WIFI_SSID = "MB210-G";
const char* WIFI_PASSWORD = "studentMAMK";
const char* MQTT_BROKER = "172.20.49.6";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "test";
const int MEASUREMENTS = 10;

const int DHT_PIN = 26;  // Replace with your DHT11 data pin

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHT_PIN, DHT11);

float temperatureValues[MEASUREMENTS];
float humidityValues[MEASUREMENTS];
int measurementIndex = 0;

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(2000);
  setupWiFi();
  client.setServer(MQTT_BROKER, MQTT_PORT);
}

void loop() {
  float temperature = 0;
  float humidity = 0;

  if (!client.connected()) {
    reconnect();
  }

  for (int i = 0; i < MEASUREMENTS; i++) {
    temperatureValues[measurementIndex] = dht.readTemperature(); // 9
    humidityValues[measurementIndex] = dht.readHumidity();

    temperature += temperatureValues[measurementIndex];
    humidity += humidityValues[measurementIndex];

    if (i == 9) {measurementIndex = (measurementIndex + 2) % MEASUREMENTS;}
      
    else
      {measurementIndex = (measurementIndex + 1) % MEASUREMENTS;}

    delay(1000);
  }

  client.loop();

  temperature /= MEASUREMENTS;
  humidity /= MEASUREMENTS;

  if (!isnan(temperature) && !isnan(humidity)) {
    publishData(temperature, humidity);
  }

  delay(5000);  // Adjust as needed
}

void setupWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void publishData(float temperature, float humidity) {
  String payload = "{\"temperature\":" + String(temperature) + ",\"humidity\":" + String(humidity) + "}";
  client.publish(MQTT_TOPIC, payload.c_str());
}


// 07/02/24 new new new new

#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* WIFI_SSID = "MB210-G";
const char* WIFI_PASSWORD = "studentMAMK";
const char* MQTT_BROKER = "172.20.49.6";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "test";
const int MEASUREMENTS = 10;

const int DHT_PIN = 26;  // Replace with your DHT11 data pin

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHT_PIN, DHT11);

float temperatureValues[MEASUREMENTS];
float humidityValues[MEASUREMENTS];
int measurementIndex = 0;

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(2000);
  setupWiFi();
  client.setServer(MQTT_BROKER, MQTT_PORT);
}

void loop() {
  float temperature = 0;
  float humidity = 0;

  if (!client.connected()) {
    reconnect();
  }

  for (int i = 0; i < MEASUREMENTS; i++) {
    temperatureValues[measurementIndex] = dht.readTemperature(); // 9
    Serial.print(temperatureValues[measurementIndex]);
    Serial.println(".");
    humidityValues[measurementIndex] = dht.readHumidity();
    Serial.print(humidityValues[measurementIndex]);
    Serial.println(".");
    temperature += temperatureValues[measurementIndex];
    humidity += humidityValues[measurementIndex];

    if (i == 9) {measurementIndex = (measurementIndex + 2) % MEASUREMENTS;}
      
    else
      {measurementIndex = (measurementIndex + 1) % MEASUREMENTS;}

    delay(2000);
  }
  Serial.println("..............");

  client.loop();

  temperature /= MEASUREMENTS;
  humidity /= MEASUREMENTS;

  if (!isnan(temperature) && !isnan(humidity)) {
    publishData(temperature, humidity);
  }

  delay(5000);  // Adjust as needed
}

void setupWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void publishData(float temperature, float humidity) {
  String payload = "{\"temperature\":" + String(temperature) + ",\"humidity\":" + String(humidity) + "}";
  client.publish(MQTT_TOPIC, payload.c_str());
}
