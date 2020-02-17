#include <utility>

#include <iostream>
#include "Cause.h"

Cause::Cause(std::string name, std::string description, int amountAwarded) :
        mName(std::move(name)), mDescription(std::move(description)), mAmountAwarded(amountAwarded) {}

const std::string& Cause::getName() const
{
    return mName;
}
const std::string& Cause::getDescription() const
{
    return mDescription;
}
int Cause::getAmountOfMoney() const
{
    return mAmountAwarded;
}

void Cause::setName(const std::string& name)
{
    mName = name;
}

void Cause::setDescription(const std::string& description)
{
    mDescription = description;
}

void Cause::setAmountOfMoney(int cost)
{
    mAmountAwarded = cost;
}


void Cause::printDetails()
{
    std::cout << mName << ", " << mDescription << ", " << mAmountAwarded << std::endl;
}