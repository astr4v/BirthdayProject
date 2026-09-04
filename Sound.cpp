#include "sound.h"
#include "config.h"

void initSound() {
  pinMode(Pin_buzzer, OUTPUT);
}

void playHappyBirthday() {
// Nada dasar: C4 C4 D4 C4 F4 E4
  int nada[] = {262, 262, 294, 262, 349, 330}; 
  int durasi[] = {250, 250, 500, 500, 500, 1000};
  
  for(int i = 0; i < 6; i++) {
    tone(Pin_buzzer, nada[i]);
    delay(durasi[i]);
    noTone(Pin_buzzer);
    delay(50); // Jeda kecil antar nada
  }
}

void stopSound() {
  noTone(Pin_buzzer);
}