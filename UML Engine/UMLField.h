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

class UMLField : public UMLMember
{
public:
    UMLField() : UMLMember(), name(""), type("")
    {}
    ~UMLField()
    {}

    std::vector<std::string> modifiers;
    std::string name;
    std::string type;

    void draw();
};
