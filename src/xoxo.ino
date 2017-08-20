#include "display.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}


int val = 0;
long updated = 0;
void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - updated >= 1) {
    val = ((millis() % 1000) * 1023) / 1000;
    //Serial.printf("millismod = %i, val = %i, millis = %li\n", val, (millis() % 1000), millis());
    analogWrite(D1, 1023-val);
    analogWrite(D2, val);
    analogWrite(D3, val);
    updated = millis();
  }

}

