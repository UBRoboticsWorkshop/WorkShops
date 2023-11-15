# Communications

> [!NOTE]
> You need have general ideals about:
> - HTML, JavaScript
> - UDP, TCP
> - WebSocket

>BTW, these are all technologies used for network communication. 
>HTML and JavaScript -> web-based user interfaces.
>
>UDP (User Datagram Protocol), TCP (Transmission Control Protocol), and WebSocket -> used for communication between devices.
---
<details>
  <summary>

  ## 1. Setup an AP
  </summary>


>Why are we doing this?
>
>To understand how ESP32 acts as a Wi-Fi hotspot. It involves selecting the ESP32 board, including the Wi-Fi library, setting up AP credentials, and defining the setup and optional loop functions.

> Setting up an Access Point (AP) with an ESP32 involves configuring the ESP32 to act as a Wi-Fi hotspot. Here's an example using the Arduino IDE and the ESP32 library:

1. **Select the ESP32 Board:**
   Go to "Tools" -> "Board" and select your ESP32 board from the list.

2. **Include Wi-Fi Library:**
   At the beginning of your Arduino sketch, include the Wi-Fi library:
   ```cpp
   #include <WiFi.h>
   ```

3. **Set AP Credentials:**
   Define the SSID and password for your Access Point:
   ```cpp
   const char* ssid = "your_AP_SSID";
   const char* password = "your_AP_PASSWORD";
   ```

4. **Setup Function:**
   In the `setup()` function, initialize serial communication and set up the ESP32 as an Access Point:
   ```cpp
   void setup() {
     Serial.begin(115200);

     // Set up Access Point
     WiFi.softAP(ssid, password);

     Serial.println("Access Point Started");
     Serial.print("IP Address: ");
     Serial.println(WiFi.softAPIP());
   }
   ```

5. **Loop Function (Optional):**
   You can add code in the `loop()` function for any continuous tasks.

6. **Upload and Monitor:**
   Upload the code to your ESP32 by clicking the upload button. Open the Serial Monitor (`Tools` -> `Serial Monitor`) to see the Access Point details.

Here's the complete example:

```cpp
#include <WiFi.h>

const char* ssid = "your_AP_SSID";
const char* password = "your_AP_PASSWORD";

void setup() {
  Serial.begin(115200);

  // Set up Access Point
  WiFi.softAP(ssid, password);

  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Your code here (if needed)
}
```

Replace `"your_AP_SSID"` and `"your_AP_PASSWORD"` with the desired SSID and password for your Access Point. After uploading the code, open the Serial Monitor to see the Access Point details, including the assigned IP address.
</details>

---
<details>
  <summary>

  ## 2. Connect to a WiFi
  </summary>
> This section explains how to connect an ESP32 to an existing Wi-Fi network. It involves selecting the ESP32 board, including the Wi-Fi library,  setting up Wi-Fi credentials , Defining the setup and optional loop functions.

>
>
> Connecting an ESP32 to a Wi-Fi network involves a few steps. Here's a basic example using the Arduino IDE and the ESP32 library. Make sure you have the ESP32 board support installed in your Arduino IDE.

1. **Select the ESP32 Board:**
   Go to "Tools" -> "Board" and select your ESP32 board from the list.

2. **Include Wi-Fi Library:**
   At the beginning of your Arduino sketch, include the Wi-Fi library:
   ```cpp
   #include <WiFi.h>
   ```

3. **Set Wi-Fi Credentials:**
   Define your Wi-Fi network credentials (SSID and password):
   ```cpp
   const char* ssid = "your_SSID";
   const char* password = "your_PASSWORD";
   ```

4. **Setup Function:**
   In the `setup()` function, initialize serial communication and connect to Wi-Fi:
   ```cpp
   void setup() {
     Serial.begin(115200);

     // Connect to Wi-Fi
     WiFi.begin(ssid, password);
     while (WiFi.status() != WL_CONNECTED) {
       delay(1000);
       Serial.println("Connecting to WiFi...");
     }

     Serial.println("Connected to WiFi");
   }
   ```

5. **Loop Function (Optional):**
   You can add code in the `loop()` function for any continuous tasks.

6. **Upload and Monitor:**
   Upload the code to your ESP32 by clicking the upload button. Open the Serial Monitor (`Tools` -> `Serial Monitor`) to see the connection status.

Here's the complete example:

```cpp
#include <WiFi.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  // Your code here (if needed)
}
```

