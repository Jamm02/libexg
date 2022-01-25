#ifndef _EOG_H
#define _EOG_H


#define SAMPLE_RATE_EOG 75

class eog
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
