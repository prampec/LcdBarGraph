/**
 * File: Timer.ino
 * Description:
 * Usage of LcdBarGraph with (unsigned long). Basic overhead, useful when dealing with milliseconds.
 *
 * Author: Wilfried Loche
 * Contact: wloche@hotmail.com
 * Copying permission statement: This file is part of LcdBarGraph.
 */

#include <LiquidCrystal.h>
#include <LcdBarGraph.h>

byte lcdNumCols = 16; // -- number of columns in the LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // -- creating LCD instance
LcdBarGraph lbg(&lcd, lcdNumCols);     // -- creating the BarGraph instance

unsigned long duration = 60000; // 1 minute
unsigned long shootingStartedMillis  = 0;

void setup()
{
  // -- initializing the LCD
  lcd.begin(2, lcdNumCols);
  lcd.clear();
  // -- do some delay: some time I've got broken visualization
  delay(100);
  // -- initializing the start time
  shootingStartedMillis = millis();
}

void loop() 
{
  unsigned long currentMillis = millis();
  if ((unsigned long)(currentMillis - shootingStartedMillis) > duration) {
    //--- Duration's over: exit
    exit(0);
  }

  // -- draw bar graph from the analog value readed
  lbg.drawValue((unsigned long)(currentMillis - shootingStartedMillis), duration);
  // -- do some delay: frequent draw may cause broken visualization
  delay(100);
}
