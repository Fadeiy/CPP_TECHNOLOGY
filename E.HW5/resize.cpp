char* resize(char* pointer2OldMemory, unsigned int size, unsigned int newSize)
{
    char* pointer2NewMemory = new char[newSize];
    for(unsigned int i = 0; i < newSize && i < size; ++i)
    {
        pointer2NewMemory[i] = pointer2OldMemory[i];
    }
    delete[] pointer2OldMemory;
    return pointer2NewMemory;
}
