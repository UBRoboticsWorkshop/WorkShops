#include <WiFi.h>
#include <ESPAsyncWebSrv.h>
#include <AsyncTCP.h>

#include <iostream>
#include <sstream>


const char *host = "your-ssid";
const char *password = "your-password";
const char* htmlHomePage PROGMEM = R"HTMLHOMEPAGE(
<!DOCTYPE html>
<html>
<head>
  <title>WebSocket Example</title>
  <script>
    var socket = new WebSocket('ws://' + window.location.hostname + '/ws');

    socket.onopen = function(event) {
      console.log('WebSocket connected');
    };

    socket.onmessage = function(event) {
      console.log('WebSocket received message: ' + event.data);
    };

    socket.onclose = function(event) {
      console.log('WebSocket closed');
    };

    function sendMessage() {
      var message = document.getElementById('message').value;
      socket.send(message);
    }
  </script>
</head>
<body>
  <h1>WebSocket Example</h1>
  <input type="text" id="message" placeholder="Enter message">
  <button onclick="sendMessage()">Send Message</button>
</body>
</html>
)HTMLHOMEPAGE";

// Create an instance of the server
AsyncWebServer server(80);

// Create an instance of the WebSocket
AsyncWebSocket wsCarInput("/CarInput");

void onCarInputWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,void *arg, uint8_t *data, size_t len){
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      AwsFrameInfo *info;
      info = (AwsFrameInfo*)arg;
      if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        //std::string myData = "";
        //myData.assign((char *)data, len);
        //std::istringstream ss(myData);
        //std::string key, value;
        //std::getline(ss, key, ',');
        //std::getline(ss, value, ',');
        //Serial.printf("Key [%s] Value[%s]\n", key.c_str(), value.c_str()); 
        //int valueInt = atoi(value.c_str());     
        Serial.printf("ws[%s][%u] %s-message[%llu]: ", server->url(), client->id(), (info->opcode == WS_TEXT)?"text":"binary", info->len);
      }
      break;
    case WS_EVT_PONG:
      Serial.printf("ws[%s][%u] pong[%u]: %s\n", server->url(), client->id(), len, (len)?(char*)data:"");
      break;
    case WS_EVT_ERROR:
      Serial.printf("ws[%s][%u] error(%u): %s\n", server->url(), client->id(), *((uint16_t*)arg), (char*)data);
      break;
    default:
      break;  
  }
}

void setup() {
  Serial.begin(115200);
  
  // AP name,passwd
  WiFi.softAP(host, password);
  WiFi.setTxPower(WIFI_POWER_MINUS_1dBm);

  
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", htmlHomePage);
  });
  server.onNotFound([](AsyncWebServerRequest *request){
    request->send(404, "text/plain", "File Not Found");
  });
      
  wsCarInput.onEvent(onCarInputWebSocketEvent);
  server.addHandler(&wsCarInput);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handle WebSocket events
  wsCarInput.cleanupClients();
}