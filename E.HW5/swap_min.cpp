void swapMin(int** array, unsigned int numOfStr, unsigned int lengthOfStr)
{
    int minElement = array[0][0];
    int numberOfStringWithMinElement = 0;
    for(int i = 0; i < numOfStr; ++i)
    {
        for(int k = 0; k < lengthOfStr; ++k)
        {
            if (minElement > array[i][k])
            {
                minElement = array[i][k];
                numberOfStringWithMinElement = i;
            }
        }
    }
    int* tempPointer = *array;
    *array = array[numberOfStringWithMinElement];
    array[numberOfStringWithMinElement] = tempPointer;
}
