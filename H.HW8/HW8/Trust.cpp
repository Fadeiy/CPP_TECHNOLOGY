#include <iostream>
#include "Trust.h"

Trust::Trust(std::vector<Employee>& vectorOfEmployee, Office& office, Budget& budget) :
Department(vectorOfEmployee, office, budget) {}

void Trust::getMoney()
{
    mFundsBalance.printDetails();
}

const std::string& Trust::getName() const
{
    return mName;
}
const CEO& Trust::getCEO() const
{
    return mCeo;
}
const Office& Trust::getHeadOffice() const
{
    return mHeadOffice;
}

const FundsBalance& Trust::getFundsBalance() const
{
    return mFundsBalance;
}

void Trust::setName(const std::string& name)
{
    mName = name;
}
void Trust::setCEO(const CEO& CEO)
{
    mCeo = CEO;
}
void Trust::setHeaderOffice(const Office& headOffice)
{
    mHeadOffice = headOffice;
}
void Trust::setFundsBalance(const FundsBalance& fundsBalance)
{
    mFundsBalance = fundsBalance;
}

void Trust::printDetails()
{
    Department::printDetails();
    std::cout << mName << std::endl;
    mOffice.printDetails();
    mCeo.printDetails();
    mHeadOffice.printDetails();
    mFundsBalance.printDetails();
}