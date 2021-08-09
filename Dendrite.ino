/*
 * Dendrite.ino
 * Author: Connor Johnston
 * Date: 6/8/2021
 */

/* 
 *  Addressable LED Bundle, Side with 3 Branches, Bottom Branch
 *  DATA_PIN108 has 108 LEDs in the light strip
 */
#include "FastLED.h"

#define DATA_PIN108 A1
#define DATA_PIN145 A0
#define DATA_PIN143 A3
#define DATA_PIN105 A2
CRGB leds108[108];
CRGB leds145[145];
CRGB leds143[143];
CRGB leds105[105];
boolean once = true;

// Non-addressable LED Bundle, Side with 3 Branches, Middle Bundle
#define RED_LED_ThreeMid A4
#define GREEN_LED_ThreeMid A5
#define BLUE_LED_ThreeMid A6

// Non-addressable LED Bundle, Side with 3 Branches, Top Bundle
#define RED_LED_ThreeTop A7
#define GREEN_LED_ThreeTop A8
#define BLUE_LED_ThreeTop A9

// Non-addressable LED Bundle, Side with 2 Branches, Bottom Bundle
#define RED_LED_TwoBot A10
#define GREEN_LED_TwoBot A11
#define BLUE_LED_TwoBot A12

// Non-addressable LED Bundle, Side with 2 Branches, Top Bundle
#define RED_LED_TwoTop A13
#define GREEN_LED_TwoTop A14
#define BLUE_LED_TwoTop A15

// CONSTANTS
int brightness = 255;
int gBright = 0;
int rBright = 0;
int bBright = 0;
int fadeSpeed = 10;

// ARRAYS FOR NON-ADDRESSABLE LED BUNDLES
int redPins[] = {RED_LED_ThreeMid, RED_LED_TwoTop, RED_LED_ThreeTop, RED_LED_TwoBot};
int greenPins[] = {GREEN_LED_ThreeMid, GREEN_LED_TwoTop, GREEN_LED_ThreeTop, GREEN_LED_TwoBot};
int bluePins[] = {BLUE_LED_ThreeMid, BLUE_LED_TwoTop, BLUE_LED_ThreeTop, BLUE_LED_TwoBot};
int ArraySize = 4;

