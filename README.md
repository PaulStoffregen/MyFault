A collection of examples to trigger fault exceptions on Teensy 4.x.

These examples are intended for testing CrashReport.  Every example
should begin with:

```
void setup() {
  Serial.begin(9600);
  Serial.print(CrashReport);
```

Please try to keep each example short and limited to one fault case.
