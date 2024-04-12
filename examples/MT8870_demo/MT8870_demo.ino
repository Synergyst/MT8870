#include "MT8870.h"
MT8870 DTMF;
char ch = 0;

void setup() {
  DTMF.begin(0, 1, 2, 3);
  pinMode(4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(4), dtmfProcess, RISING);
  Serial.begin(115200);
  delay(2000);
  Serial.println("Started..");
}

void dtmfProcess() {
  ch = DTMF.read();
}

void loop() {
  if (ch > 0) {
    Serial.println(ch);
    ch = 0;
  }
}