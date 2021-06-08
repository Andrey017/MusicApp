#include "Complex.h"
#include "FFTransform.h"

using namespace SoundAnalysis;
using namespace System;

namespace SoundAnalysis
{
    // ��� ���� � ����
    //� - ������� ������
    //return - ������������� ������
    array<double>^ FFTransform::Calculate(array<double>^ x)
    {
        int xLength = x->Length;
        int length;
        int bitsInLength;
        if (IsPowerOfTwo(xLength))
        {
            length = xLength;
            bitsInLength = Log2(length) - 1;
        }
        else
        {
            bitsInLength = Log2(xLength);
            length = 1 << bitsInLength;
            //������� ����� ��������� ������
        }

        //��������������
        array<Complex^>^ data = gcnew array<Complex^>(length);
        for (int i = 0; i < length; i++) {
            data[i] = gcnew Complex();
        }
        for (int i = 0; i < xLength; i++)
        {
            int j = ReverseBits(i, bitsInLength);
            data[j] = gcnew Complex(x[i]);
        }

        // ����-���� (���� �� �������� ���)
        for (int i = 0; i < bitsInLength; i++)
        {
            int m = 1 << i;
            int n = m * 2;
            double alpha = -(2 * Math::PI / n);

            for (int k = 0; k < m; k++)
            {
                // e^(-2*pi*k/N)
                Complex^ oddPartMultiplier = (gcnew Complex(0, alpha * k))->PoweredE();

                for (int j = k; j < length; j += n)
                {
                    Complex^ evenPart = data[j];
                    Complex^ oddPart = oddPartMultiplier->CompMultiply(oddPartMultiplier, data[j + m]);
                    data[j] = evenPart->CompAddition(evenPart, oddPart);
                    data[j + m] = evenPart->CompSubstraction(evenPart, oddPart);
                }
            }
        }

        //���������� ������������
        array<double>^ spectrogram = gcnew array<double>(length);
        for (int i = 0; i < spectrogram->Length; i++)
        {
            spectrogram[i] = data[i]->AbsPower2();
        }
        return spectrogram;
    }


    //�������� ���������� �������� ����
    //���������� ����� ��� �������� �����
    int FFTransform::Log2(int n)
    {
        int i = 0;
        while (n > 0)
        {
            ++i; n >>= 1;
        }
        return i;
    }


    //������ ���� � ������
    //n - �����
    //bitsCount ���-�� �������� ����� � �����
    int FFTransform::ReverseBits(int n, int bitsCount)
    {
        int reversed = 0;
        for (int i = 0; i < bitsCount; i++)
        {
            int nextBit = n & 1;
            n >>= 1;

            reversed <<= 1;
            reversed |= nextBit;
        }
        return reversed;
    }

    //��������� �������� �� ����� �������� ������
    //true ���� n=2^k � k - ������������� �����
    bool FFTransform::IsPowerOfTwo(int n)
    {
        return n > 1 && (n & (n - 1)) == 0;
    }
}

