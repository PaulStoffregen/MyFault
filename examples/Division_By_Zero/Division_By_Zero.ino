#include "crashreport.h"

volatile int number = 0xbeef;

void setup() {
  Serial.begin(9600);  
  Serial.print(CrashReport);  

  SCB_CCR |= (1 << 4);  //enable "division by zero" hardfaults.
  Serial.println(number / 0);  
}

void loop() {}
