// config.h
#pragma once
#ifndef DISPLAYUI_H
#define DISPLAYUI_H
#include <Arduino.h>
#include <Adafruit_SSD1306.h>
extern Adafruit_SSD1306 display;
void initDisplay();           // Fungsi untuk menyalakan OLED pertama kali di setup()
void showStandbyText();       // Fungsi untuk menampilkan teks awalan
void playAnimation();         // Fungsi untuk memutar 15 frame animasi
void showBirthdayMessage();   // Fungsi teks ucapan ultah 
void showFinalImage();        // Fungsi untuk menampilkan epd_diraFace


#endif