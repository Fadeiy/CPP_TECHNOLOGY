#pragma once

#include <string>
#include "InterfacePrint.h"

class Employee : InterfacePrint
{
public:
    Employee() = default;
    Employee(std::string name, std::string address, std::string id, int salary, std::string jobType);

    const std::string& getName() const;
    const std::string& getAddress() const;
    const std::string& getId() const;
    int getSalary() const;
    const std::string& getJobType() const;

    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setId(const std::string& id);
    void setSalary(int salary);
    void setJobType(const std::string& jobType);

    void printDetails() override;

private:
    std::string mName;
    std::string mAddress;
    std::string mId;
    int mSalary;
    std::string mJobType;
};
