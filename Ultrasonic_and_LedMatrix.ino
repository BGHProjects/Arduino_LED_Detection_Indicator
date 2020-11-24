
#include "LedControl.h"
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

//DIN is Pin 7
//CS is Pin 6
//CLK is Pin 5

LedControl lc = LedControl(7,5,6,1);


void setup() {
  // put your setup code here, to run once:

  //setup SR04
  Serial.begin(9600);
  delay(1000);

  //setup LedMatrix
  lc.shutdown(0,false);
  lc.setIntensity(0,2);
  lc.clearDisplay(0);

}

void detection()  {
  long dist = sr04.Distance();
  int i;

  if (dist > 87.5){
    i = 7;
  }
  else if (dist < 87.5 && dist >= 75)
  {
    i = 6;
  }
  else if (dist < 75 && dist >= 62.5)
  {
    i = 5;
  }
  else if (dist < 62.5 && dist >= 50)
  {
    i = 4;
  }
  else if (dist < 50 && dist >= 37.5)
  {
    i = 3;
  }
  else if (dist < 37.5 && dist >= 25)
  {
    i = 2;
  }
  else if (dist < 25 && dist >= 12.5)
  {
    i = 1;
  }
  else if (dist < 12.5)
  {
    i = 0;
  }
  
  for (int j=0;j < 8; j++){
    Serial.print(a);
    lc.setLed(0,i,j,true);
    delay(25);
    lc.setLed(0,i,j,false);
  }

  
}


void loop() {
  // put your main code here, to run repeatedly:
  detection();

}
  
