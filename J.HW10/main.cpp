#include <iostream>
#include "ArrayImpl.hpp"
#include "Vector.cpp"

template <class T>
void print(Array<T>& array)
{
    for(int i = 0; i < array.size(); ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

bool less(int a, int b)
{
    return a < b;
}

struct Greater
{
    bool operator()(int a, int b) const
    {
        return b < a;
    }
};

template <class T, class Comparator>
T& minimum(const Array<T>& array, const Comparator& comp)
{
    if(array.size() == 0)
    {
        std::cout << "Attempt to find a minimum in an empty array" << "\n";
        T randomT;
        return randomT;
    }
    T tempMin = array[0];
    for(size_t i = 1; i < array.size(); ++i)
    {
        if(comp(array[i], tempMin))
        {
            tempMin = array[i];
        }
    }
    return tempMin;
}

template <class T>
void flatten(Array<T> array, std::ostream& out)
{
    for(size_t i = 0; i < array.size(); ++i)
    {
        out << array[i] << ' ';
    }
}

template <class T>
void flatten(const Array<Array<T>> array, std::ostream& out)
{
    for(size_t i = 0; i < array.size(); ++i)
    {
        flatten(array[i], std::cout);
    }
    out << std::endl;
}

int main()
{
    char* ch = new char;
    delete ch;
    int x = 4;
    Array<int> firstArray(10, x);
    print(firstArray);

    Array<int> secondArray(firstArray);
    print(secondArray);

    Array<int> thirdArray(10, 100);

    firstArray = thirdArray;
    firstArray[2] = 7;
    print(firstArray);

    std::cout << firstArray.size() << ' ' << secondArray.size() << ' ' << thirdArray.size() << std::endl;

    Array<int> ints1(3);
    ints1[0] = 10;
    ints1[1] = 2;
    ints1[2] = 15;
    int min = minimum(ints1, less);
    int max = minimum(ints1, Greater());
    std::cout << min << ' ' << max << std::endl;

    Array<int> emptyArray(0);
    minimum(emptyArray, less);

    Array<int> ints2(2, 0);
    ints2[0] = 10;
    ints2[1] = 20;
    flatten(ints2, std::cout);
    std::cout << std::endl;

    Array<Array<int>> arrayOfInts(3, ints2);
    flatten(arrayOfInts, std::cout);

    Array<double> doubles(5, 0.0);
    flatten(doubles, std::cout);
    std::cout << std::endl;

    Array<bool> booleans(10, true);
    flatten(booleans, std::cout);
    std::cout << std::endl;

    Array<char> chars(10, '+');
    flatten(chars, std::cout);
    std::cout << std::endl;

    Array<std::string> strings(10, "<3");
    flatten(strings, std::cout);
    std::cout << std::endl;

    Vector vector(1, 2);
    Array<Vector> ArrayVector(2, vector);
    
    flatten(ArrayVector, std::cout);

    return 0;
}