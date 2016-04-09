#include "CMMCSnakeGameWS.h"

//===========================================================
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <ESP_Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
//===========================================================

//

void GameLoop();

int GameFPS = 25;
GameInterval GameInterval(1000 / GameFPS, GameLoop);

int iInput1Pin = 0;
int iInput2Pin = 13;

int iInputUpPin = 12;
int iInputDownPin = 14;
int iInputLeftPin = 3;
int iInputRightPin = 1;


//

void setup()   {
  Serial.begin(9600);

  //===========================================================
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  //display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.begin(SSD1306_SWITCHCAPVCC, 0x78 >> 1);
  // init done

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);
  display.clearDisplay();
  //===========================================================

  pinMode(iInput1Pin, INPUT_PULLUP);
  pinMode(iInput2Pin, INPUT_PULLUP);

  pinMode(iInputUpPin, INPUT_PULLUP);
  pinMode(iInputDownPin, INPUT_PULLUP);
  pinMode(iInputLeftPin, INPUT_PULLUP);
  pinMode(iInputRightPin, INPUT_PULLUP);

}

void loop() {
  GameInterval.update();
}

//===========================================================

void GameLoop()
{
  GameUpdate();
  GameDraw();
}

String sBtn[] = {"Off", "On"};

byte bModeState = 0;
byte bBtnState = 0;

byte bInput1BuffRead = HIGH;
byte bInput2BuffRead = HIGH;

bool iInputUpState = false;
bool iInputDownState = false;
bool iInputLeftState = false;
bool iInputRightState = false;

void GameUpdate()
{
  if (GameInput::getKey(iInputUpPin, LOW))
  {
    iInputUpState = HIGH;
  } else {
    iInputUpState = LOW;
  }

  if (GameInput::getKey(iInputDownPin, LOW))
  {
    iInputDownState = HIGH;
  } else {
    iInputDownState = LOW;
  }

  if (GameInput::getKey(iInputLeftPin, LOW))
  {
    iInputLeftState = HIGH;
  } else {
    iInputLeftState = LOW;
  }

  if (GameInput::getKey(iInputRightPin, LOW))
  {
    iInputRightState = HIGH;
  } else {
    iInputRightState = LOW;
  }

}

void GameDraw()
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.setTextColor(BLACK, WHITE);
  display.println("Button Key");
  display.println();

  display.setTextColor(BLACK, WHITE);
  display.print("Key Up   ");
  display.setTextColor(WHITE);
  display.println(" " + ((String)sBtn[iInputUpState]));

  display.setTextColor(BLACK, WHITE);
  display.print("Key Down ");
  display.setTextColor(WHITE);
  display.println(" " + ((String)sBtn[iInputDownState]));

  display.setTextColor(BLACK, WHITE);
  display.print("Key Left ");
  display.setTextColor(WHITE);
  display.println(" " + ((String)sBtn[iInputLeftState]));

  display.setTextColor(BLACK, WHITE);
  display.print("Key Right");
  display.setTextColor(WHITE);
  display.println(" " + ((String)sBtn[iInputRightState]));

  display.display();
}


