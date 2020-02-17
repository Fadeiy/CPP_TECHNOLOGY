#include <iostream>
#include "GrandDepartment.h"
#include "Office.h"
#include "Cause.h"

GrandDepartment::GrandDepartment(std::vector<Employee>& vectorOfEmployee, Office& office, Budget& budget) :
                      Department(vectorOfEmployee, office, budget) {}

Cause& GrandDepartment::getCause()
{
    return mCause;
}

void GrandDepartment::setCause(const Cause& cause)
{
    mCause = cause;
}
void GrandDepartment::checkBudget()
{
    mBudget.printDetails();

}
void GrandDepartment::track()
{
    Department::printDetails();

}
void GrandDepartment::awardMoney(const int money)
{
    mCause.setAmountOfMoney(money);
}

void GrandDepartment::printDetails()
{
    Department::printDetails();
    mCause.printDetails();
}
