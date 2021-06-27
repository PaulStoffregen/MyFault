// MyFault - collection of examples to trigger fault exceptions
void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);

  //Call an unused interrupt vector
  NVIC_SET_PENDING(IRQ_Reserved1);
}

void loop() {
}
