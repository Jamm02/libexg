// LibEXG
// https://github.com/upsidedownlabs/libexg

// Upside Down Labs invests time and resources providing this open source code,
// please support Upside Down Labs and open-source hardware by purchasing
// products from Upside Down Labs!

// Copyright (c) 2021 Moteen Shah moteenshah.02@gmail.com
// Copyright (c) 2021 Upside Down Labs - contact@upsidedownlabs.tech

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#ifndef BIOAMP_EXG_PILL_H_
#define BIOAMP_EXG_PILL_H_

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"

// #include <ecg.h>
// #include <eog.h>
// #include <emg.h>
// #include <eeg.h>

#endif

#define EMG 1
#define EOG 2
#define EEG 3
#define ECG 4
#define SAMPLE_RATE_ECG 125
#define SAMPLE_RATE_EEG 256
#define SAMPLE_RATE_EMG 500
#define SAMPLE_RATE_EOG 75

class eog
{
public:
  void attachEOG(int pin, int sample_rate);
  float EOGfilter(float input);
  int calcDelayEOG(int interval);
  int input_pin;
private:
float z1 , z2;
    int _sampleRate;
};

class emg
{
public:
  void attachEMG(int pin, int sample_rate);
  float EMGfilter(float input);
  int calcDelayEMG(int interval);
  int input_pin;
private:
float z1 , z2;

    int _sampleRate;
};

class eeg
{
public:
  void attachEEG(int pin, int sample_rate);
  float EEGfilter(float input);
  int calcDelayEEG(int interval);
  int input_pin;
private:
float z1 , z2;

    int _sampleRate;
};

class ecg
{
public:
  void attachECG(int pin, int sample_rate);
  float ECGfilter(float input);
  int calcDelayECG(int interval);
  int input_pin;
private:
float z1 , z2;

    
    int _sampleRate;
};

#endif
