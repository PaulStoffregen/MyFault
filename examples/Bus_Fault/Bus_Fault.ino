// MyFault - collection of examples to trigger fault exceptions

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);
  Serial.println("Bus Fault");
  asm("dsb");
  asm("isb");
  *(uint32_t *)0x4039C000 = 0;
  Serial.println("after");
}

void loop() {
}
