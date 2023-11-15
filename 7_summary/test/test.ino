#include <WiFi.h>
#include <ESPAsyncWebSrv.h>
#include <AsyncTCP.h>



const char *ssid = "your-ssid";
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
AsyncWebServer ws("/ws");

void setup() {
  // Serial
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Route to serve HTML page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });

  // WebSocket event handler
  ws.onEvent([](AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len){
    if(type == WS_EVT_CONNECT){
      Serial.println("WebSocket client connected");
    } else if(type == WS_EVT_DISCONNECT){
      Serial.println("WebSocket client disconnected");
    } else if(type == WS_EVT_DATA){
      AwsFrameInfo *info = (AwsFrameInfo*)arg;
      if(info->opcode == WS_TEXT){
        // Handle text data received from the client
        String message = "";
        for(size_t i=0; i < len; i++){
          message += (char)data[i];
        }
        Serial.println("WebSocket received message: " + message);
        // You can send a response back to the client if needed
        // client->text("Message received: " + message);
      }
    }
  });

  // Add the WebSocket handler to the server
  server.addHandler(&ws);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handle WebSocket events
  ws.cleanupClients();
}