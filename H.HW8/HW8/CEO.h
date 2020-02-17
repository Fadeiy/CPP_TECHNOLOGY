#pragma once

#include "Employee.h"

class CEO : Employee
{
public:
    CEO() = default;
    CEO(std::string name, std::string address, std::string id, int salary);

    void printDetails() override;
};
