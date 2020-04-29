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
byte STATE_2 = 0;

void setup() {
  arduboy.begin();
  
  arduboy.setFrameRate(FRAME_RATE);
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.clear();

  arduboy.setCursor(x,y);

  if (arduboy.pressed(A_BUTTON)) {
    STATE = false;
  } else if (arduboy.pressed(B_BUTTON)) {
    STATE = true;
  }

  if (arduboy.pressed(UP_BUTTON)) {
    STATE_2 = 0;
  } else if (arduboy.pressed(LEFT_BUTTON)) {
    STATE_2 = 1;
  } else if (arduboy.pressed(RIGHT_BUTTON)) {
    STATE_2 = 2;
  } else if (arduboy.pressed(DOWN_BUTTON)) {
    STATE_2 = 3;
  }

  if (STATE) {
    arduboy.print(F("Do Not Disturb"));
    arduboy.setCursor(x,y+y);
    switch (STATE_2) {
      case 0:
        arduboy.print(F("In Class"));
        break;
      case 1:
        arduboy.print(F("In Call/Conference"));
        break;
      case 2:
        arduboy.print(F("Test Taking"));
        break;
      case 3:
        arduboy.print(F("Busy"));
        break;
      default:
        arduboy.print(F("In Call/Conference"));
    }
  } else {
    arduboy.print(F("Open"));
  }
  
  arduboy.display();
}
