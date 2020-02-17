//Fadeev Sergey. 2019
//Задача G. Реверс
//http://neerc.ifmo.ru/teaching/cpp/year2018/sem2/hw/hw4.pdf

#include <fstream>

using namespace std;

int cnt = 0;
int numOfInt;
ifstream fin("reverse.in");
ofstream fout("reverse.out");

void inOutRec()
{
    int num;
    fin >> num;
    ++cnt;
    if (cnt != numOfInt)
    {
        inOutRec();
    }
    fout << num << " ";
    return;
}

int main()
{
    fin >> numOfInt;
    inOutRec();
    fin.close();
    fout.close();
    return 0;
}
