#include <iostream>
#include <cstdlib>
#include "mylib4Hw5.h"

void coutArray(int** array, int numOfStr, int lengthOfStr)
{
    for(int i = 0; i < numOfStr; ++i)
    {
        for (int k = 0; k < lengthOfStr; ++k)
        {
            std::cout << array[i][k] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    //test of swap_min
    int** array = new int*[3];
    for(int i = 0; i < 3; ++i)
    {
        array[i] = new int[5];
    }
    for(int i = 0; i < 3; ++i)
    {
        for (int k = 0; k < 5; ++k)
        {
            array[i][k] = rand() % 10 + 1;
        }
    }
    array[2][4] = 0;
    coutArray(array, 3, 5);
    swapMin(array, 3, 5);
    coutArray(array, 3, 5);
    for(int i = 0; i < 3; ++i)
    {
        delete[] array[i];
    }
    delete[] array;

    //test of getline
    char* line = getline(10);
    int pos = 0;
    while(line[pos] != '0')
    {
        std::cout << line[pos];
        ++pos;
    }
    std::cout << std::endl;
    delete[] line;

    //test of resize
    unsigned int newSize;
    std::cin >> newSize;
    char* string = new char[26];
    for(int i = 0; i < 26; ++i)
    {
        string[i] = i + 65;
    }
    string = resize(string, 26, newSize);
    for(int i = 26; i < newSize; ++i)
    {
        string[i] = '+';
    }
    for(int i = 0; i < newSize; ++i)
    {
        std::cout << string[i];
    }
    std::cout << std::endl;
    delete[] string;
    return 0;
}
