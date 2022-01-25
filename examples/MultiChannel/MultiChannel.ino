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

#include <libexg.h>

#define BAUD_RATE 115200
#define CHANNELS 2
emg Emg[CHANNELS];

void setup()
{
    Emg[0].attachEMG(A0, SAMPLE_RATE_EMG);
    Emg[1].attachEMG(A1, SAMPLE_RATE_EMG);

    Serial.begin(BAUD_RATE);
}

void loop()
{
    unsigned long start_time = micros();
    for (int i = 0; i < CHANNELS; i++)
    {
        int data;
        data = analogRead(Emg[i].input_pin);
        int signal = Emg[i].EMGfilter(data);
        Serial.print(signal);
        Serial.print(" ");
    }
    
    unsigned long interval = micros() - start_time;
    delay(Emg[0].calcDelayEMG(interval));

    Serial.println();
}
