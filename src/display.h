
#ifndef _DISPLAY_
#include "arduino.h"


enum class DisplayMode{
  WaitForAck,
  AckReceived,
  ReadReceived,
  DisplayKiss,
  TerminationPending,
  Terminated
};

class Display{
  public:
    void init(int PinR, int PinG, int PinB);

    /* Update the blink and toggle states */
    void update();

    /***
     * R,G,B are ignored if mode!=DisplayKiss
     */
    void setMode(DisplayMode mode, int R, int G, int B);
    
  private:
    DisplayMode mMode;/* The current display mode */
    unsigned long mTimeInMode; /* The value of millis(), when the current mode was set */
    int mToggleActivated;
    int mTogglePeriod;
    int mToggledTime; /* The value of millis(), since toggled the last time */
    int mBlinkPeriod;
    int mPinR, mPinG, mPinB;
    int mR, mG, mB;
  
};

#endif
