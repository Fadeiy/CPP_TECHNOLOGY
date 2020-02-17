#include <iostream>
#include "mylib4Hw5.h"

char* getline(unsigned int firstSize)
{
    char* line = new char[firstSize];
    unsigned int sizeOfAllocatedMemory = firstSize;
    char tempChar;
    unsigned int position;                          //the position in the line in which we will write
    for(position = 0; std::cin.get(tempChar) && tempChar != '\n'; ++position)
    {
        if(position + 1 == sizeOfAllocatedMemory)//at this string we resize namely when size_of_allocated_memory == position + 1, because
        {                                           //at the end of cycle we should have one free place for zero character
            line = resize(line, sizeOfAllocatedMemory, sizeOfAllocatedMemory *= 2);
        }
        line[position] = tempChar;
    }
    line[position] = '0';
    return resize(line, position + 1, position + 1);
}
