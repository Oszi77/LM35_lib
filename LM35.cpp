
#include "LM35.h"

LM35::LM35(int aPin, bool showSerMonitor) {

   _show = showSerMonitor;
   _aPin = aPin;

}

void LM35::begin(int bandrate){
   Serial.begin(bandrate);
}

void LM35::getCelsius(){
  _cTemp = (_volt * 500) / 1023 ; //Feszültség érték -> Celziusz fok.
}

float LM35::readSensor() {
  float Vout = analogRead(_aPin) ;//Analóg pin beolvasása.
  _volt = Vout;
  getCelsius();

  if(_show){
    Serial.print("Szenzor kimeneti erteke = ");
    Serial.print(Vout);
    Serial.println();
    }
  
   return Vout;

}


float LM35::getTemperatureInCelsuis() {
   float cTemp = _cTemp;

  if(_show){
    Serial.print("Homerseklet celziusz fokban = ");
    Serial.print(cTemp);
    Serial.print(" C");
    Serial.println();
    }
  
  return cTemp;
}

/*
float LM35::getTemperatureInFarenheit(){
  float fTemp = (getTemperatureInCelsuis());

  if(_show){
    Serial.print("Hőmérséklet farenheit fokban =  ");
    Serial.print(fTemp . " F");
    Serial.println();
    }
  
  return fTemp;
}
*/

float LM35::getTemperatureInKelvin(){
    float kTemp = (_cTemp + 271);

   if(_show){
    Serial.print("Hőmérséklet kelvin fokban =  ");
    Serial.print(kTemp);
    Serial.print(" K");
    Serial.println();
    }
    
    return kTemp;
  }
