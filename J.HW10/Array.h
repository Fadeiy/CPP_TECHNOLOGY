#pragma once

template <class T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T());
    Array(const Array& array);
    ~Array();

    Array& operator=(const Array& array);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
    T* data() const;
private:
    void cleanMemory(Array<Array<T>>& array);
    void cleanMemory(Array<T>& array);
    size_t mSize;
    T* mData;
};