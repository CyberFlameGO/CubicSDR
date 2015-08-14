#pragma once

#include "IOThread.h"
#include "SpectrumVisualProcessor.h"

class FFTVisualDataThread : public IOThread {
public:
    FFTVisualDataThread();
    ~FFTVisualDataThread();
    
    void setLinesPerSecond(int lps);
    int getLinesPerSecond();
    SpectrumVisualProcessor *getProcessor();
    
    void run();
    
protected:
    FFTDataDistributor fftDistrib;
    DemodulatorThreadInputQueue fftQueue;
    SpectrumVisualProcessor wproc;
    
    std::atomic_int linesPerSecond;
    std::atomic_bool lpsChanged;
};
