#pragma once

using namespace SoundAnalysis;
using namespace System;

namespace SoundAnalysis
{

    // ��� ���� � ����
    ref class FFTransform
    {
        //� - ������� ������
        //return - ������������� ������
    public: array<double>^ Calculate(array<double>^ x);

          //�������� ���������� �������� ����
          //���������� ����� ��� �������� �����
    private: static int Log2(int n);

           //������ ���� � ������
           //n - �����
           //bitsCount ���-�� �������� ����� � �����
    private: static int ReverseBits(int n, int bitsCount);

           //��������� �������� �� ����� �������� ������
           //true ���� n=2^k � k - ������������� �����
    private: static bool IsPowerOfTwo(int n);
    };
}

