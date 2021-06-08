#include "Complex.h"
#include "FFTransform.h"
#include "FrequencyCheck.h"

namespace FFTTuner
{
    // ������� ������� �������� ����� ��������������� �������.
        // ������� ��������������� �������: ��������� �������������, ������� ����, �����������
        //� - �������� ������
        //sampleRate ������� �������������
        //minFreq ����������� �������� �������
        //maxFreq ������������ �������� �������
        //returns ��������� �������, 0 - � ��������� ������

    double FrequencyCheck::FindFundamentalFrequency(array<double>^ x, int sampleRate, double minFreq, double maxFreq)
    {
        FFTransform spec;
        array<double>^ spectr = spec.Calculate(x);

        int usefullMinSpectr = Math::Max(0, (int)(minFreq * spectr->Length / sampleRate));
        int usefullMaxSpectr = Math::Min(spectr->Length, (int)(maxFreq * spectr->Length / sampleRate) + 1);

        // ������� ���� ������ �� ��� 
        const int PeaksCount = 5;
        array<int>^ peakIndices;
        peakIndices = FindPeaks(spectr, usefullMinSpectr, usefullMaxSpectr - usefullMinSpectr,
            PeaksCount);

        if (Array::IndexOf(peakIndices, usefullMinSpectr) >= 0)
        {
            // ���� ����� �� ����� - ������ 0
            return 0;
        }

        // �������� �������� ��� ����������� ������� ��������
        const int verifyFragmentOffset = 0;
        int verifyFragmentLength = (int)(sampleRate / minFreq);

        // ���������� ��� ���� ��� ������ ������ � ���������� �������� �� ������
        double minPeakValue = Double::PositiveInfinity;
        int minPeakIndex = 0;
        int minOptimalInterval = 0;
        for (int i = 0; i < peakIndices->Length; i++)
        {
            int index = peakIndices[i];
            int binIntervalStart = spectr->Length / (index + 1);
            int binIntervalEnd = spectr->Length / index;
            int interval;
            double peakValue;

            // ������������ ������/����������
            FrequencyCheck::ScanSignalIntervals(x, verifyFragmentOffset, verifyFragmentLength,
                binIntervalStart, binIntervalEnd, &interval, &peakValue);

            if (peakValue < minPeakValue)
            {
                minPeakValue = peakValue;
                minPeakIndex = index;
                minOptimalInterval = interval;
            }
        }

        return (double)sampleRate / minOptimalInterval;
    }

    void FrequencyCheck::ScanSignalIntervals(array<double>^ x, int index, int length,
        int intervalMin, int intervalMax, int* optimalInterval, double* optimalValue)
    {
        *optimalValue = Double::PositiveInfinity;
        *optimalInterval = 0;

        // �������� ����� ����� ��������� � ������� ��������� ����� ���� �������
        // ������������ ��� ������������� ���������
        const int MaxAmountOfSteps = 30;
        int steps = intervalMax - intervalMin;
        if (steps > MaxAmountOfSteps)
            steps = MaxAmountOfSteps;
        else if (steps <= 0)
            steps = 1;

        // ���� � ��������� ����� � ���������� ��������� �����
        for (int i = 0; i < steps; i++)
        {
            int interval = intervalMin + (intervalMax - intervalMin) * i / steps;

            double sum = 0;
            for (int j = 0; j < length; j++)
            {
                double diff = x[index + j] - x[index + j + interval];
                sum += diff * diff;
            }
            if (*optimalValue > sum)
            {
                *optimalValue = sum;
                *optimalInterval = interval;
            }
        }
    }

    array<int>^ FrequencyCheck::FindPeaks(array<double>^ values, int index, int length, int peaksCount) {
        array<double>^ peakValues = gcnew array<double>(peaksCount);
        array<int>^ peakIndices = gcnew array<int>(peaksCount);

        for (int i = 0; i < peaksCount; i++)
        {
            peakValues[i] = values[peakIndices[i] = i + index];
        }

        // ������� ����������� ��������
        double minStoredPeak = peakValues[0];
        int minIndex = 0;
        for (int i = 1; i < peaksCount; i++)
        {
            if (minStoredPeak > peakValues[i]) minStoredPeak = peakValues[minIndex = i];
        }

        for (int i = peaksCount; i < length; i++)
        {
            if (minStoredPeak < values[i + index])
            {
                // �������� ����������� �������� �������
                peakValues[minIndex] = values[peakIndices[minIndex] = i + index];

                // � ���� ����������� �������� �����
                minStoredPeak = peakValues[minIndex = 0];
                for (int j = 1; j < peaksCount; j++)
                {
                    if (minStoredPeak > peakValues[j]) minStoredPeak = peakValues[minIndex = j];
                }
            }
        }
        return peakIndices;
    }
}
