using namespace std;

class Fraction
{
public:
    Fraction(int numerator, int denominator);

    //~Fraction() = default;

    Fraction& operator++(int);
    Fraction& operator--(int);
    Fraction& operator+() const;
    Fraction& operator-() const;
    Fraction& operator++();
    Fraction& operator--();
    Fraction& operator+(const Fraction& Fraction) const;
    Fraction& operator-(const Fraction& Fraction) const;
    Fraction& operator*(const Fraction& secondFraction) const;
    Fraction& operator*(int number) const;
    Fraction& operator/(const Fraction& secondFraction) const;
    Fraction& operator/(int number) const;
    Fraction& operator%(double number) const;
    Fraction& operator+=(const Fraction& fraction);
    Fraction& operator-=(const Fraction& Fraction);
    Fraction& operator*=(const Fraction& fraction);
    Fraction& operator*=(int number);
    Fraction& operator/=(const Fraction& Fraction);
    Fraction& operator%=(double number);
    double operator~() const;
    Fraction& operator&(const Fraction& Fraction) const;
    Fraction& operator|(const Fraction& Fraction) const;
    Fraction& operator^(int power) const;
    Fraction& operator&=(const Fraction& Fraction);
    Fraction& operator|=(const Fraction& Fraction);
    Fraction& operator^=(int power);
    friend istream& operator>>(istream& is, Fraction &Fraction);
    friend ostream& operator<<(ostream& is, Fraction &Fraction);
    Fraction& operator!() const;
    bool operator&&(const Fraction& Fraction) const;
    bool operator||(const Fraction& Fraction) const;
    bool operator==(const Fraction& Fraction) const;
    bool operator!=(const Fraction& Fraction) const;
    bool operator>(const Fraction& Fraction) const;
    bool operator<(const Fraction& Fraction) const;
    bool operator>=(const Fraction& Fraction) const;
    bool operator<=(const Fraction& Fraction) const;
    Fraction& operator=(const Fraction& Fraction);
    int* operator*() const;
    int& operator&() const;
    void operator->*(int& number) const;
    int* operator->();
    double operator,(int number) const;
    explicit operator int() const;
    explicit operator float() const;
    explicit operator double() const;

    int operator[](int number) const;
    int operator()(int number) const;

    int myAbs(int number) const;
    int getGcd(int first, int second);
    Fraction& recovery(Fraction& fraction);

private:
    int mNumerator;
    int mDenominator;
};
