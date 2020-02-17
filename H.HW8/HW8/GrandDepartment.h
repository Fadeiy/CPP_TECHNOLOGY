#pragma once

#include "InterfacePrint.h"
#include "Department.h"
#include "Budget.h"
#include "Cause.h"

class GrandDepartment : Department, InterfacePrint
{
public:
    GrandDepartment() = default;
    GrandDepartment(std::vector<Employee>& vectorOfEmployee, Office& office, Budget& budget);

    Cause& getCause();

    void setCause(const Cause& cause);

    void track();
    void checkBudget();
    void awardMoney(int money);

    void printDetails() override;

private:
    Cause mCause;
};
