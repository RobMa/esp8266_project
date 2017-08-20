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
}
