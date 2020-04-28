// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <math.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif



// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            7
#define COPIN    A0

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGBW + NEO_KHZ800);

int neodelayval = 500; // delay for half a second
int neodelayval2 = 20; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
//#if defined (__AVR_ATtiny85__)
//  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
//#endif
//  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(115200);
  Serial.println("sensor demo!");
  
}



void showBlue(int x) {   //x between 0 and 20
    for(int i=0;i<x;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,150, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(neodelayval2); // Delay for a period of time (in milliseconds).

  }
}

void showGreen(int x) {   //x between 0 and 20
    for(int i=0;i<x;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(200,0,0, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(neodelayval2); // Delay for a period of time (in milliseconds).

  }
}

void allWhite() {   //white out
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0, 20)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(10); // Delay for a period of time (in milliseconds).

  }
   for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(10); // Delay for a period of time (in milliseconds).

  }
}

void allGreen() {   //green out
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(200,0,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

  }
  delay(10); // Delay for a period of time (in milliseconds).
}


void allRed() {   //blue out
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

  }
  delay(10); // Delay for a period of time (in milliseconds).
}

void allBlue() {   //green out
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,150,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

  }
  delay(10); // Delay for a period of time (in milliseconds).
}


void blank() {   //blank out
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0, 0)); // Moderately bright green color.

    delay(5); // Delay for a period of time (in milliseconds).

  }
   pixels.show(); // This sends the updated pixel color to the hardware.
}


void showRed(int x) {   //x between 0 and 20
    for(int i=0;i<x;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(neodelayval2); // Delay for a period of time (in milliseconds).

  }
}

void showOrange(int x) {   //x between 0 and 20
    for(int i=0;i<x;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(50,210,0, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(neodelayval2); // Delay for a period of time (in milliseconds).

  }
}


void showYellow(int x) {   //x between 0 and 20
    for(int i=0;i<x;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(200,200,0, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(neodelayval2); // Delay for a period of time (in milliseconds).

  }
}

void showPurple(int x) {   //x between 0 and 20
    for(int i=0;i<x;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,150, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(neodelayval2); // Delay for a period of time (in milliseconds).

  }
}


void showTeal(int x) {   //x between 0 and 20
    for(int i=0;i<x;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(150,0,150, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(neodelayval2); // Delay for a period of time (in milliseconds).

  }
}

void testPixels() {
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(200,0,0, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(neodelayval); // Delay for a period of time (in milliseconds).

  }

    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,150, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(neodelayval); // Delay for a period of time (in milliseconds).

  }
}


void loop() {

//  allWhite();
//  showGreen(14);
//  blank();
//  showRed(10);
//  blank();
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  delay(500);
  blank();
  //testPixels();
  float reading = floor(16.0 * (analogRead(COPIN)/1023.0)); 
  Serial.println(reading);
  Serial.println(analogRead(COPIN));
  

  //show CO as orange
  showOrange(int(reading));
  //showPurple(int(reading));
  if (reading > 4.0) { 
    allRed();
    delay(200);
    blank();
    delay(200);
    allRed();
    delay(200);
    blank();    
  }
  
  delay(500);
  delay(2000);
  allWhite();
// indoor air quality
//  reading = floor(16.0 * (INDOORAIRQUALITY/300.0)); 
//  Serial.println(reading);
//  
  showTeal(int(reading));
  
  delay(500);
  delay(2000);
  allWhite();
  
// temperature
//  reading = floor(16.0 * ((TEMPERATURE+20.0)/90.0)); 
//  Serial.println(reading);
//  
  showRed(int(reading));
  
  delay(500);
  delay(2000);
 
  allWhite();

  // humidity
//  reading = floor(16.0 * ((HUMIDITY)/100.0)); 
//  Serial.println(reading);
//  
  showBlue(int(reading));
  
  delay(500);
  delay(2000);
 
  allWhite();

  // PM1.0
//  reading = ceil(16.0 * ((PM1.0)/900.0)); 
//  Serial.println(reading);
//  
  showPurple(int(reading));
  
  delay(500);
  delay(2000);
 
  allWhite();


    // PM2.5
//  reading = ceil(16.0 * ((PM2.5)/300.0)); 
//  Serial.println(reading);
//  
  showYellow(int(reading));

  delay(500);
  delay(2000);
 

  if (reading > 10.0) { 
    allRed();
    delay(200);
    blank();
    delay(200);
    allRed();
    delay(200);
    blank();    
  } else {
    allGreen();
    delay(200);
    blank();
    delay(200);
    allGreen();
    delay(200);
    blank();
  }

  delay(500);

  allWhite();


}

