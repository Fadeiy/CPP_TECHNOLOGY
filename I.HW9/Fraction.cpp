#include <iostream>
#include <cmath>
#include <algorithm>
#include "Fraction.h"

using namespace std;

Fraction::Fraction(int numerator, int denominator)
{
    mNumerator = numerator;
    mDenominator = denominator;
    recovery(*this);
}

Fraction& Fraction::operator=(const Fraction& fraction)= default;

bool Fraction::operator==(const Fraction& Fraction) const
{
    return (mNumerator * Fraction.mDenominator == Fraction.mNumerator * mDenominator);
}

bool Fraction::operator>(const Fraction& Fraction) const
{
    return (mNumerator * Fraction.mDenominator > Fraction.mNumerator * mDenominator);
}

bool Fraction::operator<(const Fraction& Fraction) const
{
    return (mNumerator * Fraction.mDenominator < Fraction.mNumerator * mDenominator);
}

bool Fraction::operator>=(const Fraction& Fraction) const
{
    return (mNumerator * Fraction.mDenominator >= Fraction.mNumerator * mDenominator);
}

bool Fraction::operator<=(const Fraction& Fraction) const
{
    return (mNumerator * Fraction.mDenominator <= Fraction.mNumerator * mDenominator);
}

bool Fraction::operator!=(const Fraction& Fraction) const
{
    return (mNumerator * Fraction.mDenominator != Fraction.mNumerator * mDenominator);
}

Fraction& Fraction::operator!() const
{
    Fraction result(mDenominator, mNumerator);
    return result;
}

Fraction& Fraction::operator+() const
{
    Fraction result(mNumerator, mDenominator);
    return result;
}

Fraction& Fraction::operator-() const
{
    Fraction result(-mNumerator, mDenominator);
    return result;
}

Fraction& Fraction::operator*(const Fraction& factor) const
{
    int newNumerator = mNumerator * factor.mNumerator;
    int newDenominator = mDenominator * factor.mDenominator;
    Fraction newFraction(newNumerator, newDenominator);
    return newFraction;
}

Fraction& Fraction::operator/(const Fraction& divider) const
{
    int newNumerator = mNumerator * divider.mDenominator;
    int newDenominator = mDenominator * divider.mNumerator;
    Fraction newFraction(newNumerator, newDenominator);
    return newFraction;
}

Fraction& Fraction::operator++()
{
    Fraction result(++mNumerator, ++mDenominator);
    return result;
}

Fraction& Fraction::operator++(int)
{
    Fraction result(mNumerator++, mDenominator++);
    return result;
}

Fraction& Fraction::operator--()
{
    Fraction result(--mNumerator, --mDenominator);
    return result;
}

Fraction& Fraction::operator--(int)
{
    Fraction result(-mNumerator, mDenominator);
    return result;
}

Fraction& Fraction::operator*(const int number) const
{
    int newNumerator = mNumerator * number;
    int newDenominator = mDenominator;
    Fraction newFraction(newNumerator, newDenominator);
    //recovery(newFraction);
    return newFraction;
}

Fraction & Fraction::operator/(const int number) const
{
    int newNumerator = mNumerator;
    int newDenominator = mDenominator * number;
    Fraction newFraction(newNumerator, newDenominator);
    //recovery(newFraction);
    return newFraction;
}

double Fraction::operator~() const
{
    return ((double)mNumerator / mDenominator);
}

Fraction& Fraction::operator%(const double number) const
{
    Fraction result((int)((((double)mNumerator / mDenominator) - (int)(((double)mNumerator / mDenominator) / number) * number) * 1000), 1000);
    return result;
}

Fraction& Fraction::operator%=(const double number)
{
    mNumerator = (int)((((double)mNumerator / mDenominator) - (int)(((double)mNumerator / mDenominator) / number) * number) * 1000);
    mDenominator = 1000;
    return *this;
}

Fraction& Fraction::operator*=(const int number)
{
    mNumerator = mNumerator * number;
    recovery(*this);
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& factor)
{
    mNumerator *= factor.mNumerator;
    mDenominator *= factor.mDenominator;
    recovery(*this);
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& divider)
{
    mNumerator *= divider.mDenominator;
    mDenominator *= divider.mNumerator;
    recovery(*this);
    return *this;
}

Fraction& Fraction::operator+(const Fraction& addend) const
{
    int newNumerator = mNumerator * addend.mDenominator + mDenominator * addend.mNumerator;
    int newDenominator = mDenominator * addend.mDenominator;
    Fraction newFraction(newNumerator, newDenominator);
    //recovery(newFraction);
    return newFraction;
}

