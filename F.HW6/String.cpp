#include <cstring>
#include "String.h"

String::String(const char* receivedStr)
{
    mSize = strlen(receivedStr);
    mStr = new char[mSize + 1];
    strcpy(mStr, receivedStr);
}

String::String(const size_t length, const char ch)
{
    mSize = length;
    mStr = new char[mSize + 1];
    memset(mStr, ch, mSize);
    mStr[mSize] = '\0';
}

String::String(const String& receivedStr)
{
    mSize = receivedStr.mSize;
    mStr = new char[mSize + 1];
    strcpy(mStr, receivedStr.mStr);
    mSize = receivedStr.mSize;
    mStr[mSize] = '\0';
}

String::~String()
{
    delete[] mStr;
}

void String::append(const String& receivedStr)
{
    mSize += receivedStr.mSize;
    char* tempPointer = new char[mSize + 1];
    strcpy(tempPointer, mStr);
    strcat(tempPointer, receivedStr.mStr);
    delete[] mStr;
    mStr = tempPointer;
}
void String::append(const char* receivedStr)
{
    mSize += strlen(receivedStr);
    char* tempPointer = new char[mSize + 1];
    strcpy(tempPointer, mStr);
    strcat(tempPointer, receivedStr);
    delete[] mStr;
    mStr = tempPointer;
}

void String::assign(const String& receivedStr)
{
    if(receivedStr.mSize == mSize)
    {
        strcpy(mStr, receivedStr.mStr);
    }
    else
    {
        mSize = receivedStr.mSize;
        delete[] mStr;
        mStr = new char[mSize];
        strcpy(mStr, receivedStr.mStr);
    }
}

char String::getChar(const int i) const
{
    return mStr[i];
}

size_t String::getSize() const
{
    return mSize;
}

char* String::getString() const
{
    return mStr;
}
