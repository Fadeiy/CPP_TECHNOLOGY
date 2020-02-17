#pragma once

#include "Employee.h"

class Director : Employee
{
public:
    Director(std::string name, std::string address, std::string id, int salary);

    void printDetails() override;
};
