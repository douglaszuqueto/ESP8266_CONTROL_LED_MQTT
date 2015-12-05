#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WIFI
const char* SSID = "fedora"; // Troque seu SSID
const char* PASSWORD = "zkzCpx3e"; // Troque sua senha

// MQTT
const char* BROKER_MQTT = "200.132.17.11"; // IP DO MEU BROKER
int BROKER_PORT = 1883;
WiFiClient espClient;
PubSubClient MQTT(espClient); // Instancia o Cliente MQTT

void setup() {
  initPins();
  initSerial();
  initWiFi();
  initMQTT();
}
void initPins() {
  pinMode(D5, OUTPUT); // Led Ligado ao Pino D5 do ESP826 - ESP12-E
  digitalWrite(D5, 0);
}
void initSerial() {
  Serial.begin(115200);
}
void initWiFi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando-se em: ");
  Serial.println(SSID);

  WiFi.begin(SSID, PASSWORD); // Conecta na Rede Wireless
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectado na Rede ");
  Serial.print(SSID);
  Serial.println(" | IP ");
  Serial.println(WiFi.localIP());
}

// Funcão para se conectar ao Broker MQTT
void initMQTT() {
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
  MQTT.setCallback(mqtt_callback);
}
//Função que recebe as mensagens publicadas
void mqtt_callback(char* topic, byte* payload, unsigned int length) {

  String message;
  for (int i = 0; i < length; i++) {
    char c = (char)payload[i];
    message += c;
  }
  Serial.print("Tópico ");
  Serial.print(topic);
  Serial.print(" | ");
  Serial.println(message);
  if (message == "1") {
    digitalWrite(D5, 1);
  } else {
    digitalWrite(D5, 0);
  }
  message = "";
  Serial.println();
  Serial.flush();
}

void reconnectMQTT() {
  while (!MQTT.connected()) {
    Serial.print("Tentando se conectar ao Broker MQTT: ");
    Serial.println(BROKER_MQTT);
    if (MQTT.connect("ESP8266-ESP12-E")) {
      Serial.println("Conectado");
      MQTT.subscribe("led/1"); // Assina o tópico led/1, obs: esse mesmo tópico será usado para a comunicação com a aplicação web

    } else {
      Serial.println("Falha ao Reconectar");
      Serial.println("Tentando se reconectar em 2 segundos");
      delay(2000);
    }
  }
}
void recconectWiFi() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
}
void loop() {
  if (!MQTT.connected()) {
    reconnectMQTT(); // Caso o ESP se desconecte do Broker, ele tenta reconectar ao Broker
  }
  recconectWiFi(); // Caso o ESP perca conexão com a rede WiFi, ele tenta se reconetar na rede.
  MQTT.loop();
}
