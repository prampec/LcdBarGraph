#include <LiquidCrystal.h>
#include <LcdBarGraph.h>

byte lcdNumCols = 16; // -- number of columns in the LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // -- creating LCD instance
// -- creating a 4 chars wide bars
LcdBarGraph lbg0(&lcd, 4, 0, 0); // -- First line at column 0
LcdBarGraph lbg1(&lcd, 4, 5, 0); // -- First line at column 5
LcdBarGraph lbg2(&lcd, 4, 10, 0); // -- First line at column 10
LcdBarGraph lbg3(&lcd, 4, 0, 1); // -- Second line at column 0
LcdBarGraph lbg4(&lcd, 4, 5, 1);  // -- Second line at column 5
LcdBarGraph lbg5(&lcd, 4, 10, 1); // -- Second line at column 0

byte i0 = 0;
byte i1 = 0;
byte i2 = 0;
byte i3 = 0;
byte i4 = 0;
byte i5 = 0;

void setup(){
  // -- initializing the LCD
  lcd.begin(2, lcdNumCols);
  lcd.clear();
  // -- do some delay: some time I've got broken visualization
  delay(100);
}

void loop()
{
  // -- draw bar graph from the analog value readed
  lbg0.drawValue( i0, 255);
  lbg1.drawValue( i1, 255);
  lbg2.drawValue( i2, 255);
  lbg3.drawValue( i3, 255);
  lbg4.drawValue( i4, 255);
  lbg5.drawValue( i5, 255);
  // -- do some delay: frequent draw may cause broken visualization
  delay(100);
  
  i0 += 5;
  i1 += 7;
  i2 += 9;
  i3 += 11;
  i4 += 13;
  i5 += 15;
}
