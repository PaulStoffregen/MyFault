// MyFault - collection of examples to trigger fault exceptions

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);

  // configure invalid address for memory fault handler
  _VectorsRam[4] = 0xFFFFFFFF;

  // cause a memory fault, which then causes hard fault
  uint32_t *y = 0;
  y[0] = 5;
}

void loop() {
}
