#include <iostream>

struct Foo
{
    void say() const
    {
        std::cout << "Foo says: " << msg << "\n";
    }

protected:
    Foo(const char* msg) : msg(msg) {}

private:
    const char* msg;
};

void foo_says(const Foo& foo)
{
    foo.say();
}

struct HeirOfFoo : Foo
{
    HeirOfFoo(const char* msg) : Foo(msg) {}
};

HeirOfFoo get_foo(const char* msg)
{
    return HeirOfFoo(msg);
}

int main()
{
    const char* msg = "Privetik!";
    foo_says(get_foo(msg));
    return 0;
}