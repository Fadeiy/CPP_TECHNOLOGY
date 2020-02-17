#include <utility>
#include <iostream>
#include "Department.h"

Department::Department(std::vector<Employee>& vectorOfEmployee, Office& office, Budget& budget) :
                        mVectorOfEmployee(std::move(vectorOfEmployee)), mOffice(office), mBudget(budget) {}

const std::vector<Employee>& Department::getVectorOfEmployee()
{
    return mVectorOfEmployee;
}
const Office& Department::getOffice()
{
    return mOffice;
}
const Budget& Department::getBudget()
{
    return mBudget;
}

void Department::setVectorOfEmployee(const std::vector<Employee>& vectorOfEmployee)
{
    mVectorOfEmployee = vectorOfEmployee;
}
void Department::setOffice(const Office& office)
{
    mOffice = office;
}
void Department::setBudget(const Budget& budget)
{
    mBudget = budget;
}

void Department::printDetails()
{
    std::cout << "Employees:" << std::endl;
    for(Employee tempEmployee : mVectorOfEmployee)
    {
        tempEmployee.printDetails();
    }
    std::cout << "Office: ";
    mOffice.printDetails();
    std::cout << "Budget: ";
    mBudget.printDetails();
}