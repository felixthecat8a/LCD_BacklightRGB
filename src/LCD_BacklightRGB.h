// LCD_BacklightRGB.h
#ifndef LCD_BACKLIGHTRGB_H
#define LCD_BACKLIGHTRGB_H

class LCD_BacklightRGB {
private:
    int _redPin, _greenPin, _bluePin;
public:
    LCD_BacklightRGB(int redPin, int greenPin, int bluePin);
    void begin();
    void setRGB(int red, int green, int blue);
};

#endif
