/*
   DoorSign.ino
   @TheBitStick
   Do Not Disturb Door Sign for Arduboy
   Uses Arduboy2 library
*/

#include <Arduboy2.h>

Arduboy2 arduboy;

#define FRAME_RATE 15

byte x = 6;
byte y = 9;
bool STATE = false;
bool STATE_2 = true;

void setup() {
  arduboy.begin();
  
  arduboy.setFrameRate(FRAME_RATE);
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.clear();

  arduboy.setCursor(x,y);

  if (arduboy.pressed(A_BUTTON)) {
    STATE = true;
  } else if (arduboy.pressed(B_BUTTON)) {
    STATE = false;
    STATE_2 = !STATE_2;
  }
  
  if (STATE) {
    arduboy.print(F("Do Not Disturb"));
    arduboy.setCursor(x,y+y);
    if (STATE_2) {
      arduboy.print(F("In Call/Conference"));
    } else {
      arduboy.print(F("Test Taking"));
    }
  } else {
    arduboy.print(F("Open"));
  }
  
  arduboy.display();
}
