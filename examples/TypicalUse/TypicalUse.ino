// Typical Usage Example : when a sketch is leaving the Teensy non-responsive
// Compile this sketch with USB Serial
// With Serial Monitor attaching it will restart and show the CrashReport
// If Serial Monitor is not active it will continue to Crash and restart

void setup() {
  Serial.begin(9600); // With TeensyDuino 1.54 Serial.begin() may return connected
  if ( Serial && CrashReport ) { // Make sure Serial is alive and there is a CrashReport stored.
    Serial.print(CrashReport); // Once called any crash data is cleared
    // In this case USB Serial is used - but any Stream capable output will work : SD Card or other UART Serial
  }
  else {
    // Following code will cause a Fault of the processor from writing to a NULL pointer
    // Don't run it again until the next restart showing normal after a fault
    uint32_t *y = 0;
    y[0] = 5;
  }
  pinMode( LED_BUILTIN, OUTPUT );
}

elapsedMillis blinkTime;
void loop() {
  if ( blinkTime > 1000 ) {
    digitalToggle( LED_BUILTIN );
    blinkTime = 0;
  }
}
