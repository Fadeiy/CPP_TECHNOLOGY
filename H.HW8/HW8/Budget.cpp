#include <iostream>
#include "Budget.h"

Budget::Budget(int budget) : mBudget(budget) {}

int Budget::getBudget() const
{
    return mBudget;
}

void Budget::setBudget(const int budget)
{
    mBudget = budget;
}

void Budget::printDetails()
{
    std::cout << mBudget << std::endl;
}