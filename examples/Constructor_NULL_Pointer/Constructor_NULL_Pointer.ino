// MyFault - collection of examples to trigger fault exceptions

// This example exposes a known limitation - CrashReport prints too late!

class crashme {public:crashme(){*(uint32_t *)0 = 0;}};
crashme foo;

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);
}

void loop() {
}
