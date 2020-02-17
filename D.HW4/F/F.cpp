//Fadeev Sergey. 2019
//Задача F. Многочлены
//http://neerc.ifmo.ru/teaching/cpp/year2018/sem2/hw/hw4.pdf

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int str2Int(string str)
{
    int result = 0;
    int curSize = (int)str.length();
    for (char ch : str)
    {
        int temp = (int)ch - 48;
        for (int i = 0; i < curSize - 1; ++i)
        {
            temp *= 10;
        }
        result += temp;
        curSize--;
    }
    return result;
}

int main()
{
    ifstream fin("polynomial.in");
    ofstream fout("polynomial.out");
    int numStr = 0;
    string ss;
    getline(fin, ss);
    numStr = str2Int(ss);
    vector<vector<int>> vectTr;
    for (int k = 0; k < numStr; ++k)
    {
        string tempStr;
        getline(fin, tempStr);
        string splitTempStr;
        splitTempStr.clear();
        vector <string> vect;
        bool flag = false;
        if (tempStr[0] == '+')
        {
            tempStr.erase(0, 1);
        }
        //cout << tempStr;
        int tempStrLength = (int)tempStr.length();
        for(int i = 0; i < tempStrLength; ++i)
        {
            if (tempStr[i] == '+' || tempStr[i] == '-')
            {
                if(flag)
                {
                    vect.push_back(splitTempStr);
                    splitTempStr.clear();
                    flag = false;
                }
                if (tempStr[i] == '+')
                {
                    continue;
                }
                if (tempStr[i] == '-')
                {
                    splitTempStr += '-';
                    continue;
                }
            }
            splitTempStr += tempStr[i];
            flag = true;
        }
        //cout << splitTempStr << "\n";
        vect.push_back(splitTempStr);
        for (string str : vect)
        {

            int powN = 0;
            int powM = 0;
            int numN = 1;
            int mp = 1;
            string num;
            num.clear();
            int strLength = (int)str.length();
            for ( int i = 0; i < strLength; ++i)
            {
                char ch = str[i];
                switch (ch)
                {
                case 'n':
                    if (i + 1 >= strLength)
                    {
                        powN++;
                        break;
                    }
                    if (str[i + 1] == 'm' || str[i + 1] == 'n' || str[i + 1] == '*' || (str[i + 1] >= 48 && str[i + 1] <= 57))
                    {
                        powN++;
                        break;
                    }
                    if(str[i + 1] == '^')
                    {
                        break;
                    }
                    if (str[i - 1] == 'm' || str[i - 1] == 'n' || str[i - 1] == '*' || (str[i - 1] >= 48 && str[i - 1] <= 57))
                    {
                        powN++;
                        break;
                    }
                    break;
                case 'm':
                    if (i + 1 >= strLength)
                    {
                        powM++;
                        break;
                    }
                    if (str[i + 1] == 'm' || str[i + 1] == 'n' || str[i + 1] == '*' || (str[i + 1] >= 48 && str[i + 1] <= 57))
                    {
                        powM++;
                        break;
                    }
                    if(str[i + 1] == '^')
                    {
                        break;
                    }
                    if (str[i - 1] == 'm' || str[i - 1] == 'n' || str[i - 1] == '*' || (str[i - 1] >= 48 && str[i - 1] <= 57))
                    {
                        powM++;
                        break;
                    }
                    break;

                case '^':
                    if (str[i - 1] == 'n')
                    {
                        i++;
                        while(str[i] >= 48 && str[i] <= 57)
                        {
                            num += str[i];
                            i++;
                            if (i >= strLength)
                            {
                                //i--;
                                break;
                            }
                        }
                        i--;
                        powN += str2Int(num);
                        num.clear();
                        break;
                    }
                    if(i - 1 >= 0)
                    if (str[i - 1] == 'm')
                    {
                        i++;
                        while(str[i] >= 48 && str[i] <= 57)
                        {
                            num += str[i];
                            i++;
                            if (i >= strLength)
                            {
                                break;
                            }
                        }
                        i--;
                        powM += str2Int(num);
                        num.clear();
                        break;
                    }
                    break;
                case '-':
                    mp = -1;
                    break;
                default:
                    if (str[i] == '*')
                    {
                        break;
                    }
                    if(i - 1 <= -1 || (str[0] == '-' && i == 1))
                    {
                        num += str[i];
                        i++;
                        if (i >= strLength)
                        {
                            i--;
                            numN *= str2Int(num);
                            num.clear();
                            break;
                        }
                        while(str[i] >= 48 && str[i] <= 57)
                        {
                            num += str[i];
                            i++;
                            if (i >= strLength)
                            {
                                break;
                            }
                        }
                        i--;
                        //cout << str2Int(num) << " " << i << "\n";
                        numN *= str2Int(num);
                        num.clear();
                        break;
                    }

                    if(str[i - 1] == '*' || str[i - 1] == 'n' || str[i - 1] == 'm')
                    {
                        if (str[i] == '0')
                        {
                            numN = 0;
                            //i = str.length();
                            break;
                        }
                        num += str[i];
                        i++;
                        if (i >= strLength)
                        {
                            i--;
                            numN *= str2Int(num);
                            num.clear();
                            break;
                        }
                        while(str[i] >= 48 && str[i] <= 57)
                        {
                            num += str[i];
                            i++;
                            if (i >= strLength)
                            {
                                break;
                            }
                        }
                        i--;
                        numN *= str2Int(num);
                        num.clear();
                        break;
                    }
                }
            }
            numN *= mp;
            vectTr.push_back({powN, powM, numN});
            //cout << str << " |" << powN << " " << powM << " " << numN << "\n";
        }
        map <pair<int, int>, int> res;
        int vectTrSize = (int)vectTr.size();
        for (int i = 0; i < vectTrSize; ++i)
        {
            if (res.count({vectTr[i][0], vectTr[i][1]}))
            {
                //res.at({vectTr[i][0], vectTr[i][1]}) += res[{vectTr[i][0], vectTr[i][1]}];
                res.at({vectTr[i][0], vectTr[i][1]}) += vectTr[i][2];
            }
            else
            {
                res.insert(pair<pair<int, int>,int>({vectTr[i][0], vectTr[i][1]}, vectTr[i][2]));
            }
        }
        int col = 0;
        int n = 0;

        for(pair<pair<int, int>, int> p : res)
        {
            int xyy = 0;
            if (p.second < 0)
            {
                if (p.second == -1)
                {
                    fout << '-';
                }
                else
                {
                    fout << p.second;
                }
                col++;
                n++;
            }
            if (p.second > 0)
            {
                if (n != 0)
                {
                    fout << "+";
                }
                if (p.second != 1)
                {
                    fout << p.second;
                }
                col++;
                n++;
            }
            if (p.second == 1)
            {
                col++;
            }
            if (p.second != 0)
            {
                if (p.first.first == 0)
                {
                    xyy++;
                }
                if (p.first.first == 1)
                {
                    fout << "n";
                }
                if (p.first.first > 1)
                {
                    fout << "n^" << p.first.first;
                }

                if (p.first.second == 0)
                {
                    xyy++;
                }
                if (p.first.second == 1)
                {
                    fout << "m";
                }
                if (p.first.second > 1)
                {
                    fout << "m^" << p.first.second;
                }
                if (p.first.first == 0 && p.first.second == 0)
                {
                    //cout << 1;
                }
            }
                 if (xyy == 2 && (p.second == 1 || p.second == -1))
            {
                 fout << 1;
            }

        }
        if (col == 0)
        {
            fout << 0;
        }

        fout << "\n";
        vectTr.clear();
    }
    fin.close();
    fout.close();
}
