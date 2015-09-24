/************************************\
 *   Copyright 2015 Jacob Gonzalez  *
 *             a1687803             *
 * -------------------------------- *
 *          (╯°□°）╯︵ ┻━┻           *
\************************************/

#include "UMLMethod.h"

void UMLMethod::draw()
{
    printf("%s param 0 = %s %s\n", name.c_str(), args[0].c_str(), type.c_str());
}
