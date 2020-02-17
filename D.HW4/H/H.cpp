//Fadeev Sergey. 2019
//Задача H. СУ-ДО-КУ
//http://neerc.ifmo.ru/teaching/cpp/year2018/sem2/hw/hw4.pdf

#include <iostream>

long arr4Ch[9];
long arr[9][9];

using namespace std;
bool in()
{
    for (int i = 0 ; i < 9; ++i)
    {
        for (int k = 0; k < 9; ++k)
        {
            cin >> arr[i][k];
            if (arr[i][k] > 9 || arr[i][k] < 1)
            {
                arr[i][k] = 1;
                return false;
            }
        }
    }
    return true;
}

void clean()
{
    for (int i = 0; i < 9; ++i)
    {
        arr4Ch[i] = -1;
    }
}

bool check()
{
    long tempS = 0;
    for (int i = 1; i < 9; ++i)
    {
        tempS += arr4Ch[i];
    }
    if (tempS == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkG()
{
    for (int i = 0; i < 9; ++i)
    {
        clean();
        for (int k = 0; k < 9; ++k)
        {
            arr4Ch[arr[i][k] - 1] = 0;
        }
        if (!check())
        {
            return false;
        }
    }
    return true;
}

bool checkV()
{
    for (int i = 0; i < 9; ++i)
    {
        clean();
        for (int k = 0; k < 9; ++k)
        {
            arr4Ch[arr[k][i] - 1] = 0;
        }
        if (!check())
        {
            return false;
        }
    }
    return true;
}

bool checkK()
{
    for(int i = 0; i < 9; i += 3)
    {
        for(int k = 0; k < 9; k += 3)
        {
            clean();
            for(int ii = 0; ii < 3; ++ii)
            {
                for(int kk = 0; kk < 3; ++kk)
                {
                    arr4Ch[arr[i + ii][k + kk] - 1] = 0;
                }
            }
            if (!check())
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    if(!in())
    {
        cout << "No";
        return 0;
    }
    if(!checkG())
    {
        cout << "No";
        return 0;
    }
    if(!checkV())
    {
        cout << "No";
        return 0;
    }
    if(!checkK())
    {
        cout << "No";
        return 0;
    }

    cout << "Yes";
    return 0;
}
