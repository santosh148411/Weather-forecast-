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

/***************************
 * End Settings
 **************************/
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


