//Fadeev Sergey. 2019
//Задача E. НОД
//http://neerc.ifmo.ru/teaching/cpp/year2018/sem2/hw/hw4.pdf

#include <fstream>

using namespace std;

int main()
{
    ifstream fin("gcd.in");
    long long a;
    long long b;
    long long c;
    fin >> a >> b;
    fin.close();
    while(a != b)
    {
        if(b > a)
            swap(a, b);
        c = a / b;
        if (c != 1)
            a = a - (c - 1) * b;
        else
            a = a - b;
    }
    ofstream fout("gcd.out");
    fout << a;
    fout.close();
    return 0;
}
