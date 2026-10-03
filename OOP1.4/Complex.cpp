#include "Complex.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

bool Complex::setReal(double value)
{
    if (isfinite(value))
    {
        real = value;
        return true;
    }
    real = 0;
    return false;
}

bool Complex::setImag(double value)
{
    if (isfinite(value))
    {
        imag = value;
        return true;
    }
    imag = 0;
    return false;
}

bool Complex::Init(double realPart, double imagPart)
{
    return setReal(realPart) && setImag(imagPart);
}

void Complex::Read()
{
    double realPart;
    double imagPart;

    cout << "Enter real part: ";
    cin >> realPart;

    cout << "Enter imaginary part: ";
    cin >> imagPart;

    Init(realPart, imagPart);
}

void Complex::Display() const
{
    cout << toString() << endl;
}

string Complex::toString() const
{
    ostringstream out;

    out << real;

    if (imag >= 0)
        out << " + " << imag << "i";
    else
        out << " - " << -imag << "i";

    return out.str();
}

Complex Complex::add(const Complex& other) const
{
    Complex result;

    result.Init(
        real + other.real,
        imag + other.imag
    );

    return result;
}

Complex Complex::subtract(const Complex& other) const
{
    Complex result;

    result.Init(
        real - other.real,
        imag - other.imag
    );

    return result;
}

Complex Complex::multiply(const Complex& other) const
{
    Complex result;

    double newReal = real * other.real - imag * other.imag;
    double newImag = real * other.imag + imag * other.real;

    result.Init(newReal, newImag);

    return result;
}