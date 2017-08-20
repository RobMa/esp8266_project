
#ifndef _RECEIVER_
#include <ESP8266WiFi.h>
#include "arduino.h"

class Message
{
  public:
    Message(char *message, int message_len, char *subject, int subject_len);
    static const int SUBJECT_MAX_LEN = 5;
    static const int MSG_MAX_LEN = 32;
  private:
    char mSubject[SUBJECT_MAX_LEN];
    char mMessage[MSG_MAX_LEN];
};

class Receiver
{
  public:
    Receiver(const char *address, int port, const char* subject);
    void init();
    void update();
    int getMessageCount();
    Message* getNextMessage();
    
  private:
    int mMessageCount;
    Message mMessage;    
};


#endif
