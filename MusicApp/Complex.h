#pragma once

using namespace System;

namespace SoundAnalysis
{
    //комплексные числа
    ref struct Complex
    {
    public: double Re;
    public: double Im;

    public: Complex();

    public: Complex(double re);

    public: Complex(double re, double im);

    public: Complex^ ComplexImp(double n);

    public: Complex^ CompMultiply(Complex^ n1, Complex^ n2);

    public: Complex^ CompAddition(Complex^ n1, Complex^ n2);

    public: Complex^ CompSubstraction(Complex^ n1, Complex^ n2);

    public: Complex^ CompNegative(Complex^ n);

    public: Complex^ PoweredE();

    public: double Power2();

    public: double AbsPower2();

    public: String^ ConvertToString();
    };
}