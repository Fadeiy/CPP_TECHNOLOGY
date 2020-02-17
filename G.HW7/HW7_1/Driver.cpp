#include <iostream>
#include "Driver.h"

void Driver::test(PlaneFigure& pf)
{
    std::cout << pf.getArea() << std::endl;
    std::cout << pf.getPerimeter() << std::endl;
}

void Driver::main()
{
    PlaneFigure* pf = new Rect(2, 3);
    test(*pf);
    delete pf;
}