Fraction& Fraction::operator-(const Fraction& subtrahend) const
{
    int newNumerator = mNumerator * subtrahend.mDenominator - mDenominator * subtrahend.mNumerator;
    int newDenominator = mDenominator * subtrahend.mDenominator;
    Fraction newFraction(newNumerator, newDenominator);
    //recovery(newFraction);
    return newFraction;
}

Fraction& Fraction::operator+=(const Fraction& fraction)
{
    mNumerator = mNumerator * fraction.mDenominator + mDenominator * fraction.mNumerator;
    mDenominator = mDenominator * fraction.mDenominator;
    recovery(*this);
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& Fraction)
{
    mNumerator = mNumerator * Fraction.mDenominator - mDenominator * Fraction.mNumerator;
    mDenominator = mDenominator * Fraction.mDenominator;
    recovery(*this);
    return *this;
}

istream& operator>>(istream& stream, Fraction &Fraction)
{
    stream >> Fraction.mNumerator >> Fraction.mDenominator;
    return stream;
}

ostream& operator<<(ostream& stream, Fraction &Fraction)
{
    stream << Fraction.mNumerator << "/" << Fraction.mDenominator;
    return stream;
}

Fraction& Fraction::operator^(const int power) const
{
    Fraction result((int)pow(mNumerator, power), (int)pow(mDenominator, power));
    return result;
}

Fraction& Fraction::operator^=(const int power)
{
    mNumerator = (int)pow(mNumerator, power);
    mDenominator = (int)pow(mDenominator, power);
    return *this;
}

Fraction& Fraction::operator&(const Fraction& Fraction) const
{
    class Fraction result(mNumerator & Fraction.mNumerator, mDenominator & Fraction.mDenominator);
    return result;
}

Fraction& Fraction::operator&=(const Fraction& Fraction)
{
    mNumerator &= Fraction.mNumerator;
    mDenominator &= Fraction.mDenominator;
    return *this;
}

Fraction& Fraction::operator|(const Fraction& Fraction) const
{
    class Fraction result(mNumerator | Fraction.mNumerator, mDenominator | Fraction.mDenominator);
    return result;
}

Fraction& Fraction::operator|=(const Fraction& Fraction)
{
    mNumerator |= Fraction.mNumerator;
    mDenominator |= Fraction.mDenominator;
    return *this;
}

bool Fraction::operator&&(const Fraction& Fraction) const
{
    return (mNumerator != 0 && Fraction.mNumerator != 0);
}

bool Fraction::operator||(const Fraction& Fraction) const
{
    return (mNumerator != 0 || Fraction.mNumerator != 0);
}

int* Fraction::operator*() const
{
    int value = mNumerator / mDenominator;
    return &value;
}

int& Fraction::operator&() const
{
    int value = mNumerator / mDenominator;
    return value;
}

Fraction::operator double() const
{
    return (double)mNumerator / mDenominator;
}

Fraction::operator float() const
{
    return (float)mNumerator / mDenominator;
}

Fraction::operator int() const
{
    return mNumerator / mDenominator;
}

double Fraction::operator,(const int number) const
{
    return log2(myAbs(mNumerator) * mDenominator) * number;
}

int* Fraction::operator->()
{
    return &mNumerator;
}

void Fraction::operator->*(int& number) const
{
    number *= (mNumerator / mDenominator);
}

int Fraction::operator[](int number) const
{
    return mNumerator * number;
}

int Fraction::operator()(int number) const
{
    return mDenominator * number;
}

int Fraction::myAbs(int number) const
{
    return (number < 0 ? -number : number);
}

int Fraction::getGcd(int first, int second) {
    return (second == 0) ? first : getGcd(second, first % second);
}

Fraction& Fraction::recovery(Fraction& fraction)
{
    if (fraction.mDenominator == 0)
    {
        std::cout << "Denominator can not be zero" << std::endl;
        fraction.mNumerator = 0;
        fraction.mDenominator = 1;
        return fraction;
    }

    fraction.mNumerator = (fraction.mNumerator > 0 && fraction.mDenominator > 0) || (fraction.mNumerator < 0 && fraction.mDenominator < 0) ?
                myAbs(fraction.mNumerator) : -myAbs(fraction.mNumerator);
    fraction.mDenominator = myAbs(fraction.mDenominator);

    int tempGcd;
    tempGcd = getGcd(mNumerator, mDenominator);

    fraction.mNumerator /= tempGcd;
    fraction.mDenominator /= tempGcd;
    return *this;
}

