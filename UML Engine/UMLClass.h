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


class UMLMember;

class UMLClass
{
public:
    UMLClass() : name(""), parent("")
    {}
    ~UMLClass()
    {}

    std::string name;
    std::string parent;
    std::vector<UMLMember *> members;

    void draw();
};
