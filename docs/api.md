# LCD_BacklightRGB

## Methods

### `LCD_BacklightRGB()`

#### Description

The constructor for the **LCD_BacklightRGB** class initializes an object that controls the RGB backlight of an LCD. It requires specifying the Arduino pins connected to the red, green, and blue components of the backlight.

#### Syntax

```
LCD_BacklightRGB(redPin, greenPin, bluePin)
```

#### Parameters
redPin: the number of the Arduino pin that is connected to the red pin on the RGB LCD module (pin 16)

greenPin: the number of the Arduino pin that is connected to the red pin on the RGB LCD module (pin 17)

bluePin: the number of the Arduino pin that is connected to the red pin on the RGB LCD module (pin 18)

### `begin()`

#### Description

The **begin()** method initializes the RGB backlight for operation. This method sets up the pins specified in the constructor as outputs and prepares the backlight for further commands like setting colors and brightness. Note: Ensure you call begin() in your setup() function before using any other methods from the LCD_BacklightRGB class.

#### Syntax

```
backlight.begin()
```

#### Parameters
backlight: An instance of the LCD_BacklightRGB class. This parameter implicitly refers to the object you’re working with.

#### Example

```ino
#include <LiquidCrystal.h>
#include <LCD_BacklightRGB.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LCD_BacklightRGB backlight(6, 9, 10);

void setup()
{
  lcd.begin(16,1);
  backlight.begin();
  lcd.print("hello, world!");
}

void loop() {}
```

### `setBrightness()`

#### Description

The setBrightness() method adjusts the brightness of the LCD backlight by modifying the intensity of the red, green, and blue components simultaneously. This allows for dimming or brightening the backlight as needed. Note: This method does not change the current color of the backlight but scales the intensity of the color based on the provided brightness value.

#### Syntax

```
backlight.setBrightness(brightness)
```

#### Parameters

backlight: An instance of the LCD_BacklightRGB class.

brightness: The desired brightness level for the LCD backlight. This value should be an integer in the range of 0 (completely off) to 255 (maximum brightness).

### `setRGB()`

#### Description

The setRGB() method sets the color of the LCD backlight. It optionally allows you to adjust the brightness of the color simultaneously.

#### Syntax

```
backlight.setRGB(red, green, blue)
backlight.setRGB(red, green, blue, brightness)
```

#### Parameters

backlight: An instance of the LCD_BacklightRGB class.

red: The intensity of the red component, specified as an integer in the range of 0 (off) to 255 (full intensity).

green: The intensity of the green component, specified as an integer in the range of 0 (off) to 255 (full intensity).

blue: The intensity of the blue component, specified as an integer in the range of 0 (off) to 255 (full intensity).

brightness: The desired brightness level for the LCD backlight in the range of 0 (completely off) to 255 (maximum brightness).

#### Example

```ino
// Set the backlight to pure blue
backlight.setRGB(0, 0, 255);
lcd.print("Color: Orange");
```
```ino
// Set the backlight to orange with 50% brightness
backlight.setRGB(255, 165, 0, 128);
lcd.print("Color: Orange");
```

### `off()`

#### Description

The off() method turns off the LCD backlight by setting all RGB components to zero, effectively disabling the light. 

#### Syntax

```
backlight.off()
```

#### Parameters

backlight: An instance of the LCD_BacklightRGB class.


### `setWhite()`

#### Description

The setWhite() method sets the LCD backlight color to white by assigning maximum intensity to the red, green, and blue components. Optionally, you can specify a brightness level to adjust the intensity of the white light.

#### Syntax

```
backlight.setWhite()
backlight.setWhite(brightness)
```

#### Parameters

backlight: An instance of the LCD_BacklightRGB class.

brightness (optional): The desired brightness level for the LCD backlight in the range of 0 (completely off) to 255 (maximum brightness).

### `setRed()`

#### Description

The setRed() method sets the LCD backlight color to red by assigning the RGB components the values of **(255, 0, 0)**. Optionally, you can specify a brightness value.

#### Syntax

```cpp
backlight.setRed()
backlight.setRed(brightness)
```
#### Parameters

backlight: An instance of the LCD_BacklightRGB class.

brightness (optional): The desired brightness level for the LCD backlight in the range of 0 (completely off) to 255 (maximum brightness).

### `setGreen()`

#### Description

The setGreen() method sets the LCD backlight color to green by assigning the RGB components the values of **(0, 255, 0)**. Optionally, you can specify a brightness value.

#### Syntax

```cpp
backlight.setGreen()
backlight.setGreen(brightness)
```
#### Parameters

backlight: An instance of the LCD_BacklightRGB class.

brightness (optional): The desired brightness level for the LCD backlight in the range of 0 (completely off) to 255 (maximum brightness).

### `setBlue()`

#### Description

The setBlue() method sets the LCD backlight color to blue by assigning the RGB components the values of **(0, 0, 255)**. Optionally, you can specify a brightness value.

#### Syntax

```cpp
backlight.setBlue()
backlight.setBlue(brightness)
```
#### Parameters

backlight: An instance of the LCD_BacklightRGB class.

brightness (optional): The desired brightness level for the LCD backlight in the range of 0 (completely off) to 255 (maximum brightness).

### `setYellow()`

#### Description

The setYellow() method sets the LCD backlight color to yellow by assigning the RGB components the values of **(255, 255, 0)**. Optionally, you can specify a brightness value.

#### Syntax

```cpp
backlight.setYellow()
backlight.setYellow(brightness)
```
#### Parameters

backlight: An instance of the LCD_BacklightRGB class.

brightness (optional): The desired brightness level for the LCD backlight in the range of 0 (completely off) to 255 (maximum brightness).

### `setCyan()`

#### Description

The setCyan() method sets the LCD backlight color to cyan by assigning the RGB components the values of **(0, 255, 255)**. Optionally, you can specify a brightness value.

#### Syntax

```cpp
backlight.setCyan()
backlight.setCyan(brightness)
```
#### Parameters

backlight: An instance of the LCD_BacklightRGB class.

brightness (optional): The desired brightness level for the LCD backlight in the range of 0 (completely off) to 255 (maximum brightness).

### `setMagenta()`

#### Description

The setMagenta() method sets the LCD backlight color to magenta by assigning the RGB components the values of **(255, 0, 255)**. Optionally, you can specify a brightness value.

#### Syntax

```cpp
backlight.setMagenta()
backlight.setMagenta(brightness)
```
#### Parameters

backlight: An instance of the LCD_BacklightRGB class.

brightness (optional): The desired brightness level for the LCD backlight in the range of 0 (completely off) to 255 (maximum brightness).