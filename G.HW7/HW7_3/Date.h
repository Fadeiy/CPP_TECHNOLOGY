#pragma once

#include <iostream>

class Date
{
public:
    Date(int day, int month, int year);

    std::string getString() const;

    friend std::ostream& operator<<(std::ostream& stream, const Date& date);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int day);
    void setMounth(int month);
    void setYear(int year);

private:
    int mDay;
    int mMonth;
    int mYear;
};