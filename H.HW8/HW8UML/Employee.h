#pragma once

#include <iostream>
#include <PrintDetails.h>

class Employee
{
public:
    Employee(const std::string name, const std::string address, const std::string id, const int salary, const std::string jobType);

    std::string getName() const;
    std::string getAddress() const;
    std::string getId() const;
    int getSalary() const;
    std::string getJobType() const;

    void setName(const std::string name);
    void setAddress(const std::string address);
    void setId(const std::string id);
    void setSalary(const int salary);
    void setJobType(const std::string jobType);

    void printDetails() : PrintDetails;

private:
    std::string mName;
    std::string mAddress;
    std::string mId;
    int mSalary;
    std::string mJobType;
};
