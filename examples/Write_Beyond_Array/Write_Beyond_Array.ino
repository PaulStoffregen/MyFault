char bigArray[128 * 1024];

void setup() {
  Serial.begin(9600);  
  Serial.print(CrashReport);  

  const uint32_t beyondArray = 15000;
  memset(bigArray, 0, sizeof(bigArray) + beyondArray);
}

void loop() {}
