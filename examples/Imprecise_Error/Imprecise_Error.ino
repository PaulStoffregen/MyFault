// MyFault - collection of examples to trigger fault exceptions
void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);

  //Imprecise Error fault
  *(uint32_t *)0x4039C000 = 0;

}

void loop() {
}
