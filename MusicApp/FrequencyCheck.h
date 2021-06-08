#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;

namespace FFTTuner
{

    // ������� ������� �������� ����� ��������������� �������.
    ref class FrequencyCheck
    {
        // ������� ��������������� �������: ��������� �������������, ������� ����, �����������
        //� - �������� ������
        //sampleRate ������� �������������
        //minFreq ����������� �������� �������
        //maxFreq ������������ �������� �������
        //returns ��������� �������, 0 - � ��������� ������

    public: double FindFundamentalFrequency(array<double>^ x, int sampleRate, double minFreq, double maxFreq);

    private: static void ScanSignalIntervals(array<double>^ x, int index, int length,
        int intervalMin, int intervalMax, int* optimalInterval, double* optimalValue);

    private: static array<int>^ FindPeaks(array<double>^ values, int index, int length, int peaksCount);
    };
}
