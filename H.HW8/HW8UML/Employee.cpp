#include "Employee.h"

Employee::Employee(const std::string name, const std::string address, const std::string id, const int salary, const std::string jobType) :
        mName(name), mAddress(address), mId(id), mSalary(salary), mJobType(jobType) {}
std::string Employee::getName() const
{
    return mName;
}
std::string Employee::getAddress() const
{
    return mAddress;
}
std::string Employee::getId() const
{
    return mId;
}
int Employee::getSalary() const
{
    return mSalary;
}
std::string Employee::getJobType() const
{
    return mJobType;
}

void Employee::setName(const std::string name)
{
    mName = name;
}
void Employee::setAddress(const std::string address)
{
    mAddress = address;
}
void Employee::setId(const std::string id)
{
    mId = id;
}
void Employee::setSalary(const int salary)
{
    mSalary = salary;
}
void Employee::setJobType(const std::string jobType)
{
    mJobType = jobType;
}

void Employee::printDetails() : PrintDetails
{
    std::cout << mName << ", " << mAddress << ", " << mId << ", " << mSalary << ", " << mJobType << std::endl;
}