# Communications

> [!NOTE]
> You need have general ideals about:
> - HTML, JavaScript
> - UDP, TCP
> - WebSocket

---
<details>
  <summary>

  ## 1. Setup an AP
  </summary>

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
> 1. Due to security reasons. Chrome cannot send UDP packages. As a result, this method require sorce and sink device.
> 2. The code is untested. But UDP method will have a better result than TCP(WebSocket).

**Code:** https://github.com/sysytwl/web-gamepad-for-esp32


</details>

<details>
  <summary>

  ### 3.2. Use WebSocket(TCP) Method
  </summary>

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