Replace `"your_SSID"` and `"your_PASSWORD"` with your Wi-Fi network credentials. After uploading the code, open the Serial Monitor to see the connection status.
</details>

---
<details>
  <summary>

  ## 3. Data Transfer
  </summary>

> UDP (User Datagram Protocol) and TCP (Transmission Control Protocol) are two of the most widely used protocols in computer networking, providing communication services for different types of applications. Both operate at the transport layer of the Internet Protocol (IP) suite and play crucial roles in facilitating data transfer across networks, but they have distinct characteristics and use cases.
<details>
  <summary>

  ### 3.1. Use UDP Method
  </summary>

**UDP (User Datagram Protocol):**
1. Connectionless: UDP is a connectionless protocol, meaning it does not establish a dedicated connection before sending data. Each packet is sent independently of previous packets.

2. Unreliable: Unlike TCP, UDP does not guarantee reliable data delivery. It does not use acknowledgments or retransmission, so there is no mechanism to ensure that data is received correctly.

3. No flow control: UDP does not implement flow control mechanisms. This can lead to congestion if the sender transmits data at a rate that exceeds the receiver's capacity.

4. No ordered data delivery: UDP does not guarantee the order of delivery. If multiple messages are sent, they may be received out of order by the application layer.

5. Low overhead: Because UDP lacks the reliability and control features of TCP, it has lower overhead. This makes it faster and more suitable for real-time applications where low latency is crucial.

6. Examples of applications: DNS (Domain Name System), DHCP (Dynamic Host Configuration Protocol), streaming media, online gaming, and VoIP (Voice over Internet Protocol) are examples of protocols that use UDP.

> [!WARNING]
> 1. Due to security reasons. Chrome cannot send UDP packages. As a result, this method require a sorce and a sink device.
> 2. The code is untested. But UDP method will have a better result than TCP(WebSocket).

**Code:** https://github.com/sysytwl/web-gamepad-for-esp32


</details>

<details>
  <summary>

  ### 3.2. Use WebSocket(TCP) Method
  </summary>

> WebSocket is a communication protocol that provides full-duplex communication channels over a single, long-lived TCP connection. It is designed to be implemented in web browsers and web servers but can be used by any client or server application. Unlike traditional web communication protocols like HTTP, which follows a request-response model, WebSocket enables bidirectional communication, allowing data to be sent from both the client to the server and vice versa.

### Steps to setup:

#### 1. Install the Required Libraries:

In the Arduino IDE, go to **Sketch > Include Library > Manage Libraries**. Search for and install the following libraries:

- `AsyncTCP` by `me-no-dev`
- `ESPAsyncWebServer` by `me-no-dev`

#### 2. Write the Code:

```cpp
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncWebSocket.h>

const char *ssid = "your-ssid";
const char *password = "your-password";

// Create an instance of the server
AsyncWebServer server(80);

// Create an instance of the WebSocket
AsyncWebSocket ws("/ws");

void setup() {
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

  // Serve static files from SPIFFS
  server.serveStatic("/", SPIFFS, "/");

  // Start the server
  server.begin();
}

void loop() {
  // Handle WebSocket events
  ws.cleanupClients();
}
```

#### 3. Create the HTML file (index.html):

Create a file named `index.html` and save it in the data folder of your Arduino sketch. The data folder should be in the same directory as your `.ino` file.

```html
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
```

#### 4. Upload the Code:

Connect your ESP32 to your computer, select the correct board and port in the Arduino IDE, and upload the code.

#### 5. Test:

Open the Serial Monitor in the Arduino IDE to view the ESP32's serial output. Once the ESP32 is connected to Wi-Fi, it will print an IP address. Open a web browser and navigate to that IP address. You should see the HTML page with a text input and a button.

Open the browser's developer console (press F12) to view WebSocket events. Enter a message in the text input, click "Send Message," and observe the WebSocket events in the console.

This example demonstrates a simple WebSocket setup on an ESP32. You can expand and customize it based on your specific application requirements.

https://github.com/sysytwl/web-gamepad-for-esp32/tree/UoBRobotics_SumoRobotics_WebSocket
</details>

</details>

---
<details>
  <summary>

  ## 4. Alternative method: Bluetooth
  > [!WARNING]
  > This method is very hard.
  </summary>

1. `void setup()` is a special function in Arduino programming that is called once when the microcontroller starts. It's used for initializing things that only need to be done once.
2. `Serial.begin(115200)` is a function call that initializes the serial communication with a baud rate of 115,200. The serial communication is a way for the microcontroller to send and receive data with an external device like a computer.
</details>
