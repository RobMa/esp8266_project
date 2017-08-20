
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
    Display(int PinR, int PinG, int PinB);

    /* Udpdate the blink and toggle states */
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
    
  
};

#endif
