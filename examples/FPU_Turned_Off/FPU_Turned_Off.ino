// MyFault - collection of examples to trigger fault exceptions

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);

  //delay(5000);
  Serial.print("Coprocessor Fault - turn off FPU");
  __asm volatile(
    "ldr r0, =0xE000ED88 \n"
    "mov r1, #0 \n"
    "str r1, [r0] \n"
    "dsb \n"
    "vmov r0, s0 \n"
  );
}

void loop() {
}
