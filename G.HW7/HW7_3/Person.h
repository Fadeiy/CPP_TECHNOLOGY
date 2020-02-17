#pragma once

#include <iostream>
#include "Date.h"

class Person
{
public:
    Person(std::string firstName, std::string secondName, Date birthday, bool Male);

    friend std::ostream& operator<<(std::ostream& stream, const Person& person);

    Date getBirthday() const;

    std::string getFirstName() const;
    std::string getSecondName() const;

    void setBirthDay(Date date);
    void setFirstName(std::string word);
    void setSecondName(std::string word);

protected:
    virtual std::string getString() const;

private:
    Date mBirthday;
    bool mMale;
    std::string mFirstName;
    std::string mSecondName;
};