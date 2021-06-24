// MyFault - collection of examples to trigger fault exceptions
// If the subsystem is not enabled it will crash/hang and not recover

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);

//  CCM_CCGR5 |= CCM_CCGR5_FLEXIO1(CCM_CCGR_ON);
  Serial.printf("VERID:%x PARAM:%x CTRL:%x PIN: %x\n", FLEXIO1_VERID, FLEXIO1_PARAM, FLEXIO1_CTRL, FLEXIO1_PIN);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalToggleFast(13);
  delay(250);
}
