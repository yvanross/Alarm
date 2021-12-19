#include "Arduino.h"
#include "Alarm.h"

Alarm:: Alarm(
  unsigned long size,
  float alarmThresholdInPercent[]) {
    _alarm_threshold_in_percent = alarmThresholdInPercent;
    _size = size;

}

bool Alarm::shouldSendAlarm(float percentValue){
  float seuil_alarme = 0;
  for (unsigned int i = 0; i <  _size; i++) {
    if (percentValue > _alarm_threshold_in_percent[i])
      seuil_alarme = _alarm_threshold_in_percent[i];
  }

  if (fabs(seuil_alarme - _current_alarm_threshold) > 1) {
     _current_alarm_threshold = seuil_alarme;
    _percent_value = percentValue;
    return true;
  } else {
    return false;
  }
}

float Alarm::getPercent(){
  return _percent_value;
}

float Alarm::getThreshold(){
  return _current_alarm_threshold;
}
