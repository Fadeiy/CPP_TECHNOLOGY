//Fadeev Sergey. 2019
//Задача B. Роман и Тошибки
//http://neerc.ifmo.ru/teaching/cpp/year2018/sem2/hw/hw4.pdf

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ifstream fin("broken-keyboard.in");
    ofstream fout("broken-keyboard.out");
    int n;
    fin >> n;
    vector <string> arr;
    vector <int> ans;
    int maxL = 0;
    int ll;
    string temp;
    for (int i = 0; i < n; ++i)
    {
        fin >> temp;
        arr.push_back(temp);
        ll = (int)temp.length();
        if (maxL < ll)
        {
            maxL = ll;
        }
        ans.push_back(0);
    }
    ans[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        ll = (int)arr[i].length();
        for (int k = 0; k < ll - maxL; ++k)
            arr[i] += ">";
    }
    for (int i = 1; i < n; ++i)
    {
        if (i != 0 && ((arr[i - 1])[0] != (arr[i])[0]))
        {
            ans[i] = 1;
            continue;
        }
        set<char> st;
        for (int k = 0; k < maxL; ++k)
        {
            if (arr[i - 1][k] != arr[i][k])
            {
                if (!st.count(arr[i][k]))
                    ans[i] = 1;
                break;
            }
            else
            {
                if (st.count(arr[i][k]))
                {
                    break;
                }
                else
                {
                    st.insert(arr[i][k]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (ans[i])
        {
            fout << "YES" << "\n";
        }
        else
        {
            fout << "NO" << "\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}
