// MyFault - collection of examples to trigger fault exceptions

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);

  uint32_t *y = 0;
  y[0] = 5;
}

void loop() {
}
