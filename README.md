# Weather_forecast_with_BME
Weather forecast system using esp32 with BME



ABSTRACT
Weather forecasting involves predicting future weather conditions based on various climatic parameters, including temperature, wind, humidity, and rainfall. For this analysis, we focus on temperature and humidity. Data is collected from the OpenWeatherMap API, which provides temperature and humidity values for specific regions or locations. The data is displayed on an OLED screen connected to an ESP32 board. Correlation analysis of these parameters aids in predicting future values, and the ARIMA model, known for its effectiveness with time-series data, is employed for making these predictions.

WEATHER FORECAST
INTRODUCTION
In today's technologically advanced era, real-time information plays a crucial role in various applications. One such application is a Weather Forecast Display Board that provides up-to-date weather information briefly. To enhance the accuracy and reliability of our project, we will integrate it with a Weather API (Application Programming Interface). APIs act as intermediaries, allowing our project to communicate with external data sources seamlessly. In this case, the Weather API will provide us with current weather conditions, forecasts, and other relevant data.

DEFINING THE PROBLEM
In ancient times, forecasting was mostly based on weather pattern observation. Over the years, the study of weather patterns has resulted in various techniques for rainfall forecasting. Present rainfall forecasting embodies a combination of computer models, interpretation, and an acquaintance of weather patterns.

SOLUTION PROPOSED
Weather forecasting is the application of science and technology to predict the state of the atmosphere for a given location. Weather forecasts are made by collecting quantitative data about the current state of the atmosphere and using scientific understanding of atmospheric processes to project how the atmosphere will evolve. There are a variety of end users to weather forecasts. Weather warnings are important forecasts because they are used to protect life and property. 

COMPONENTS REQUIRED 
1.	ESP32¬-WROOM¬32E
2.	ARDUINO UNO 
3.	LCD DISPLAY WITH I2C
4.	OLED DISPLAY SENSOR
5.	BME - 280
6.	BREAD BOARD 
7.	JUMPER WIRES 

SOFTWARE TOOLS 
1.	ARDUINO IDE 
2.	OpenWeather Map

 
COMPONENTS SPECIFICATION

ESP32-¬WROOM¬32E

The ESP32 is a popular microcontroller and Wi-Fi/Bluetooth module that is widely used in the field of embedded systems and IoT (Internet of Things). It is developed by Espressif Systems.
FEATURES
	Small volume, easily embedded to other products
	Strong function with support LWIP Protocol, Freertos
	Supporting three modes:  AP, STA, and AP+STA
	Supporting Lua program, easily to develop
	Includes CP2102 USB-UART bridge.


ARDUINO UNO

The Arduino Uno is an open-source microcontroller board based on the ATmega328P, popular for electronics projects and prototyping. It includes 14 digital I/O pins, 6 analog inputs, a USB connection, a power jack, and a reset button. The board is programmed using the Arduino IDE, which simplifies coding and uploading to the microcontroller.
FEATURES
	Microcontroller: ATmega328P.
	Operating Voltage: 5V.
	Input Voltage: 7-12V (recommended), 6-20V (limits).
	Digital I/O Pins: 14 (6 PWM outputs).
	Analog Input Pins: 6.
	DC Current per I/O Pin: 20 mA.
	Flash Memory: 32 KB (0.5 KB used by bootloader).
	SRAM: 2 KB.
	EEPROM: 1 KB.

 
LCD – I2C DISPLAY SENSOR

This LCD screen is a 16x2 character LCD display with an I2C interface. It features two rows for displaying text, with each row capable of displaying up to 16 characters. The white characters will be displayed on a blue background, providing a clear and visually appealing display.
In traditional Arduino LCD display projects, there are often limitations in terms of available pins, especially when using Arduino Uno. Additionally, wiring and connections can become quite complex. To address these issues, we introduce this I2C 16x2 Arduino LCD display, which utilizes the I2C communication interface. This means that it only requires 4 pins to connect the LCD display, including VCC, GND, SDA, and SCL. 
Applications
•	Data Display: Show sensor readings or system status.
•	User Interfaces: Create simple menus and interaction points.
•	Debugging: Display debug information during development.


