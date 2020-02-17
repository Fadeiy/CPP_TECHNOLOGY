#include <iostream>
#include "FundsBalance.h"

FundsBalance::FundsBalance(int balance) : mBalance(balance) {}

int FundsBalance::getBalance() const
{
    return mBalance;
}

void FundsBalance::setBalance(const int balance)
{
    mBalance = balance;
}

void FundsBalance::printDetails()
{
    std::cout << mBalance << std::endl;
}