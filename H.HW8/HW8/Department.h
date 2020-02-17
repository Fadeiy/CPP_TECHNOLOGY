#pragma once

#include <vector>
#include <string>
#include "InterfacePrint.h"
#include "Employee.h"
#include "CEO.h"
#include "Director.h"
#include "Secretary.h"
#include "Office.h"
#include "Budget.h"

class Department : InterfacePrint
{
public:
    Department() = default;
    Department(std::vector<Employee>& vectorOfEmployee, Office& office, Budget& budget);

    const std::vector<Employee>& getVectorOfEmployee();
    const Office& getOffice();
    const Budget& getBudget();

    void setVectorOfEmployee(const std::vector<Employee>& vectorOfEmployee);
    void setOffice(const Office& office);
    void setBudget(const Budget& budget);

    void printDetails() override;

protected:
    std::vector<Employee> mVectorOfEmployee;
    Office mOffice;
    Budget mBudget;

};