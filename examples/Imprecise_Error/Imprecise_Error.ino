// MyFault - collection of examples to trigger fault exceptions

int illegal_instruction_execution(void) {
  int (*bad_instruction)(void) = (void *)0xE0000000;
  return bad_instruction();
}

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);

  //Imprecise Error fault
  *(uint32_t *)0x4039C000 = 0;

}

void loop() {
}