OLED-DISPLAY SENSOR

OLED (Organic Light-Emitting Diodes) is a flat light emitting technology-based screen. OLED is an advanced display technology made from a thin film of light-emitting organic materials. When electrical current is applied, a bright light is emitted from OLED. 
Applications
•	Used in consumer electronics.
•	Used for Smartwatch, mobile phone, and MP3 displays.
•	Small level gaming displays.
•	Wide range of viewing angle enables to be used in low light.

PIN CONFIGURATION
Pin Name	Description
Ground (GND)	Connected to the ground of the circuit
Vcc (VCC,5V)	Can be powered by either 3.3V or 5V
SCL (D0, CLK)	It is a clock signal. This pin transmits clocks to a slave, SCL. Data will be sent to other devices on clock tick event. The only master device has control over this SCL line
SDA (D1, MOSI)	SDA is used to transmit data between master and slave. The data and acknowledgement are sent through SDA.

Features of OLED Display
•	Monochrome 7-pin SSD1306 0.96” OLED display.
•	128×64-pixel resolution with 160° viewing angle.
•	Supply voltage 3V – 5V (supports both 5V and 3.31v logic devices).
•	It uses SSD1306 for interfacing hence can communicate through SPI or IIC.
•	Multiple SPI or IIC devices are supported
•	It can be easily interfaced with Arduino (Library available).
•	Supports decent graphics of bitmap images.


BME-280

FEATURES
•	Package 2.5 mm x 2.5 mm x 0.93 mm metal lid LGA
•	Digital interface I2C (up to 3.4 MHz) and SPI (3 and 4 wire, up to 10 MHz)
•	Supply voltage VDD main supply voltage range: 1.71 V to 3.6 V
•	VDDIO interface voltage range: 1.2 V to 3.6 V
•	Current consumption 1.8 uA @ 1 Hz humidity and temperature
•	2.8 uA @ 1 Hz pressure and temperature
o	uA @ 1 Hz humidity, pressure and temperature
o	uA in sleep mode
•	Operating range -40…+85 C, 0…100 % rel. humidity, 300…1100 hPa- Humidity sensor and pressure sensor can be independently enabled/disabled
 

BREAD BOARD

A modern solderless breadboard socket consists of a perforated block of plastic with numerous tin planted phosphor bronze or nickel silver alloy spring clips under the perforations. The clips are often called tie points or contact points. The number of tie points is often given in the specification of the breadboard.

Solderless breadboards connect pin to pin by metal strips inside the breadboard. The layout of a typical solderless breadboard is made up from two types of areas, called strips. Strips consist of interconnected electrical terminals. Often breadboard strips or blocks of one brand have male and female dovetail notches so boards can be clipped together to form a large breadboard.

 
JUMPER WIRES

A jump wire (also known as jumper, jumper wire, DuPont wire) is an electrical wire, or group of them in a cable, with a connector or pin at each end (or sometimes without them – simply "tinned"), which is normally used to interconnect the components of a breadboard or other prototype or test circuit, internally or with other equipment or components, without soldering.

Individual jump wires are fitted by inserting their "end connectors" into the slots provided in a breadboard, the header connector of a circuit board, or a piece of test equipment.


SOFTWARE TOOLS

ARDUINO IDE

The Arduino IDE (Integrated Development Environment) is a software platform that is used to write and upload code to Arduino boards. Here’s a brief introduction:
Arduino IDE
	The Arduino IDE is an open-source platform, making it freely available for anyone to use and modify.
	It provides a user-friendly interface for writing, compiling, and uploading code to Arduino boards.
	Arduino boards are widely used in electronics and programming projects, especially in the realm of hobbyist and educational applications.
	The IDE is compatible with various Arduino boards, each having its own unique features and capabilities.
	It simplifies the process of programming microcontrollers on Arduino boards, making it accessible to beginners and experienced developers alike.
	The IDE supports the C and C++ programming languages and is based on the Wiring framework.

