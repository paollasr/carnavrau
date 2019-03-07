#include "Arduino.h"
#include <avr/interrupt.h>
#include <avr/sleep.h>

volatile boolean ledOn = false;

void setup() {

  Serial.begin(9600);
  
  pinMode(13,OUTPUT);
  //ISR Button - Triggering Interrupt Function
  pinMode(2,INPUT);
   //ISR function(digPIN2, function, SignalMode)
  attachInterrupt(0,PinInterrupt,RISING); 
 
}

void loop() {
 

if (ledOn == false){
  Serial.println(F("going to sleep"));
   sleepSetupMCU();
  
  }
  else {
    
  Serial.println ("awake");
    }

}


void sleepSetupMCU()
{
  sleep_enable(); 
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
 
  sleep_cpu(); //(SE)bit is enable. MCU goes sleep
//Stops to execute the function

  
  }

void PinInterrupt()
{
    sleep_disable();
 
  if(ledOn)
  {
    ledOn = false;
    digitalWrite(13,LOW);
  }else
  {
    ledOn = true;
    digitalWrite(13,HIGH); 
 }

}
