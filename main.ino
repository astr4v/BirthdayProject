#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"
#include "DisplayUI.h"
#include "sound.h"

// Initialize display with standard I2C reset pin config (-1)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int lastTouchState = LOW;

void setup()   {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  pinMode(Pin_button, INPUT);
  
  initDisplay();
  initSound();

  }

void loop() {
  int touchState = digitalRead(Pin_button);
  if (touchState == HIGH && lastTouchState == LOW) {
    jalankanSkenario();
  } 
  else if (touchState == LOW) {
    showStandbyText();
    stopSound();
  }
  lastTouchState = touchState;
  delay(50); // Debounce
}

void jalankanSkenario() {
  playAnimation();
  delay(500);
  showBirthdayMessage();
  playHappyBirthday();
  delay(500);
  showFinalImage();
  delay(5000); 
}