Key features
	Code Editor: The IDE includes a text editor where you can write and edit your Arduino code.
	Compiler: It has a built-in compiler that translates your human-readable code into machine-readable code (binary) that the Arduino board can understand.
	Upload Tool: The IDE allows you to upload your compiled code to the Arduino board, enabling it to execute the programmed functionality.
	Serial Monitor: A feature that enables you to communicate with your Arduino board and monitor the data being sent and received through the serial port.
	Library Manager: Arduino IDE supports libraries, which are pre-written code modules that you can include in your projects. The Library Manager makes it easy to add, update, and manage libraries.

 
OpenWeather Map

OpenWeatherMap is a service that provides weather data and related information. It offers a wide range of weather-related data, including current weather conditions, forecasts, and historical data. Developers often use OpenWeatherMap's API (Application programming interface) to integrate weather information into their applications or websites.

If you're looking to access weather data through OpenWeatherMap, you can visit their official website at https://openweathermap.org/. They offer various APIs that allow you to retrieve weather information programmatically.

Please note that while some features of OpenWeatherMap are available for free, certain advanced functionalities and higher usage levels may require a subscription or payment. Make sure to review their terms of use and pricing information if you plan to use their services extensively.


Wiring Instructions:

BME280 Sensor to ESP32:

VCC (BME280) → 3.3V (ESP32)
GND (BME280) → GND (ESP32)
SDA (BME280) → SDA (ESP32) (which is GPIO 21 by default on ESP32)
SCL (BME280) → SCL (ESP32) (which is GPIO 22 by default on ESP32)
If using a different microcontroller, ensure that SDA and SCL match the appropriate pins.

LCD (16x2) with I2C:

VCC (LCD) → 5V (ESP32)
GND (LCD) → GND (ESP32)
SDA (LCD) → SDA (ESP32) (which is GPIO 21 by default on ESP32)
SCL (LCD) → SCL (ESP32) (which is GPIO 22 by default on ESP32)
Note: The LCD and BME280 share the I2C bus, so both should connect to the same SDA and SCL lines on the ESP32.

SSD1306 OLED Display:

VCC (OLED) → 3.3V (ESP32)
GND (OLED) → GND (ESP32)
SDA (OLED) → SDA (ESP32) (GPIO 21)
SCL (OLED) → SCL (ESP32) (GPIO 22)
The OLED display also shares the I2C bus with the LCD and BME280 sensor.

LED:

LED anode (long leg) → GPIO 2 (ESP32)
LED cathode (short leg) → GND (ESP32)
BME280 Power Pin (optional):

If you wish to control the power to the BME280 sensor programmatically:
Pin 4 (ESP32) → VCC (BME280)


          +-------------------------+
          |         ESP32            |
          |                          |
          |      +-----+     +-----+ |
     3.3V |------| VCC |     | VCC | |--> 3.3V
          |      +-----+     +-----+ |
     GND  |------| GND |     | GND | |--> GND
          |      +-----+     +-----+ |
     SDA  |------| SDA |     | SDA | |--> GPIO 21 (I2C Data Line)
          |      +-----+     +-----+ |
     SCL  |------| SCL |     | SCL | |--> GPIO 22 (I2C Clock Line)
          |      +-----+     +-----+ |
          |                          |
          |  +---------+   +------+  |
  GPIO 2  |--| LED Anode | | LED |   |--> LED Cathode to GND
          |  +---------+   +------+  |
          +-------------------------+



SOURCE CODE

#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <time.h>
#include <sys/time.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <SSD1306Wire.h>
#include <OLEDDisplayUi.h>
#include <LiquidCrystal_I2C.h>  // Include the LiquidCrystal_I2C library

#include "OpenWeatherMapCurrent.h"
#include "OpenWeatherMapForecast.h"

// LCD settings
#define LCD_ADDRESS 0x27  // Adjust this according to your LCD module
#define LCD_COLUMNS 16
#define LCD_ROWS 2
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // Create an instance of the sensor
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS); // Initialize the LCD

