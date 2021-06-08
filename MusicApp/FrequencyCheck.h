#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;

namespace FFTTuner
{

    // Утилита которая помогает найти фундаментальную чатсоту.
    ref class FrequencyCheck
    {
        // Находим фундаментальную частоту: вычисляем спектрограмму, находим пики, анализируем
        //х - звуковые сэмплы
        //sampleRate частота семплирования
        //minFreq минимальная полезная частота
        //maxFreq максимальная полезная частота
        //returns Найденная частота, 0 - в противном случае

    public: double FindFundamentalFrequency(array<double>^ x, int sampleRate, double minFreq, double maxFreq);

    private: static void ScanSignalIntervals(array<double>^ x, int index, int length,
        int intervalMin, int intervalMax, int* optimalInterval, double* optimalValue);

    private: static array<int>^ FindPeaks(array<double>^ values, int index, int length, int peaksCount);
    };
}
