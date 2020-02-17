#include <iostream>
#include "FundRaisingDepartment.h"
#include "Office.h"
#include "Event.h"

FundRaisingDepartment::FundRaisingDepartment(std::vector<Employee>& vectorOfEmployee, Office& office, Budget& budget) :
        Department(vectorOfEmployee, office, budget) {}

const Event& FundRaisingDepartment::getEvent() const
{
    return mEvent;
}

void FundRaisingDepartment::setEvent(const Event& cause)
{
    mEvent = cause;
}

void FundRaisingDepartment::checkBudget()
{
    mBudget.printDetails();

}
void FundRaisingDepartment::track()
{
    Department::printDetails();

}
void FundRaisingDepartment::printDetails()
{
    Department::printDetails();
    mEvent.printDetails();
}
