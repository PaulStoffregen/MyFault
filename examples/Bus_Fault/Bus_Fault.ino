// MyFault - collection of examples to trigger fault exceptions

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);
  Serial.println("Bus Fault");

  LPSPI3_VERID = 0;
  Serial.println("after");
}

void loop() {
}
