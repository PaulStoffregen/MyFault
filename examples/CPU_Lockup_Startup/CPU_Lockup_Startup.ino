// MyFault - collection of examples to trigger fault exceptions

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);
}

// Cause a CPU lockup by reconfiguring FlexRAM
extern "C" void startup_early_hook();
void startup_early_hook() {
  IOMUXC_GPR_GPR17 = 0;
}

void loop() {
}
