#include "Complex.h"
using namespace SoundAnalysis;

using namespace System;
using namespace SoundAnalysis;

namespace SoundAnalysis
{
    //комплексные числа
    Complex::Complex()
    {
        this->Re = 0;
        this->Im = 0;
    }

    Complex::Complex(double re)
    {
        this->Re = re;
        this->Im = 0;
    }

    Complex::Complex(double re, double im)
    {
        this->Re = re;
        this->Im = im;
    }

    Complex^ Complex::ComplexImp(double n)
    {
        return gcnew Complex(n, 0);
    }

    Complex^ Complex::CompMultiply(Complex^ n1, Complex^ n2)
    {
        return gcnew Complex(n1->Re * n2->Re - n1->Im * n2->Im,
            n1->Im * n2->Re + n1->Re * n2->Im);
    }

    Complex^ Complex::CompAddition(Complex^ n1, Complex^ n2)
    {
        return gcnew Complex(n1->Re + n2->Re, n1->Im + n2->Im);
    }

    Complex^ Complex::CompSubstraction(Complex^ n1, Complex^ n2)
    {
        return gcnew Complex(n1->Re - n2->Re, n1->Im - n2->Im);
    }

    Complex^ Complex::CompNegative(Complex^ n)
    {
        return gcnew Complex(-n->Re, -n->Im);
    }

    Complex^ Complex::PoweredE()
    {
        double e = Math::Exp(Re);
        return gcnew Complex(e * Math::Cos(Im), e * Math::Sin(Im));
    }

    double Complex::Power2()
    {
        return Re * Re - Im * Im;
    }

    double Complex::AbsPower2()
    {
        return Re * Re + Im * Im;
    }

    String^ Complex::ConvertToString()
    {
        return String::Format("{0}+i*{1}", Re, Im);
    }
}
