#include "crashreport.h"

class crashme {public:crashme(){ uint32_t *y = 0; y[0] = 5; } };
crashme foo;

void setup() {
  Serial.begin(9600);  
  Serial.print(CrashReport);  
}

void loop() {}
