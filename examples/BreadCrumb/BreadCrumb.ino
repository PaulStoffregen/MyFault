// MyFault - collection of examples to trigger fault exceptions

// Example for :  void breadcrumb(unsigned int num, unsigned int value) {
// num is a value 1 to 6 for possible unique storage entries

void setup() {
  if ( !CrashReport ) {
    CrashReport.breadcrumb( 1, 0x5000000 | __LINE__ ); // Upper bits hold '5' perhaps indicating func() for ref, lower bits show line #
    CrashReport.breadcrumb( 2, millis() );
    Serial.begin(9600);
    CrashReport.breadcrumb( 3, millis() );
    while (!Serial && millis() < 4000 );
    CrashReport.breadcrumb( 4, millis() );
    Serial.println("\n" __FILE__ " " __DATE__ " " __TIME__);
    CrashReport.breadcrumb( 5, millis() );
    CrashReport.breadcrumb( 6, 0xdeadbeef );
    *(volatile uint32_t *)0x30000000 = 0; // causes Data_Access_Violation
  }
  else {
    while (!Serial && millis() < 10000 );
    Serial.println("\n" __FILE__ " " __DATE__ " " __TIME__);
    Serial.print(CrashReport);
  }
}

void loop() {
}

