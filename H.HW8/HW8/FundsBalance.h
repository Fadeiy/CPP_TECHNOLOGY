#pragma once

#include "InterfacePrint.h"

class FundsBalance : InterfacePrint
{
public:
    FundsBalance() = default;
    FundsBalance(int balance);

    int getBalance() const;

    void setBalance(int balance);

    void printDetails() override;

private:
    int mBalance;
};
