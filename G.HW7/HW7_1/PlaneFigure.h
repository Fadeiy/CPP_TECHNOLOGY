#pragma one

#include <iostream>

class PlaneFigure
{
public:
    virtual double getArea() {return 0;};
    virtual double getPerimeter() {return 0;};
    virtual ~PlaneFigure() = default;
};