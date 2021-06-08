#pragma once

using namespace SoundAnalysis;
using namespace System;

namespace SoundAnalysis
{

    // БПФ Кули — Туки
    ref class FFTransform
    {
        //х - входные данные
        //return - спектрограмма данных
    public: array<double>^ Calculate(array<double>^ x);

          //получает количество значащих байт
          //количество битов для хранения числа
    private: static int Log2(int n);

           //Меняет биты в числах
           //n - число
           //bitsCount кол-во значащих битов в числе
    private: static int ReverseBits(int n, int bitsCount);

           //проверяет является ли число степенью двойки
           //true если n=2^k и k - положительное целое
    private: static bool IsPowerOfTwo(int n);
    };
}

