#include "Vector.h"

Vector::Vector(const int first, const int second)
{
    mFirst = first;
    mSecond = second;
}

std::ostream& operator<<(std::ostream& is, Vector& vector)
{
    is << '(' << vector.getFirst() << ", " << vector.getSecond() << ')';
    return is;
}

int Vector::getFirst()
{
    return mFirst;
}

int Vector::getSecond()
{
    return mSecond;
}