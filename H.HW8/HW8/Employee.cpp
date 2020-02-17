#include <iostream>
#include "Employee.h"

Employee::Employee(std::string name, std::string address, std::string id, int salary, std::string jobType) :
        mName(std::move(name)), mAddress(std::move(address)), mId(std::move(id)),
        mSalary(salary), mJobType(std::move(jobType)) {}

const std::string& Employee::getName() const
{
    return mName;
}
const std::string& Employee::getAddress() const
{
    return mAddress;
}
const std::string& Employee::getId() const
{
    return mId;
}
int Employee::getSalary() const
{
    return mSalary;
}
const std::string& Employee::getJobType() const
{
    return mJobType;
}

void Employee::setName(const std::string& name)
{
    mName = name;
}
void Employee::setAddress(const std::string& address)
{
    mAddress = address;
}
void Employee::setId(const std::string& id)
{
    mId = id;
}
void Employee::setSalary(const int salary)
{
    mSalary = salary;
}
void Employee::setJobType(const std::string& jobType)
{
    mJobType = jobType;
}

void Employee::printDetails()
{
    std::cout << mName << ", " << mAddress << ", " << mId << ", " << mSalary << ", " << mJobType << std::endl;
}