#pragma once
#include <string>

    using namespace std;

    class Complex
    {
    private:
        double real;
        double imag;

    public:
        // Методи доступу
        double getReal() const { return real; }
        double getImag() const { return imag; }

        bool setReal(double);
        bool setImag(double);

        // Основні методи
        bool Init(double, double);
        void Read();
        void Display() const;
        string toString() const;

        // Операції над комплексними числами
        Complex add(const Complex&) const;
        Complex subtract(const Complex&) const;
        Complex multiply(const Complex&) const;
    };


