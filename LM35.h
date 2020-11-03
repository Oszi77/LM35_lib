/*
* Mindig kötelező definiálni egy a könyvtár számára az IDE miatt.
* Ez esetünkben az. lm35.
* 
* Szükséges még a megfelelő működéshez az Arduino.h könyvtár újabb
* verziók esetében vagy régebbi verziók esetén a WProgram.h osztály
* könyvtár.
* 
*/

#ifndef lm
#define lm

#if(ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

//Deffiniáljuk az osztály könyvtárat.
class LM35 {
  
  public:
    //Konstruktor
    LM35(int aPin, bool showSerMonitor = false);

   //Metódus
   void  begin(int bandrate = 9600);
   
   float readSensor();
   float getTemperatureInCelsuis();
   //float getTemperatureInFarenheit();
   float getTemperatureInKelvin();
    
  private:
    //Mutatás a soros monitoron.
    bool _show;
    //Analóg láb
    int _aPin;
    //szenzor feszültség.
    float _volt;
    //Fok celzusz érték.
    float _cTemp;

    //Celzusz fok metódus.
    void getCelsius();
  };






#endif
