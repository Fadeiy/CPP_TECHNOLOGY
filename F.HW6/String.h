#pragma once

#include <cstring>

struct String
{
public:
    String(const char* receivedStr = "");
    String(size_t length, char ch);
    String(const String& receivedStr);
    ~String();

    void append(const String& receivedStr);
    void append(const char* receivedStr);
    void assign(const String& receivedStr);
    char getChar(int i) const;
    size_t getSize() const;
    char* getString() const;

private:
    size_t mSize;
    char* mStr;
};