// LED Pin for ESP32
const int LED_PIN = 2;
// WIFI
const char *WIFI_SSID = "SANTOSH";
const char *WIFI_PWD = "12345678";

#define TZ 5.5     // (utc+) TZ in hours
#define DST_MN 60  // use 60mn for summer time in some countries

// Setup
const int UPDATE_INTERVAL_SECS = 20 * 60;  // Update every 20 minutes

// Display Settings
const int I2C_DISPLAY_ADDRESS = 0x3c;
const int SDA_PIN = 5;  //D3;
const int SDC_PIN = 4;  //D4;

// OpenWeatherMap Settings
String OPEN_WEATHER_MAP_APP_ID = "123800b9a61d9e8368f6541201c41d52";
String OPEN_WEATHER_MAP_LOCATION_ID = "1277333"; // Find your location ID on OpenWeatherMap
String OPEN_WEATHER_MAP_LANGUAGE = "en";
const uint8_t MAX_FORECASTS = 4;

const boolean IS_METRIC = true;

// Adjust according to your language
const String WDAY_NAMES[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
const String MONTH_NAMES[] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };

// Initialize the oled display for address 0x3c
SSD1306Wire display(I2C_DISPLAY_ADDRESS, SDA_PIN, SDC_PIN);
OLEDDisplayUi ui(&display);

OpenWeatherMapCurrentData currentWeather;
OpenWeatherMapCurrent currentWeatherClient;

OpenWeatherMapForecastData forecasts[MAX_FORECASTS];
OpenWeatherMapForecast forecastClient;

#define TZ_MN ((TZ)*60)
#define TZ_SEC ((TZ)*3600)
#define DST_SEC ((DST_MN)*60)
time_t now;

// flag changed in the ticker function every 10 minutes
bool readyForWeatherUpdate = false;

String lastUpdate = "--";

long timeSinceLastWUpdate = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);  // Initialize the LED pin as an output

  // Initialize BME280 sensor
  pinMode(4, OUTPUT); // Define pin 4 as output for BME280 power
  digitalWrite(4, HIGH); // Set pin 4 HIGH to power the BME280
  if (!bme.begin(0x76)) { // Replace with your BME280 I2C address if different
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  // Initialize LCD
  lcd.begin();  // Initialize the LCD with default address and dimensions
  lcd.backlight(); // Turn on the backlight
  lcd.clear(); // Clear the LCD screen
  lcd.print("BME280 Sensor"); // Print initial message
  lcd.setCursor(0, 1); // Set cursor to start of second line
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear(); // Clear the LCD screen

  // Initialize OLED display
  display.init();
  display.clear();
  display.display();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setContrast(255);
  WiFi.begin(WIFI_SSID, WIFI_PWD);

  int counter = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    display.clear();
    display.drawString(64, 10, "Connecting to WiFi");
    display.display();
    counter++;
  }

  // Get time from network time service
  configTime(TZ_SEC, DST_SEC, "pool.ntp.org");

  ui.setTargetFPS(30);
  ui.setIndicatorPosition(BOTTOM);
  ui.setIndicatorDirection(LEFT_RIGHT);
  ui.setFrameAnimation(SLIDE_LEFT);
  //ui.setFrames(frames, numberOfFrames);  // Uncomment and adjust according to your display setup
  //ui.setOverlays(overlays, numberOfOverlays);  // Uncomment and adjust according to your display setup
  ui.init();

  updateData(&display);
}
void loop() {
  if (millis() - timeSinceLastWUpdate > (1000L * UPDATE_INTERVAL_SECS)) {
    setReadyForWeatherUpdate();
    timeSinceLastWUpdate = millis();
  }

  if (readyForWeatherUpdate && ui.getUiState()->frameState == FIXED) {
    updateData(&display);
  }

  int remainingTimeBudget = ui.update();

  if (remainingTimeBudget > 0) {
    delay(remainingTimeBudget);
  }

  blinkLED();
}

