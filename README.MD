# Controlando um Led com ESP8266 através de uma aplicação Web 
Hoje montei uma pequena aplicação que tem como objetivo controlar um **LED** conectado ao **ESP8266** através da **Internet**

### Materiais 

* ESP8266 modelo ESP12-E (Pode ser o ESP-01);
* 1 LED;
* Rede Wireless;
* Broker MQTT hospedado na Nuvem(NodeJS);
* Aplicação Simples para Controle do LED;

### Código
* [Firmware ESP8266](https://github.com/douglaszuqueto/ESP8266_CONTROL_LED_MQTT/blob/master/ESP8266_LED_MQTT.ino) 
* [Broker MQTT](https://github.com/douglaszuqueto/ESP8266_CONTROL_LED_MQTT/blob/master/mqtt-server-ws.js)
* [Aplicação Web](https://github.com/douglaszuqueto/ESP8266_CONTROL_LED_MQTT/blob/master/index.html)

### Fotos
#### Embarcado 
![ScreenShot](https://raw.github.com/douglaszuqueto/ESP8266_CONTROL_LED_MQTT/master/EMBARCADO.jpg)

#### Aplicação Web 
![ScreenShot](https://raw.github.com/douglaszuqueto/ESP8266_CONTROL_LED_MQTT/master/APLICACAO_WEB.png)

### Resultados
Estava curioso para saber como iria funcionar um ESP8266 recebendo dados via MQTT, pois meu TCC somente envia dados. Por isso resolvi fazer uma simples aplicação que através da internet controla um led conectado ao ESP8266.

Os resultados são surpreendentes com a utilização do MQTT, pois eu implementei um Broker em um servidor que tenho na Nuvem, e os testes demonstram um tempo de resposta quase que imperceptível.

Para ficar mais claro, meu ESP8266 está conectado na internet através de uma Rede, o Broker MQTT está em outra rede totalmente diferente e para acessar a aplicação e ligar o LED usei a 3G da Vivo.

A todos que gostam de Internet das Coisas, Automação Residencial, ou conectar qualquer objeto na internet, recomendo estudar essas tecnologias(NodeJS e MQTT)


### Referências 
* [https://github.com/esp8266/Arduino]
* [https://github.com/knolleary/pubsubclient]
* [http://nodejs.org/]
* [https://github.com/mcollina/mosca]
* [http://materializecss.com/]
* [https://jquery.com/]
* [http://git.eclipse.org/c/paho/org.eclipse.paho.mqtt.javascript.git/tree/src/mqttws31.js]

### Contato
Caso queiram mais informações, ajuda ou trocar uma ideia, podem me adicionar no Facebook [https://www.facebook.com/douglasalin] , ou me mandar um e-mail diretamente: douglas.zuqueto@gmail.com

E contribuam para o grupo[https://www.facebook.com/groups/arduino.br] também, postando seus projetos :)

**Um Grande Abraço, Douglas Salin Zuqueto**

