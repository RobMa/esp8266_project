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

/*
#include "display.h"
Display display;

int i = 0;
void setup() {  
  // put your setup code here, to run once:
  display.init(D1,D2,D3);
  //display.setMode(DisplayMode::WaitForAck,0,0,0);
  //display.setMode(DisplayMode::AckReceived,0,0,0);
  //display.setMode(DisplayMode::ReadReceived,0,0,0);
  //display.setMode(DisplayMode::DisplayKiss,1000,1000,1000);
  //display.setMode(DisplayMode::TerminationPending,0,0,0);
  display.setMode(DisplayMode::Terminated,0,0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(i==200){
    display.update();
    i = 0;
  }
  i++;  
}*/

