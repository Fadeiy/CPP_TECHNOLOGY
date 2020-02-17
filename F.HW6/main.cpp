#include <iostream>
#include "String.h"

int main()
{
    char* toCheckForLeaks = new char[100];
    delete[] toCheckForLeaks;
    String firstString("123456789");
    for(int i = 0; i < firstString.getSize(); i++)
    {
        std::cout << firstString.getChar(i);
    }
    std::cout << "\n";

    String secondString(10, '~');

    for(int i = 0; i < secondString.getSize(); i++)
    {
        std::cout << secondString.getChar(i);
    }
    std::cout << "\n";

    String s1("Hello,");
    String s2(" world!");
    s1.append(s2);

    for(int i = 0; i < s1.getSize(); i++)
    {
        std::cout << s1.getChar(i);
    }
    std::cout << "\n";

    String s("Hello_______________________");
    s.append(s);

    for(int i = 0; i < s.getSize(); i++)
    {
        std::cout << s.getChar(i);
    }
    std::cout << "\n";

    s.assign(s1);

    for(int i = 0; i < s.getSize(); i++)
    {
        std::cout << s.getChar(i);
    }
    std::cout << "\n";

    String s3;
    s3.append("Russkie");
    s3.append(" vpered!");

    char* pointer = s3.getString();

    for(int i = 0; pointer[i] != '\0'; i++)
    {
        std::cout << pointer[i];
    }

    std::cout << "\n";
    std::cout << s3.getSize() << "\n";
    std::cout << ((s3.getChar(15) == '\0') ? "\\0" : "vse ploho") << "\n";
    std::cout << s3.getString() << "\n";

    String s4(s3);
    std::cout << s4.getString() << " s4" << "\n" ;
    s3.append(" Vpered!");
    std::cout << s3.getString() << "\n";
    std::cout << s4.getString() << " s4" << "\n";

    return 0;
}