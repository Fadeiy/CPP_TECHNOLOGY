//Fadeev Sergey. 2019
//Задача I. Странное число
//http://neerc.ifmo.ru/teaching/cpp/year2018/sem2/hw/hw4.pdf

#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool fl4Wh;
    string str;
    getline(cin, str);
    int num = 0;
    for (int i = 0; i < (int)str.length() - 1; ++i)
    {
        num += ((int)str[i] - 48) * 2;
    }
    num += (int)str[(int)str.length() - 1] - 48;
    cout << num << "\n";
    num = 0;
    for (int i = 0; i < (int)str.length(); ++i)
    {
        if (str[i] == '0')
            continue;
        for(int k = 0; k < (int)str[i] - 48; ++k)
        {
            fl4Wh = true;
            for (int j = 0; j < (int)str.length() - i - 1; ++j)
            {
                cout << 9;
                fl4Wh = false;
            }
            if (fl4Wh)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << " " << 1 << " ";
            }
        }
    }
    return 0;
}
