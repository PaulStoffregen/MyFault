#include "crashreport.h"

//Bus Error

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);
  *(uint32_t *)0x4039C000 = 0; //LPSPI3 - Device not enabled
}

void loop() {}
