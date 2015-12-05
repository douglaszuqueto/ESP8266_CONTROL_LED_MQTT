var mosca = require('mosca'); // Importa o modulo Mosca
var settings = {
  port: 1883, // Define a porta de operação do MQTT
  http: { // Servidor de WebSockets
    port: 8080,
    bundle: true,
    static: './'
  }
}
// Pode ser integrado a banco de dados como: Redis e MongoDB
var MQTT_SERVER = new mosca.Server(settings); // Cria um Broker MQTT com base nas configurações
MQTT_SERVER.on('clientConnected',function(cliente){ // Evento: ocorre quando um novo cliente se conecta ao Broker
  console.log('Cliente Conectado',cliente.id); // Exibe uma mensagem com o ID do cliente conectado
});
MQTT_SERVER.on('published',function(packet,client){ //  Evento: ocorre quando uma mensagem é Puplicada
  console.log("Tópico: ", packet.topic, " | ", new Date().toISOString()); // Exibe uma mensagem com o tópico da mensagem recebida
});
MQTT_SERVER.on('ready', setup); // Inicia o Broker
function setup(){
  console.log('Servidor MQTT - WebSockets rodando');
}
