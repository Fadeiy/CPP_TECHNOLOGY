#pragma once

#include "InterfacePrint.h"

class Budget : InterfacePrint
{
public:
    Budget(int budget);

    int getBudget() const;

    void setBudget(int budget);

    void printDetails() override;

private:
    int mBudget;
};
