# ESP32-DevKitC V4 Pinout

<img width="100%" src="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitC-v4-pinout.png">

## The two tables below provide the **Name** and **Function** of I/O header pins on both sides of the board

---
### J2
| No. | Name | Type [1]_ | Function                        |
| --- | ---- | ---------- | ------------------------------- |
| 1   | 3V3  | P          | 3.3 V power supply              |
| 2   | EN   | I          | CHIP_PU, Reset                 |
| 3   | VP   | I          | GPIO36, ADC1_CH0, S_VP         |
| 4   | VN   | I          | GPIO39, ADC1_CH3, S_VN         |
| 5   | IO34 | I          | GPIO34, ADC1_CH6, VDET_1       |
| 6   | IO35 | I          | GPIO35, ADC1_CH7, VDET_2       |
| 7   | IO32 | I/O        | GPIO32, ADC1_CH4, TOUCH_CH9, XTAL_32K_P |
| 8   | IO33 | I/O        | GPIO33, ADC1_CH5, TOUCH_CH8, XTAL_32K_N |
| 9   | IO25 | I/O        | GPIO25, ADC1_CH8, DAC_1        |
| 10  | IO26 | I/O        | GPIO26, ADC2_CH9, DAC_2        |
| 11  | IO27 | I/O        | GPIO27, ADC2_CH7, TOUCH_CH7    |
| 12  | IO14 | I/O        | GPIO14, ADC2_CH6, TOUCH_CH6, MTMS |
| 13  | IO12 | I/O        | GPIO12, ADC2_CH5, TOUCH_CH5, MTDI |
| 14  | GND  | G          | Ground                          |
| 15  | IO13 | I/O        | GPIO13, ADC2_CH4, TOUCH_CH4, MTCK |
| 16  | D2   | I/O        | GPIO9, D2 [2]_                 |
| 17  | D3   | I/O        | GPIO10, D3 [2]_                |
| 18  | CMD  | I/O        | GPIO11, CMD [2]_               |
| 19  | 5V   | P          | 5 V power supply                |


---
### J3
| No. | Name | Type [1]_ | Function                                       |
| --- | ---- | ---------- | --------------------------------------------- |
| 1   | GND  | G          | Ground                                        |
| 2   | IO23 | I/O        | GPIO23                                        |
| 3   | IO22 | I/O        | GPIO22                                        |
| 4   | TX   | I/O        | GPIO1, U0TXD                                  |
| 5   | RX   | I/O        | GPIO3, U0RXD                                  |
| 6   | IO21 | I/O        | GPIO21                                        |
| 7   | GND  | G          | Ground                                        |
| 8   | IO19 | I/O        | GPIO19                                        |
| 9   | IO18 | I/O        | GPIO18                                        |
| 10  | IO5  | I/O        | GPIO5                                         |
| 11  | IO17 | I/O        | GPIO17 [3]_                                   |
| 12  | IO16 | I/O        | GPIO16 [3]_                                   |
| 13  | IO4  | I/O        | GPIO4, ADC2_CH0, TOUCH_CH0                    |
| 14  | IO0  | I/O        | GPIO0, ADC2_CH1, TOUCH_CH1, Boot              |
| 15  | IO2  | I/O        | GPIO2, ADC2_CH2, TOUCH_CH2                    |
| 16  | IO15 | I/O        | GPIO15, ADC2_CH3, TOUCH_CH3, MTDO             |
| 17  | D1   | I/O        | GPIO8, D1 [2]_                                |
| 18  | D0   | I/O        | GPIO7, D0 [2]_                                |
| 19  | CLK  | I/O        | GPIO6, CLK [2]_                               |

* [1] P: Power supply; I: Input; O: Output.
* [2] The pins D0, D1, D2, D3, CMD and CLK are used internally for communication between ESP32 and SPI flash memory. They are grouped on both sides near the USB connector. Avoid using these pins, as it may disrupt access to the SPI flash memory/SPI RAM.
* [3] The pins GPIO16 and GPIO17 are available for use only on the boards with the modules ESP32-WROOM and ESP32-SOLO-1. The boards with ESP32-WROVER modules have the pins reserved for internal use.

---
### GPIO

| GPIO  | Input          | Output      | Notes                                                |
|-------|----------------|-------------|------------------------------------------------------|
| 0     | pulled up      | OK          | Outputs PWM signal at boot, must be LOW to enter flashing mode |
| 1     | TX pin         | OK          | Debug output at boot                                |
| 2     | OK             | OK          | Connected to on-board LED, must be left floating or LOW to enter flashing mode |
| 3     | OK             | RX pin      | HIGH at boot                                        |
| 4     | OK             | OK          |                                                    |
| 5     | OK             | OK          | Outputs PWM signal at boot, strapping pin           |
| 6     | x              | x           | Connected to the integrated SPI flash              |
| 7     | x              | x           | Connected to the integrated SPI flash              |
| 8     | x              | x           | Connected to the integrated SPI flash              |
| 9     | x              | x           | Connected to the integrated SPI flash              |
| 10    | x              | x           | Connected to the integrated SPI flash              |
| 11    | x              | x           | Connected to the integrated SPI flash              |
| 12    | OK             | OK          | Boot fails if pulled high, strapping pin            |
| 13    | OK             | OK          |                                                    |
| 14    | OK             | OK          | Outputs PWM signal at boot                         |
| 15    | OK             | OK          | Outputs PWM signal at boot, strapping pin           |
| 16    | OK             | OK          |                                                    |
| 17    | OK             | OK          |                                                    |
| 18    | OK             | OK          |                                                    |
| 19    | OK             | OK          |                                                    |
| 21    | OK             | OK          |                                                    |
| 22    | OK             | OK          |                                                    |
| 23    | OK             | OK          |                                                    |
| 25    | OK             | OK          |                                                    |
| 26    | OK             | OK          |                                                    |
| 27    | OK             | OK          |                                                    |
| 32    | OK             | OK          |                                                    |
| 33    | OK             | OK          |                                                    |
| 34    | OK             | Input only  |                                                    |
| 35    | OK             | Input only  |                                                    |
| 36    | OK             | Input only  |                                                    |
| 39    | OK             | Input only  |                                                    |
