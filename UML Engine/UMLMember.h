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


class UMLMember
{
public:
    UMLMember()
    {}
    virtual ~UMLMember()
    {}

    virtual void draw();
};
