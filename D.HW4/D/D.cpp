//Fadeev Sergey. 2019
//Задача D. Кроссворды
//http://neerc.ifmo.ru/teaching/cpp/year2018/sem2/hw/hw4.pdf

#include <fstream>
#include <string>

using namespace std;

int main()
{
    int result = 0;
    ifstream fin("crosswords.in");
    string s1, s2, s3, s4;
    fin >> s1 >> s2 >> s3 >> s4;
    fin.close();
    string xu[12][4] = {
    {s1, s2, s3, s4},
    {s1, s2, s4, s3},
    {s1, s3, s2, s4},
    {s1, s3, s4, s2},
    {s1, s4, s2, s3},
    {s1, s4, s3, s2},
    //1243xu(s2, s1, s3, s4); //note that the answer for the matrix
    //1234xu(s2, s1, s4, s3); //equal to the answer for the transposed matrix
    {s2, s3, s1, s4},         //let's find the answer for 4! / 2 cases
    {s2, s3, s4, s1},         //of transposition of words
    {s2, s4, s1, s3},
    {s2, s4, s3, s1},
    //xu(s3, s1, s2, s4);
    //xu(s3, s1, s4, s2);
    //xu(s3, s2, s1, s4);
    //xu(s3, s2, s4, s1);
    {s3, s4, s1, s2},
    {s3, s4, s2, s1}
    //xu(s4, s1, s2, s3);
    //xu(s4, s1, s3, s2);
    //xu(s4, s2, s1, s3);
    //xu(s4, s2, s3, s1);
    //xu(s4, s3, s1, s2);
    //xu(s4, s3, s2, s1);
    };

    for (int o = 0; o < 12; ++o)
    {
        int len1 = (int)xu[o][0].length();
        int len2 = (int)xu[o][1].length();
        int len3 = (int)xu[o][2].length();
        int len4 = (int)xu[o][3].length();
        for (int i = 0; i < len1 - 1; ++i)
        {
            for (int j = 0; j < len2 - 1; ++j)
            {
                if (xu[o][0][i] != xu[o][1][j])
                {
                    continue;
                }
                for (int k = j + 1; k < len2; ++k)
                {
                    for (int m = 0; m < len3 - 1; ++m)
                    {
                        if (xu[o][1][k] != xu[o][2][m])
                        {
                            continue;
                        }
                        for (int n = m + 1; n < len3; ++n)
                        {
                            if (i + n - m >= len1)
                            {
                                break;
                            }
                            for (int s = len4 - 1; s >= 1; --s)
                            {
                                if (s + j - k < 0)
                                {
                                    break;
                                }
                                if (xu[o][0][i + n - m] != xu[o][3][s + j - k] || xu[o][2][n] != xu[o][3][s])
                                {
                                continue;
                                }
                                result++;
                            }
                        }
                    }
                }
            }
        }
    }
    ofstream fout("crosswords.out");
    fout << result * 2;
    fout.close();
}
