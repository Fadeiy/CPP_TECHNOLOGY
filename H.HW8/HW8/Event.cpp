#include <utility>

#include <iostream>
#include "Event.h"

Event::Event(std::string name, std::string  description, int cost, FundsBalance  fundsBalance) :
          mName(std::move(name)), mDescription(std::move(description)), mCost(cost), mFundsBalance(std::move(fundsBalance)) {}

const std::string& Event::getName() const
{
    return mName;
}
const std::string& Event::getDescription() const
{
    return mDescription;
}
int Event::getAmountOfMoney() const
{
    return mCost;
}
const FundsBalance& Event::getFundsBalance() const
{
    return mFundsBalance;
}

void Event::setName(const std::string& name) {
    Event::mName = name;
}

void Event::setDescription(const std::string& description) {
    Event::mDescription = description;
}

void Event::setAmountOfMoney(int cost) {
    Event::mCost = cost;
}

void Event::setFundsBalance(const FundsBalance& fundsBalance) {
    Event::mFundsBalance = fundsBalance;
}

void Event::printDetails()
{
    std::cout << mName << ", " << mDescription << ", " << mCost << std::endl;
    std::cout << "Funds balance: ";
    mFundsBalance.printDetails();
}