#include "Secretary.h"

Secretary::Secretary(std::string name, std::string address, std::string id, int salary) :
        Employee(std::move(name), std::move(address), std::move(id), salary, "Secretary") {}

void Secretary::printDetails()
{
    Employee::printDetails();
}
