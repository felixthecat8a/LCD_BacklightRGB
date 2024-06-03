// LCD_BacklightRGB.h v1.0.2
#ifndef LCD_BACKLIGHTRGB_H
#define LCD_BACKLIGHTRGB_H

class LCD_BacklightRGB {
private:
  int _redPin, _greenPin, _bluePin;
  const int minRGB = 0, maxRGB = 255;
  int clamp(int value);
public:
  LCD_BacklightRGB(int redPin, int greenPin, int bluePin);
  void begin();
  void setRGB(int red, int green, int blue);
  void setRed();
  void setGreen();
  void setBlue();
};

#endif
