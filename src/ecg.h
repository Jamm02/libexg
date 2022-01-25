#ifndef _ECG_H
#define _ECG_H

#define SAMPLE_RATE_ECG 125

class ecg
{
public:
  void attach(int pin, int sample_rate);
  float filter(float input);
  int calcDelay(int interval);
  int input_pin;
private:
    bool def;
    int _sampleRate;
};

#endif
