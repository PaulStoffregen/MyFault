// MyFault - collection of examples to trigger fault exceptions

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);
  Serial.println("Bus Fault");
  SCB_SHCSR |= (1<<18) | (1<<17) | (1<<16);
  asm("dsb");
  asm("isb");
  *(uint32_t *)0x4039C000 = 0;
  Serial.println("after");
}

void loop() {
}
