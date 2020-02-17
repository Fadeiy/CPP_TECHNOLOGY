#include "Person.h"

Person::Person(std::string firstName, std::string secondName, Date birthday, bool Male) : mBirthday(birthday)
{
    mFirstName = std::move(firstName);
    mSecondName = std::move(secondName);
    mMale = Male;
}

std::string Person::getString() const
{
    return mSecondName + " " + mFirstName + ": " + (mMale ? "male" : "female") + " born on " + mBirthday.getString();
}

std::ostream& operator<<(std::ostream& stream, const Person& person)
{
    stream << person.getString();
    return stream;
}

Date Person::getBirthday() const
{
    return mBirthday;
}

std::string Person::getFirstName() const
{
    return mFirstName;
}

std::string Person::getSecondName() const
{
    return mSecondName;
}

void Person::setBirthDay(Date date)
{
    mBirthday = date;
}

void Person::setFirstName(std::string word)
{
    mFirstName = std::move(word);
}

void Person::setSecondName(std::string word)
{
    mSecondName = std::move(word);
}