#pragma once

#include <iostream>

#include "InterfacePrint.h"
#include "Department.h"
#include "CEO.h"
#include "Office.h"
#include "FundsBalance.h"

class Trust : Department, InterfacePrint
{
public:
    Trust(std::vector<Employee>& vectorOfEmployee, Office& office, Budget& budget);

    const std::string& getName() const;
    const CEO& getCEO() const;
    const Office& getHeadOffice() const;
    const FundsBalance& getFundsBalance() const;

    void setName(const std::string& name);
    void setCEO(const CEO& CEO);
    void setHeaderOffice(const Office& headOffice);
    void setFundsBalance(const FundsBalance& fundsBalance);

    void getMoney();
    void printDetails() override;

private:
    std::string mName;
    CEO mCeo;
    Office mHeadOffice;
    FundsBalance mFundsBalance;
};


