#ifndef Alarm_h
#define Alarm_h

#include "Arduino.h"
class Alarm {
  public: 
    Alarm(
      unsigned long size,
      float alarmThresholdInPercent[]
    );
    
    bool shouldSendAlarm(float percent);
    float getPercent();
    float getThreshold();
    
  private:
    float *_alarm_threshold_in_percent;
    float _current_alarm_threshold = 0;
    float _percent_value = 0;
    unsigned long _size = 0;
    

};


#endif
