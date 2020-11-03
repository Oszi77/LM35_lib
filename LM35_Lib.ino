#include <TM1637Display.h>
#include "LM35.h"

#define CLK 2//Órajel láb
#define DIO 3//Digitális ki-, bemenet kommunikáció láb.
#define SEN A0

const byte DEGREE = SEG_A | SEG_B | SEG_G | SEG_F; // fok jel szegmensrajzolata - o
const byte CELSIUS = SEG_A | SEG_F | SEG_E | SEG_D; // C- betű szegmensrajzolata

byte data[] = {0, 0, 0, 0}; // adattár a kiíráshoz

TM1637Display display(CLK, DIO);//Objektum példányosítása.
LM35 lm35(SEN, false);

void setup() {
   lm35.begin();
   display.setBrightness(0x0F);//Kijelző max. fényerőn.
}

void loop() {
  lm35.readSensor();
  float t = lm35.getTemperatureInCelsuis();// hőmérséklet kiolvasása (Celsius)
  int tempC = int(t + 0.5); // egészre kerekítünk
  int d1 = tempC%10; // egyesek
  int d0 = (tempC/10)%10; // tízesek

  data[0] = display.encodeDigit(d0); // szegmensrajzolat elővétele
  data[1] = display.encodeDigit(d1); // szegmensrajzolat elővétele
  data[2] = DEGREE; // fok jel
  data[3] = CELSIUS; // nagy C szegmensei
    
  display.setSegments(data); // a szegmensek megjelenítése

  delay(300);




  
  //lm35.getTemperatureInKelvin();
  //Serial.println("----------------------------------");
  //Serial.println();
}
