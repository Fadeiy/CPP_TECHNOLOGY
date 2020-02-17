#pragma once

#include "InterfacePrint.h"
#include "Department.h"
#include "Budget.h"
#include "Event.h"

class FundRaisingDepartment : Department, InterfacePrint
{
public:
    FundRaisingDepartment() = default;
    FundRaisingDepartment(std::vector<Employee>& vectorOfEmployee, Office& office, Budget& budget);

    const Event& getEvent() const;

    void setEvent(const Event& cause);

    void track();
    void checkBudget();

    void printDetails() override;

private:
    Event mEvent;
};
