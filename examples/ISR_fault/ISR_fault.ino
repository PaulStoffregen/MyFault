// MyFault - collection of examples to trigger fault exceptions

void isr()
{
  *(volatile uint32_t *)0x30000000 = 0;
}

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);

  attachInterruptVector(IRQ_Reserved1, isr);
  NVIC_ENABLE_IRQ(IRQ_Reserved1);
  NVIC_SET_PENDING(IRQ_Reserved1);
}

void loop() {
}
