#include "Complex.h"
#include "FFTransform.h"

using namespace SoundAnalysis;
using namespace System;

namespace SoundAnalysis
{
    // БПФ Кули — Туки
    //х - входные данные
    //return - спектрограмма данных
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
            //объекты будут дополнены нулями
        }

        //реверсирвоание
        array<Complex^>^ data = gcnew array<Complex^>(length);
        for (int i = 0; i < length; i++) {
            data[i] = gcnew Complex();
        }
        for (int i = 0; i < xLength; i++)
        {
            int j = ReverseBits(i, bitsInLength);
            data[j] = gcnew Complex(x[i]);
        }

        // Кули-Туки (один из способов БПФ)
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

        //вычисление спектрограмы
        array<double>^ spectrogram = gcnew array<double>(length);
        for (int i = 0; i < spectrogram->Length; i++)
        {
            spectrogram[i] = data[i]->AbsPower2();
        }
        return spectrogram;
    }


    //получает количество значащих байт
    //количество битов для хранения числа
    int FFTransform::Log2(int n)
    {
        int i = 0;
        while (n > 0)
        {
            ++i; n >>= 1;
        }
        return i;
    }


    //Меняет биты в числах
    //n - число
    //bitsCount кол-во значащих битов в числе
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

    //проверяет является ли число степенью двойки
    //true если n=2^k и k - положительное целое
    bool FFTransform::IsPowerOfTwo(int n)
    {
        return n > 1 && (n & (n - 1)) == 0;
    }
}

