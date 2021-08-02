// MyFault - collection of examples to trigger fault exceptions
// This may take a while to trip

extern "C" uint32_t set_arm_clock(uint32_t frequency); // clockspeed.c

void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);
  tempmon_setup();
  set_arm_clock(912000000);
  delay(500);
}

elapsedMillis tempPrint;
void loop() {
  float temperature = tempmonGetTemp();

  if(tempPrint > 1000) {
    Serial.printf("Temp(degC) = , %f\n", temperature);
    tempPrint = 0;
  }

}

static uint16_t frequency = 0x03U;
static uint32_t highAlarmTemp   = 50U;
static uint32_t lowAlarmTemp    = 25U;
static uint32_t panicAlarmTemp  = 55U;

static uint32_t s_hotTemp, s_hotCount ;
static float s_hot_ROOM, s_roomC_hotC;

void tempmon_setup(void)
{
  uint32_t calibrationData;
  uint32_t roomCount;
  uint32_t tempCodeVal;

  //first power on the temperature sensor - no register change 
  //power is already on so uncomment for example
  TEMPMON_TEMPSENSE0 &= ~0x1U;

  //set monitoring frequency - no register change
  TEMPMON_TEMPSENSE1 = (((uint32_t)(((uint32_t)(frequency)) << 0U)) & 0xFFFFU);
  
  //read calibration data - this works
  calibrationData = HW_OCOTP_ANA1;
    s_hotTemp = (uint32_t)(calibrationData & 0xFFU) >> 0x00U;
    s_hotCount = (uint32_t)(calibrationData & 0xFFF00U) >> 0X08U;
    roomCount = (uint32_t)(calibrationData & 0xFFF00000U) >> 0x14U;
    s_hot_ROOM = (float) (s_hotTemp) - 25.0f;
    s_roomC_hotC = (float) roomCount - (float) s_hotCount;
  
    //time to set alarm temperatures
  //Set High Alarm Temp
  tempCodeVal = ((float)s_hotCount + ((float)s_hotTemp - highAlarmTemp) * s_roomC_hotC / s_hot_ROOM);
    TEMPMON_TEMPSENSE0 |= (((uint32_t)(((uint32_t)(tempCodeVal)) << 20U)) & 0xFFF00000U);
  
  //Set Panic Alarm Temp
  tempCodeVal = ((float)s_hotCount + ((float)s_hotTemp - panicAlarmTemp) * s_roomC_hotC / s_hot_ROOM);
  TEMPMON_TEMPSENSE2 |= (((uint32_t)(((uint32_t)(tempCodeVal)) << 16U)) & 0xFFF0000U);
  
  // Set Low Temp Alarm Temp
  tempCodeVal = ((float)s_hotCount + ((float)s_hotTemp - lowAlarmTemp) * s_roomC_hotC / s_hot_ROOM);
    TEMPMON_TEMPSENSE2 |= (((uint32_t)(((uint32_t)(tempCodeVal)) << 0U)) & 0xFFFU);

  //Start temp monitoring
  TEMPMON_TEMPSENSE0 |= 0x2U;   //starts temp monitoring

}

