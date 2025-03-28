#include "temperature_system.h"
#include "Arduino.h"
#include "main.h"


void init_temperature_system(void)
{
  //config the pins for the temp sys
  pinMode(HEATER,OUTPUT);
  pinMode(COOLER,OUTPUT);

  pinMode(TEMPERATURE_SENSOR,INPUT);
    
}

float read_temperature(void)
{
   //read the temp from temp sensor & return temp
   float temperature;
   temperature = (((analogRead(TEMPERATURE_SENSOR) *(float)5/1024))/(float)0.01);
   return temperature;
}

// to turn on & off the cooler
void cooler_control(bool control)
{
  if(control){
    digitalWrite(COOLER, HIGH);
  }
  else{
    digitalWrite(COOLER, LOW);
  }
}
void heater_control(bool control)
{
  if(control){
    digitalWrite(HEATER, HIGH);
  }
  else{
    digitalWrite(HEATER, LOW);
  }
}
