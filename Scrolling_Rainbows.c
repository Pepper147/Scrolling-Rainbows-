#include <FastLED.h>

#include <LEDMatrix.h>
//*************************************************************************************************
//
//  RainbowDiagonalScroll();   Function that will have the leds start in the top left corner and scroll towards the bottom right corner.
//                             Note: The code for this function looks a little messy (lots of repeating commands).  What i tried to accomplish is 
//                                   to come up with some variable that will subtract the x value by a constantly increasing number 
//                                   rather than having to manually type in numarical values each time
//                                   
//  RainbowStripes();         Function that will divide the matrix into 4 (or more) sections of scrolling stripes.  some of the stripes will be s
//                            crolling to the Right while others will scroll to the left
//                            NOTE: What i am trying to dd to this function is something simular to the "Rain" animation where the LEDS start 
//                            beond the bowndries of the Matrix (i.e the stripes scrolling to the right will start at a negative X value)
//                            I would also like to have it so that the stripes are traveling at different speeds and so that multiple stripes 
//                            will be flying across the screen at once, rather then having them switch between scrolling left and right.  
//  
//
//*************************************************************************************************

#define LED_PIN        7
#define COLOR_ORDER    GRB
#define CHIPSET        WS2812B

#define MATRIX_WIDTH   24  // Set this negative if physical led 0 is opposite to where you want logical 0
#define MATRIX_HEIGHT  20  // Set this negative if physical led 0 is opposite to where you want logical 0
#define NUM_LEDS MATRIX_WIDTH * MATRIX_HEIGHT
#define MATRIX_TYPE    HORIZONTAL_ZIGZAG_MATRIX  // See top of LEDMatrix.h for matrix wiring types

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;

int angle = 0;
int BlankSpaceNum = 24;
int gBlankSpace[24];

void setup()
{
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.setBrightness(45);
 // set_max_power_in_volts_and_milliamps(5, 12000);       
  //Safety procotion, stating that i am using 5V 12A power supply (Max)
  Serial.begin(9600);
  Serial.println("The rogram has started");
  FastLED.clear(true);
  delay(500);
  FastLED.showColor(CRGB::Lime);
  delay(1000);
}


void loop(){
  
 // RainbowDiagonalScroll();
  RainbowStripes();
}

void fadeall(){
  for(int i = 0; i <= NUM_LEDS; i++){
    leds(i).nscale8(244);
  }
}

void RainbowDiagonalScroll(){
  int hue = sin8(angle);

  for(int x = 0; x <= leds.Width() * 2; x++)
  {
    leds(x,     0) = CHSV(hue, 255, 255); 
    leds(x - 1, 1) = CHSV(hue, 255, 255); 
    leds(x - 2, 2) = CHSV(hue, 255, 255); 
    leds(x - 3, 3) = CHSV(hue, 255, 255); 
    leds(x - 4, 4) = CHSV(hue, 255, 255); 
    leds(x - 5, 5) = CHSV(hue, 255, 255); 
    leds(x - 6, 6) = CHSV(hue, 255, 255); 
    leds(x - 7, 7) = CHSV(hue, 255, 255); 
    leds(x - 8, 8) = CHSV(hue, 255, 255); 
    leds(x - 9, 9) = CHSV(hue, 255, 255); 
    leds(x - 10, 10) = CHSV(hue, 255, 255); 
    leds(x - 11, 11) = CHSV(hue, 255, 255); 
    leds(x - 12, 12) = CHSV(hue, 255, 255); 
    leds(x - 13, 13) = CHSV(hue, 255, 255); 
    leds(x - 14, 14) = CHSV(hue, 255, 255); 
    leds(x - 15, 15) = CHSV(hue, 255, 255); 
    leds(x - 16, 16) = CHSV(hue, 255, 255); 
    leds(x - 17, 17) = CHSV(hue, 255, 255); 
    leds(x - 18, 18) = CHSV(hue, 255, 255); 
    leds(x - 19, 19) = CHSV(hue, 255, 255); 
    leds(x - 20, 20) = CHSV(hue, 255, 255);  
    
    fadeall();
    hue+=7;
    angle+=4;
    FastLED.delay(25);
  }
}

void RainbowStripes(){
  int hue = sin8(angle);

  for(int xRight = 0; xRight <= leds.Width() * 2; xRight++)
  {
    leds(xRight,     0) = CHSV(hue, 255, 255);         //Rows 0 - 4 slide to the right 
    leds(xRight - 1, 1) = CHSV(hue, 255, 255); 
    leds(xRight - 2, 2) = CHSV(hue, 255, 255); 
    leds(xRight - 3, 3) = CHSV(hue, 255, 255); 
    leds(xRight - 4, 4) = CHSV(hue, 255, 255); 

    leds(xRight - 10, 10) = CHSV(hue, 255, 255);      //Rows 10 - 14 slide to the right 
    leds(xRight - 11, 11) = CHSV(hue, 255, 255); 
    leds(xRight - 12, 12) = CHSV(hue, 255, 255); 
    leds(xRight - 13, 13) = CHSV(hue, 255, 255); 
    leds(xRight - 14, 14) = CHSV(hue, 255, 255); 

    leds(xRight - 20, 20) = CHSV(hue, 255, 255);      //Rows 20 - 24 slide to the right 
    leds(xRight - 21, 21) = CHSV(hue, 255, 255); 
    leds(xRight - 22, 22) = CHSV(hue, 255, 255); 
    leds(xRight - 23, 23) = CHSV(hue, 255, 255); 
    leds(xRight - 24, 24) = CHSV(hue, 255, 255); 
    
  for(int i = 0; i <= NUM_LEDS; i++)
  {
    leds(i).nscale8(250);
  }
    hue+=7;
    angle+=4;
    FastLED.delay(25);
  }
//**************************************************************************************************
  for(int xLeft = leds.Width() * 2; xLeft >= 0; xLeft--)
  {
    leds(xLeft - 5, 5) = CHSV(hue, 255, 255);         //Rows 5 - 9 slide to the Left 
    leds(xLeft - 6, 6) = CHSV(hue, 255, 255); 
    leds(xLeft - 7, 7) = CHSV(hue, 255, 255); 
    leds(xLeft - 8, 8) = CHSV(hue, 255, 255); 
    leds(xLeft - 9, 9) = CHSV(hue, 255, 255); 
    
    leds(xLeft - 15, 15) = CHSV(hue, 255, 255);       //Rows 15 - 19 slide to the LEft 
    leds(xLeft - 16, 16) = CHSV(hue, 255, 255); 
    leds(xLeft - 17, 17) = CHSV(hue, 255, 255); 
    leds(xLeft - 18, 18) = CHSV(hue, 255, 255); 
    leds(xLeft - 19, 19) = CHSV(hue, 255, 255); 

    fadeall();
    hue+=7;
    angle+=4;
    FastLED.delay(25);
  }
}

  
