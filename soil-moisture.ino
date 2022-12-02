#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1     // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int AirValue = 582;
// const int AirValue = 621;
const int WaterValue = 330;
int soilMoistureValue = 0;
int soilmoisturepercent = 0;
void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.dim(true);
  display.clearDisplay();
}
void loop() {
  soilMoistureValue = analogRead(A0);
  // Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if (soilmoisturepercent >= 100) {
    // Serial.println("100 %");

    display.setCursor(45, 0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println("Soil");
    display.setCursor(20, 16);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println("Moisture");

    display.setCursor(30, 40);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println("100 %");
    display.display();

    delay(1000);
    display.clearDisplay();
  } else if (soilmoisturepercent <= 0) {
    // Serial.println("0 %");

    display.setCursor(45, 0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println("Soil");
    display.setCursor(20, 16);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println("Moisture");

    display.setCursor(30, 40);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println("0 %");
    display.display();

    delay(1000);
    display.clearDisplay();
  } else if (soilmoisturepercent > 0 && soilmoisturepercent < 100) {
    // Serial.print(soilmoisturepercent);
    // Serial.println("%");

    display.setCursor(45, 0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println("Soil");
    display.setCursor(20, 16);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println("Moisture");

    display.setCursor(30, 40);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println(soilmoisturepercent);
    display.setCursor(70, 40);
    display.setTextSize(2);
    display.println("%");
    display.display();

    delay(1000);
    display.clearDisplay();
  }
}

