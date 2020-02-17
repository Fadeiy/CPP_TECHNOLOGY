#include "Student.h"

Student::Student(std::string firstName, std::string secondName, Date birthday, bool Male, int studentNumber)
        : Person(std::move(firstName), std::move(secondName), birthday, Male)
{
    mStudentNumber = studentNumber;
}

std::string Student::GetString() const
{
    return Person::getString() + ", student number: " + std::to_string(mStudentNumber);
}

int Student::getStudentNumber() const
{
    return mStudentNumber;
}

void Student::setStudentNumber(int number)
{
    mStudentNumber = number;
}