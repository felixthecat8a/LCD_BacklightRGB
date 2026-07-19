#include <LiquidCrystal.h>
#include <LCD_BacklightRGB.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
LCD_BacklightRGB display(lcd, 3, 5, 6);

void setup() {
  display.lcdBegin(16, 2);
  display.begin();

  display.setGreen();
  display.print("Hello World!");
}

void loop() {}
