#pragma once
#include <iostream>

class Vector {
public:
    Vector(int first, int second);
    int getFirst();
    int getSecond();
    friend std::ostream& operator<<(std::ostream& is, Vector& vector);
    void operator=(Vector& vector) = delete;
private:
    int mFirst;
    int mSecond;
};
