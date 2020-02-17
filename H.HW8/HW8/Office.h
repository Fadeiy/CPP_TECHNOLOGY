#pragma once

#include "InterfacePrint.h"

class Office : InterfacePrint
{
public:
    Office() = default;
    Office(std::string address, int phoneNumber);

    const std::string& getAddress() const;
    int getPhoneNumber() const;

    void setAddress(const std::string& address);
    void setPhoneNumber(int phoneNumber);


    void printDetails() override;

private:
    std::string mAddress;
    int mPhoneNumber{};
};

