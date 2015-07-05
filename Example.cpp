#include <cstdio>
#include <string>
#include "Properties.h"

// Test Class--------------

class Test
{
    Property(int, age)
    Property(std::string, name);
};

// Test Class Cpp-----------

Auto_Getter(std::string, name, Test)
Auto_Setter(std::string, name, Test)

Getter(int, age, Test)
{
    return _age;
}

Setter(int, age, Test)
{
    if (age < 0) age = 0;
    _age = age;
}

// Test Class End-----------

int main(int argc, char const *argv[])
{
    Test t;
    t.set_age(4);
    t.set_name("tod");

    printf("%d\n", t.get_age());
    printf("%s\n", t.get_name().c_str());

    return 0;
}

