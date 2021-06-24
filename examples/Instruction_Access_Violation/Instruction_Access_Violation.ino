// MyFault - collection of examples to trigger fault exceptions
  
void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);
  delay(500);
  Serial.println("Instruction Access Violation");
  void (*iav)(void) = (void (*)(void))(0x00000000);
  iav();
}

void loop() {
}

