#ifndef _EEG_H
#define _EEG_H

#define SAMPLE_RATE_EEG 256

class eeg
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
