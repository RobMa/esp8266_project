
#ifndef _RECEIVER_
#include <ESP8266WiFi.h>
#include "arduino.h"

class Receiver
{
  public:
    Receiver(const char *serveraddress, int port);
    void update();
  private:
    
};


#endif
