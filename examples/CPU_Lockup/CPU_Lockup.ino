// MyFault - collection of examples to trigger fault exceptions

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);
  delay(1000);

  // Cause a CPU lockup by reconfiguring FlexRAM
  IOMUXC_GPR_GPR17 = 0;
}

void loop() {
}
