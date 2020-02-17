#include "Array.h"
#include <iostream>

template <class T>
Array<T>::Array(size_t size, const T& value)
{
    mSize = size;
    //mData = static_cast<T*>(new char[mSize * sizeof(T)]);
    mData = (T*) new char[mSize * sizeof(T)];
    for(size_t i = 0; i < mSize; ++i)
    {
        new (mData + i) T(value);
    }
}

template <class T>
Array<T>::Array(const Array& array)
{
    mSize = array.mSize;
    //mData = static_cast<T*>(new char[mSize * sizeof(T)]);
    mData = (T*) new char[mSize * sizeof(T)];
    for(size_t i = 0; i < mSize; ++i)
    {
        new (mData + i) T(array.mData[i]);
    }
}

template <class T>
Array<T>::~Array()
{
    cleanMemory(*this);
}

template <class T>
Array<T>& Array<T>::operator=(const Array& array)
{
    delete[] mData;
    mSize = array.size();
    mData = new T[mSize * sizeof(T)];
    for(size_t i = 0; i < mSize; ++i)
    {
        mData[i] = array[i];
    }
    return *this;
}

template <class T>
T& Array<T>::operator[](size_t index)
{
    return mData[index];
}

template <class T>
const T& Array<T>::operator[](size_t index) const
{
    return mData[index];
}

template <class T>
size_t Array<T>::size() const
{
    return mSize;
}

template <class T>
T* Array<T>::data() const
{
    return mData;
}

template <class T>
void Array<T>::cleanMemory(Array<Array<T>>& array)
{
    array.cleanMemory(array);
}

template <class T>
void Array<T>::cleanMemory(Array<T>& array)
{
    delete[] array.data();
}