// Example definitions for overlays (adjust based on your specific use case)
const uint8_t numberOfOverlays = 1;  // Adjust the number of overlays as needed
const uint8_t overlay1[1024] = { /* pixel data for overlay 1 */ };

// Define the overlays array
const uint8_t* overlays[] = { overlay1 };  // Array of pointers to overlays
void updateData(OLEDDisplay *display) {
  drawProgress(display, 10, "Updating time...");
  drawProgress(display, 30, "Updating weather...");
  currentWeatherClient.setMetric(IS_METRIC);
  currentWeatherClient.setLanguage(OPEN_WEATHER_MAP_LANGUAGE);
  currentWeatherClient.updateCurrentById(&currentWeather, OPEN_WEATHER_MAP_APP_ID, OPEN_WEATHER_MAP_LOCATION_ID);
  drawProgress(display, 50, "Updating forecasts...");
  forecastClient.setMetric(IS_METRIC);
  forecastClient.setLanguage(OPEN_WEATHER_MAP_LANGUAGE);
  uint8_t allowedHours[] = { 12 };
  forecastClient.setAllowedHours(allowedHours, sizeof(allowedHours));
  forecastClient.updateForecastsById(forecasts, OPEN_WEATHER_MAP_APP_ID, OPEN_WEATHER_MAP_LOCATION_ID, MAX_FORECASTS);

  readyForWeatherUpdate = false;
  drawProgress(display, 100, "Done...");
  delay(1000);
}

void drawProgress(OLEDDisplay *display, int percentage, String label) {
  display->clear();
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_10);
  display->drawString(64, 10, label);
  display->drawProgressBar(2, 28, 124, 10, percentage);
  display->display();
}

void blinkLED() {
  static unsigned long previousMillis = 0;
  const long interval = 1500;  // Blink interval in milliseconds

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (digitalRead(LED_PIN) == HIGH) {
      digitalWrite(LED_PIN, LOW);
    } else {
      digitalWrite(LED_PIN, HIGH);
    }
  }
}

void setReadyForWeatherUpdate() {
  Serial.println("Setting readyForUpdate to true");
  readyForWeatherUpdate = true;
}

void displayTemperature() {
  lcd.clear();
  lcd.print("Temp:");
  lcd.setCursor(7, 0);
  lcd.print(bme.readTemperature(), 1); // Display temperature in Celsius
  lcd.print((char)223); // Display degree symbol
  lcd.print("C ");

  lcd.setCursor(0, 1);
  lcd.print("       ");
  lcd.setCursor(7, 1);
  lcd.print(bme.readTemperature() * 1.8 + 32, 1); // Display temperature in Fahrenheit
  lcd.print((char)223); // Display degree symbol
  lcd.print("F");
}

void displayHumidity() {
  lcd.clear();
  lcd.print("Humidity:");
  lcd.setCursor(10, 0);
  lcd.print(bme.readHumidity(), 1); // Display humidity
  lcd.print("%");
}

void displayPressure() {
  lcd.clear();
  lcd.print("Pressure:");
  lcd.setCursor(10, 0);
  lcd.print(bme.readPressure() / 100.0F, 1); // Display pressure in hPa
  lcd.print("hPa");
}

void displayAltitude() {
  lcd.clear();
  lcd.print("Altitude:");
  lcd.setCursor(9, 0);
  lcd.print(bme.readAltitude(SEALEVELPRESSURE_HPA), 1); // Display altitude in meters
  lcd.print("m");
}


CONCLUSION

Weather forecasting is the application of science and technology to predict the state of the atmosphere for a given location. Weather forecasts are made by collecting quantitative data about the current state of the atmosphere and using scientific understanding of atmospheric processes to project how the atmosphere will evolve. There are a variety of end users to weather forecasts. Weather warnings are important forecasts because they are used to protect life and property.

BIBLIOGRAPHY

https://openweathermap.org/
source code link 

https://github.com/santosh148411/Weather-forecast-

