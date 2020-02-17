#pragma once

#include <string>

class AbstractEventOrCause
{
protected:
    virtual const std::string& getName() const {};
    virtual const std::string& getDescription() const {};
    virtual int getAmountOfMoney() const {};

    virtual void setName(const std::string& name) {};
    virtual void setDescription(const std::string& description) {};
    virtual void setAmountOfMoney(int amountOfMoney) {};
};