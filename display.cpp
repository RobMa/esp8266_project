#include "display.h"

void Display::init(int PinR, int PinG, int PinB){
  mPinR = PinR;
  mPinG = PinG;
  mPinB = PinB;
  mToggleActivated = 0;
}
void Display::update(){
  int t = millis() - mTimeInMode;
  if(mToggleActivated){
    t = t % (5*60*1000);
    if(t<mToggledTime){
      analogWrite(mPinR, 1023);
      analogWrite(mPinG, 0);
      analogWrite(mPinB, 0);
    }
    else{
      analogWrite(mPinR, 0);
      analogWrite(mPinG, 0);
      analogWrite(mPinB, 0);
    }
  }
  else{
    t = t % mBlinkPeriod;
    int valR, valG, valB;
    if(t <= mBlinkPeriod/2){
      valR = (mR  * t)/ (mBlinkPeriod/2);
      valG = (mG  * t)/ (mBlinkPeriod/2);
      valB = (mB  * t)/ (mBlinkPeriod/2);
    }
    else{
      valR = mR - (mR * (t - mBlinkPeriod/2)) / (mBlinkPeriod/2) ;
      valG = mG - (mG * (t - mBlinkPeriod/2)) / (mBlinkPeriod/2) ;
      valB = mB - (mB * (t - mBlinkPeriod/2)) / (mBlinkPeriod/2) ;    
    }
    analogWrite(mPinR, valR);
    analogWrite(mPinG, valG);
    analogWrite(mPinB, valB);
  }

}
void Display::setMode(DisplayMode mode, int R, int G, int B){
  mToggleActivated = 0;
  mTimeInMode = millis();
  if(mode == DisplayMode::WaitForAck){
    mR = 0; mG = 1023; mB = 0;
    mBlinkPeriod = 8000;
  }
  else if(mode == DisplayMode::AckReceived){
    mR = 0; mG = 1023; mB = 0;
    mBlinkPeriod = 20000;
  }
  else if(mode == DisplayMode::ReadReceived){
    mR = 0; mG = 0; mB = 255*4;
    mBlinkPeriod = 400;
  }
  else if(mode == DisplayMode::DisplayKiss){
    mR = R; mG = G; mB = B;
    mBlinkPeriod = 1000;
  }
  else if(mode == DisplayMode::TerminationPending){
    mR = 255*4; mG = 0; mB = 0;
    mToggleActivated = 1;
    mToggledTime = 60*1000;
  }
  else if(mode == DisplayMode::Terminated){
    mR = 255*4; mG = 0; mB = 0;
    mBlinkPeriod = 200;
  }

}

