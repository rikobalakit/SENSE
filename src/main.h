#include <Arduino.h>
#include <ESP32_PWM.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>


#define NUMBER_ISR_PWMS         16

#define PIN_D0            0         // Pin D0 mapped to pin GPIO0/BOOT/ADC11/TOUCH1 of ESP32
#define PIN_D1            1         // Pin D1 mapped to pin GPIO1/TX0 of ESP32
#define PIN_D2            2         // Pin D2 mapped to pin GPIO2/ADC12/TOUCH2 of ESP32
#define PIN_D3            3         // Pin D3 mapped to pin GPIO3/RX0 of ESP32
#define PIN_D4            4         // Pin D4 mapped to pin GPIO4/ADC10/TOUCH0 of ESP32
#define PIN_D5            5         // Pin D5 mapped to pin GPIO5/SPISS/VSPI_SS of ESP32
#define PIN_D6            6         // Pin D6 mapped to pin GPIO6 of ESP32
#define PIN_D7            7         // Pin D7 mapped to pin GPIO7 of ESP32
#define PIN_D8            8         // Pin D8 mapped to pin GPIO8 of ESP32
#define PIN_D9            9         // Pin D9 mapped to pin GPIO9 of ESP32
#define PIN_D10           10        // Pin D10 mapped to pin GPIO10 of ESP32
#define PIN_D11           11        // Pin D11 mapped to pin GPIO11 of ESP32
#define PIN_D12           12        // Pin D12 mapped to pin GPIO12/HSPI_MISO/ADC15/TOUCH5/TDI of ESP32
#define PIN_D13           13        // Pin D13 mapped to pin GPIO13/HSPI_MOSI/ADC14/TOUCH4/TCK of ESP32
#define PIN_D14           14        // Pin D14 mapped to pin GPIO14/HSPI_SCK/ADC16/TOUCH6/TMS of ESP32
#define PIN_D15           15        // Pin D15 mapped to pin GPIO15/HSPI_SS/ADC13/TOUCH3/TDO of ESP32
#define PIN_D16           16        // Pin D16 mapped to pin GPIO16/TX2 of ESP32
#define PIN_D17           17        // Pin D17 mapped to pin GPIO17/RX2 of ESP32     
#define PIN_D18           18        // Pin D18 mapped to pin GPIO18/VSPI_SCK of ESP32
#define PIN_D19           19        // Pin D19 mapped to pin GPIO19/VSPI_MISO of ESP32

#define PIN_D21           21        // Pin D21 mapped to pin GPIO21/SDA of ESP32
#define PIN_D22           22        // Pin D22 mapped to pin GPIO22/SCL of ESP32
#define PIN_D23           23        // Pin D23 mapped to pin GPIO23/VSPI_MOSI of ESP32
#define PIN_D25           25        // Pin D25 mapped to pin GPIO25/ADC18/DAC1 of ESP32
#define PIN_D26           26        // Pin D26 mapped to pin GPIO26/ADC19/DAC2 of ESP32
#define PIN_D27           27    

#define PIN_GREY            PIN_D16
#define PIN_ORANGE          PIN_D17
#define PIN_YELLOW          PIN_D19
#define PIN_GREEN           PIN_D4
#define PIN_BLUE            PIN_D13
#define PIN_PURPLE          PIN_D18
                                
#define HW_TIMER_INTERVAL_US      20L// Pin D27 mapped to pin GPIO27/ADC17/TOUCH7 of ESP32   
uint32_t startMicros = 0;

Adafruit_SSD1306 Display(-1); //-1 arg means no reset pin
bool _displayEnabledAndFound = false;
String _line0, _line1, _line2, _line3, _line4, _line5;

void DisplayText(float timeSeconds, String line0 = "", String line1 = "", String line2 = "", String line3 = "",
                 String line4 = "", String line5 = "");
