#ifndef _EMG_H
#define _EMG_H


#define SAMPLE_RATE_EMG 500

class emg
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
