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

void setup() {
  arduboy.begin();
  
  arduboy.setFrameRate(FRAME_RATE);
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.clear();

  arduboy.setCursor(x,y);

  if (arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON)) {
    STATE = !STATE;
  }
  
  if (STATE) {
    arduboy.print(F("Do Not Disturb"));
    arduboy.setCursor(x,y+y);
    arduboy.print(F("In Call"));
  } else {
    arduboy.print(F("Open"));
  }
  
  arduboy.display();
}
