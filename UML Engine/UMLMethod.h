/************************************\
 *   Copyright 2015 Jacob Gonzalez  *
 *             a1687803             *
 * -------------------------------- *
 *          (╯°□°）╯︵ ┻━┻           *
\************************************/

#pragma once


#include "UMLMember.h"

#include <string>
#include <vector>

class UMLMethod : public UMLMember
{
public:
    UMLMethod() : UMLMember(), name(""), type("")
    {}
    ~UMLMethod()
    {}

    std::vector<std::string> modifiers;
    std::vector<std::string> args;
    std::string name;
    std::string type;

    void draw();
};