void setup() {
  // put your setup code here, to run once:

// Initialize addressable pins using FastLED library
FastLED.addLeds<NEOPIXEL,DATA_PIN108>(leds108,108);
FastLED.addLeds<NEOPIXEL,DATA_PIN145>(leds145,145);
FastLED.addLeds<NEOPIXEL,DATA_PIN143>(leds143,143);
FastLED.addLeds<NEOPIXEL,DATA_PIN105>(leds105,105);

/*
 * Initialize non-addressable pins that are controlled by 
 * logic level MOSFETS
 */
pinMode(GREEN_LED_ThreeTop, OUTPUT);
pinMode(RED_LED_ThreeTop, OUTPUT);
pinMode(BLUE_LED_ThreeTop, OUTPUT);

pinMode(GREEN_LED_TwoBot, OUTPUT);
pinMode(RED_LED_TwoBot, OUTPUT);
pinMode(BLUE_LED_TwoBot, OUTPUT);

pinMode(GREEN_LED_TwoTop, OUTPUT);
pinMode(RED_LED_TwoTop, OUTPUT);
pinMode(BLUE_LED_TwoTop, OUTPUT);

pinMode(GREEN_LED_ThreeMid, OUTPUT);
pinMode(RED_LED_ThreeMid, OUTPUT);
pinMode(BLUE_LED_ThreeMid, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

turnOnAddressableRandom();
randomColorNonAddressable(redPins, bluePins, greenPins);
turnOffAddressable();


//testAllRedGreenBlueNonAddressable(RED_LED_TwoTop, BLUE_LED_TwoTop, GREEN_LED_TwoTop);
//testOneRedGreenBlueNonAddressable(redPins, bluePins, greenPins);
}

/* 
 *  Turns on non-addressable LEDs to random color in RGB spectrum
 *  For each LED bundle, one color in the RGB spectrum is given a min
 *  value of 100 to ensure a bright enough color display
 *  
 */
void randomColorNonAddressable(int redPin[], int bluePin[], int greenPin[]){
    for(int i = 0; i<ArraySize; i++){
      int x = random(1,4);
      Serial.println(x);
      int rMin = 0;
      int bMin = 0;
      int gMin = 0;
      if(x==1)
      {
        rMin = 100;
      }
      else if (x==2)
      {
        bMin = 100;
      }
      else
      {
        gMin = 100;
      }
        
      analogWrite(redPin[i],random(rMin,256));
      analogWrite(bluePin[i],random(bMin,256));
      analogWrite(greenPin[i],random(gMin,256));
      delay(1000);
    } 
    for(int i = 0; i<ArraySize; i++){
      analogWrite(redPin[i],0);
      analogWrite(bluePin[i],0);
      analogWrite(greenPin[i],0);
      //delay(1000);
    } 
}


/*
 * Turns on addressable lights one at a time to a random color
 * For each LED in strip, one color in the RGB spectrum is given a min
 * value of 100 to ensure a bright enough color display
 */
void turnOnAddressableRandom()
{
  for(int dot=0 ; dot < 145 ; dot++){ 
    leds145[dot] = CRGB::Red;
    
    if(dot<=105)
    {
       leds105[dot] = CRGB::Red;
    }
    if(dot<=143)
    {
       leds143[dot] = CRGB::Red;
    }
    if(dot<=108)
    {
       leds108[dot] = CRGB::Red;
    }
    FastLED.show();
    delay(30);
    //Fuschia
    int x = random(1,4);
    int rMin = 0;
    int bMin = 0;
    int gMin = 0;
    if(x==1 && dot == 0)
    {
      rMin = 100;
    }
    else if (x==2 && dot == 0)
    {
      bMin = 100;
    }
    else
    {
      gMin = 100;
    }
    if (dot == 0)
    {
      int red = random(rMin,256);
      int green = random(gMin,256);
      int blue = random(bMin,256);
    }
     
    leds145[dot].setRGB(random(rMin,256),random(gMin,256),random(bMin,256));
    if(dot<=143)
    {
      int x = random(1,4);
    int rMin = 0;
    int bMin = 0;
    int gMin = 0;
    if(x==1)
    {
      rMin = 100;
    }
    else if (x==2)
    {
      bMin = 100;
    }
    else
    {
      gMin = 100;
    }
      //Limegreen
      leds143[dot].setRGB(random(rMin,256),random(gMin,256),random(bMin,256));
    }
    if(dot<=105)
    {
      int x = random(1,4);
    int rMin = 0;
    int bMin = 0;
    int gMin = 0;
    if(x==1)
    {
      rMin = 100;
    }
    else if (x==2)
    {
      bMin = 100;
    }
    else
    {
      gMin = 100;
    }
       //Coral
       leds105[dot].setRGB(random(rMin,256),random(gMin,256),random(bMin,256));
    }
    if(dot<=108)
    {
      int x = random(1,4);
    int rMin = 0;
    int bMin = 0;
    int gMin = 0;
    if(x==1)
    {
      rMin = 100;
    }
    else if (x==2)
    {
      bMin = 100;
    }
    else
    {
      gMin = 100;
    }
       //Gold
       leds108[dot].setRGB(random(rMin,256),random(gMin,256),random(bMin,256));
    }
    FastLED.show(); 
  }
}

/*
 * Turns on addressable lights one at a time to a single solid color
 */
void turnOnAddressableSolidColor()
{
  for(int dot=0 ; dot < 145 ; dot++){ 
    leds145[dot] = CRGB::Red;
    
    if(dot<=105)
    {
       leds105[dot] = CRGB::Red;
    }
    if(dot<=143)
    {
       leds143[dot] = CRGB::Red;
    }
    if(dot<=108)
    {
       leds108[dot] = CRGB::Red;
    }
    FastLED.show();
    delay(30);
    //Fuschia
    leds145[dot].setRGB(255,0,255);
    if(dot<=143)
    {
      //Limegreen
      leds143[dot].setRGB(127,255,0);
    }
    if(dot<=105)
    {
       //Coral
       leds105[dot].setRGB(255,127,80);
    }
    if(dot<=108)
    {
       //Gold
       leds108[dot].setRGB(218,165,32);
    }
    FastLED.show(); 
  }
}

/*
 * Turns off addressable lights one at a time (like snake)
 */
void turnOffAddressable(){
  for(int dot=0 ; dot < 145 ; dot++)
{ 
  leds145[dot] = CRGB::Black;
  if(dot<=105)
  {
     leds105[dot] = CRGB::Black;
  }
  if(dot<=108)
  {
     leds108[dot] = CRGB::Black;
  } 
  if(dot<=143)
  {
     leds143[dot] = CRGB::Black;
  } 
  delay(30);
  FastLED.show();
}
}

/*
 * Turns all non-addressable lights Red, then Green, then Blue
 * Used to test whether all RGB pins were assigned to the correct pin RGB pin
 */
void testAllRedGreenBlueNonAddressable(int redPin[], int bluePin[], int greenPin[]){
    for(int i = 0; i<ArraySize; i++){
      analogWrite(redPin[i],brightness);
      
      if(i==ArraySize-1)
      {
        delay(2000);
        for(int j = 0; j<ArraySize; j++){
          analogWrite(redPin[j],0);
        }
      }
    }

    for(int i = 0; i<ArraySize; i++){
      analogWrite(greenPin[i],brightness);
      
      if(i==ArraySize-1)
      {
        delay(2000);
        for(int j = 0; j<ArraySize; j++){
          analogWrite(greenPin[j],0);
        }
      }
    }

    for(int i = 0; i<ArraySize; i++){
      analogWrite(bluePin[i],brightness);
      
      if(i==ArraySize-1)
      {
        delay(2000);
        for(int j = 0; j<ArraySize; j++){
          analogWrite(bluePin[j],0);
        }
      }
    }
}

/* 
 *  Test code for testing RGB of each non-addressable LED strip
 *  Code tests one strip at a time, and one color at a time
 *  Was used to check that connections on each light were secure
 */
void testOneRedGreenBlueNonAddressable(int redPin[], int bluePin[], int greenPin[]){
    for(int i = 0; i<ArraySize; i++){
      analogWrite(redPin[i],255);
      delay(1000);
      analogWrite(redPin[i],0);
      analogWrite(greenPin[i],255);
      delay(1000);
      analogWrite(greenPin[i],0);
      analogWrite(bluePin[i],255);
      delay(1000);
      analogWrite(bluePin[i],0);
    } 
}
