#include <string>
#include "Date.h"

Date::Date(int day, int month, int year)
{
    mDay = day;
    mMonth = month;
    mYear = year;
}

std::string Date::getString() const
{
    return std::to_string(mDay) + "/" + std::to_string(mMonth) + "/" + std::to_string(mYear);
}

std::ostream& operator<<(std::ostream& stream, const Date& date)
{
    stream << date.getString();
    return stream;
}

int Date::getDay() const
{
    return mDay;
}

int Date::getMonth() const
{
    return mMonth;
}

int Date::getYear() const
{
    return mYear;
}

void Date::setDay(int day)
{
    mDay = day;
}

void Date::setMounth(int month)
{
    mMonth = month;
}

void Date::setYear(int year)
{
    mYear = year;
}