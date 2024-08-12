// Demonstrates "(IACCVIOL) Instruction Access Violation" fault
// when trying to execute code from RAM while startup.c still
// configures MPU with NOEXEC as a proactive security measure.
//
// https://forum.pjrc.com/index.php?threads/75610/#post-347791

uint16_t writeRegister_DTCM[2];
DMAMEM uint16_t writeRegister_RAM2[2];
EXTMEM uint16_t writeRegister_PSRAM[2];
const uint32_t bitmask = CORE_PIN13_BITMASK;
volatile uint32_t * const reg = &CORE_PIN13_PORTTOGGLE;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  if (CrashReport) {
    while (!Serial && millis() < 5000); // wait
    Serial.print(CrashReport);
  }
  Serial.println("Execute from RAM test");
  // must edit startup.c configure_cache() to remove NOEXEC
  initWriteRegisterMemory(writeRegister_DTCM);
  initWriteRegisterMemory(writeRegister_RAM2);
  initWriteRegisterMemory(writeRegister_PSRAM);
}

void loop() {
  // Uncomment 1 of these lines to blink the LED...
  //digitalToggleFast(13);
  //writeRegister(reg, bitmask);
  //callWriteRegisterMemory(writeRegister_DTCM, reg, bitmask);
  callWriteRegisterMemory(writeRegister_RAM2, reg, bitmask);
  //callWriteRegisterMemory(writeRegister_PSRAM, reg, bitmask);
  delay(750);
}

void writeRegister(volatile uint32_t *r, uint32_t n) {
  *r = n;
  // assembly:
  //   str r1, [r0, #0]
  //   bx  lr
}

void initWriteRegisterMemory(uint16_t *memory) {
  memory[0] = 0x6001; // str r1, [r0, #0]
  memory[1] = 0x4770; // bx  lr
  arm_dcache_flush(memory, 4);
}

void callWriteRegisterMemory(const uint16_t *memory, volatile uint32_t *r, uint32_t n) {
  ((void (*)(volatile uint32_t *r, uint32_t n))((uint32_t)memory | 1))(r, n);
}


