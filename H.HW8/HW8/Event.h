#pragma once

#include "InterfacePrint.h"
#include "FundsBalance.h"
#include "AbstractEventOrCause.h"

class Event : InterfacePrint, AbstractEventOrCause
{
public:
    Event() = default;
    Event(std::string  name, std::string  description, int cost, FundsBalance  fundsBalance);

    const std::string& getName() const override ;
    const std::string& getDescription() const override;
    int getAmountOfMoney() const override;
    const FundsBalance& getFundsBalance() const;


    void setName(const std::string& name) override;
    void setDescription(const std::string& description) override;
    void setAmountOfMoney(int amountOfMoney) override;
    void setFundsBalance(const FundsBalance& fundsBalance);


    void printDetails() override;


private:
    std::string mName;
    std::string mDescription;
    int mCost{};
    FundsBalance mFundsBalance;
};

