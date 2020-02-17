#include <iostream>
#include "Office.h"

Office::Office(std::string address, int phoneNumber) : mAddress(std::move(address)), mPhoneNumber(phoneNumber) {}

const std::string& Office::getAddress() const
{
    return mAddress;
}
int Office::getPhoneNumber() const
{
    return mPhoneNumber;
}

void Office::setAddress(const std::string& address)
{
    mAddress = address;
}
void Office::setPhoneNumber(const int phoneNumber)
{
    mPhoneNumber = phoneNumber;
}

void Office::printDetails()
{
    std::cout << mAddress << ", " << mPhoneNumber << std::endl;
}