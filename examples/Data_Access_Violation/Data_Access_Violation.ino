// MyFault - collection of examples to trigger fault exceptions

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);

  *(volatile uint32_t *)0x30000000 = 0;

}

void loop() {
}
