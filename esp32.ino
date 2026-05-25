#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>

#define TFT_CS 4
#define TFT_RST 5
#define TFT_DC 2
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_BL 15

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

unsigned long stopwatchStart = 0;
unsigned long stopwatchElapse = 0;
bool stopwatchRunning = false;
bool jumpstart = false;
bool done = false;

const int buttonPin = 22;

void initScreen() {
  for (int i = 5; i < 155; i = i + 30) {
    tft.fillCircle(i + 15, 24, 10, ST7735_BLACK);

    tft.fillCircle(i + 15, 49, 10, ST7735_BLACK);

    tft.drawCircle(i + 15, 74, 10, ST7735_BLACK);

    tft.drawCircle(i + 15, 99, 10, ST7735_BLACK);


    tft.drawRect(i + 2, 10, 26, 105, ST7735_BLACK);
  }
}


void countDown() {

  for (int i = 5; i < 155; i = i + 30) {
    tft.fillCircle(i + 15, 74, 10, ST7735_RED);

    tft.fillCircle(i + 15, 99, 10, ST7735_RED);

    for (int i = 0; i < 1000; i = i + 50) {
      delay(50);

      // if (jumpstarted()) {
      //   return;
      // }

      if (digitalRead(buttonPin) == LOW) {
        stopwatchRunning = true;
        jumpstart = true;

        Serial.print("JUMPSTART");
        return;
      }
    }
  }

  int randint = random(500, 3000);

  for (int i = 0; i < randint; i = i + 50) {
    delay(50);

    // if (jumpstarted()) {
    //   return;
    // }

    if (digitalRead(buttonPin) == LOW) {
      stopwatchRunning = true;
      jumpstart = true;

      Serial.print("JUMPSTART");
      return;
    }
  }


  for (int i = 5; i < 155; i = i + 30) {

    tft.fillCircle(i + 15, 74, 10, ST7735_WHITE);

    tft.fillCircle(i + 15, 99, 10, ST7735_WHITE);

    stopwatchStart = millis();
    stopwatchRunning = true;

    tft.drawCircle(i + 15, 74, 10, ST7735_BLACK);

    tft.drawCircle(i + 15, 99, 10, ST7735_BLACK);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing ST7735 display...");

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.initR(INITR_BLACKTAB);

  tft.fillScreen(ST7735_BLACK);
  Serial.println("Initialization complete.");

  tft.setRotation(1);
  tft.fillScreen(ST7735_WHITE);
  initScreen();
  countDown();
}

void loop() {
  if (jumpstart && stopwatchRunning) {
    tft.fillScreen(ST7735_WHITE);
    tft.setCursor(10, 128 / 2);
    tft.setTextColor(ST7735_RED);
    tft.setTextSize(2);
    tft.print("Jumpstarted");
    stopwatchRunning = false;
    done = true;
  } else if (digitalRead(buttonPin) == LOW && stopwatchRunning && !jumpstart) {
    stopwatchElapse = millis() - stopwatchStart;
    stopwatchRunning = false;

    tft.fillScreen(ST7735_WHITE);
    tft.setCursor(20, 64);
    tft.setTextColor(ST7735_RED);
    tft.setTextSize(2);

    tft.print(stopwatchElapse);
    tft.println(" ms");

    Serial.println(stopwatchElapse);
    done = true;
  }

  if (done && digitalRead(buttonPin) == LOW) {
    stopwatchStart = 0;
    stopwatchElapse = 0;
    stopwatchRunning = false;
    jumpstart = false;
    done = false;
    tft.fillScreen(ST7735_WHITE);
    initScreen();
    countDown();
  }
}
