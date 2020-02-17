//Fadeev Sergey. 2019
//Задача C. Тасовка
//http://neerc.ifmo.ru/teaching/cpp/year2018/sem2/hw/hw4.pdf

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<long long> tempVec;
    string tempStr;
    long long pNum;
    getline(cin, tempStr);
    istringstream ss(tempStr);
    while(ss >> pStr)
    {
        tempVec.push_back(pStr);
    }
    long long sizeFirst = tempVec.size();
    getline(cin, tempStr);
    istringstream st(tempStr);
    vector<long long> vect;
    vect.push_back(0);
    while(st >> pNum)
    {
        vect.push_back(pNum);
    }
    long long sizeSecond = vect.size();
    long long exVal = sizeFirst;
    for (long long k = sizeSecond - 1; k >= 0; --k)
    {
        for(long long i = vect[k]; i < exVal; ++i)
        {
            cout << tempVec[i] << " ";
        }
        exVal = vect[k];
    }
    return 0;
}
