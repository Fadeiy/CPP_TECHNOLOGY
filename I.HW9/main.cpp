#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction n(11, 10);
    cout << n;
    cin >> n;
    n ^= 3;
    cout << "\n";
    cout << n << " " << (int)n << " " << (float)n << " " << (double)n << "\n";
    Fraction q(19, 9);
    int u = 10;
    q->*u;
    cout << u << "\n";
    Fraction number(11, 10);
    cout << *number << "\n";
    cout << &number << "\n";
    cout << (number, 2) << "\n";
    //Fraction secondNumber(10, 13);


    return 0;
}