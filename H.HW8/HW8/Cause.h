#pragma once

#include "InterfacePrint.h"
#include "AbstractEventOrCause.h"

class Cause : InterfacePrint, AbstractEventOrCause
{
public:
    Cause() = default;
    Cause(std::string name, std::string description, int amountAwarded);

    const std::string& getName() const override ;
    const std::string& getDescription() const override;
    int getAmountOfMoney() const override;

    void setName(const std::string& name) override;
    void setDescription(const std::string& description) override;
    void setAmountOfMoney(int amountOfMoney) override;

    void printDetails() override;


private:
    std::string mName;
    std::string mDescription;
    int mAmountAwarded{};
};

