/************************************\
 *   Copyright 2015 Jacob Gonzalez  *
 *             a1687803             *
 * -------------------------------- *
 *          (╯°□°）╯︵ ┻━┻           *
\************************************/

#pragma once

#include "StringUtils.h"
#include "UMLDiv.h"
#include "UMLField.h"
#include "UMLMethod.h"
#include "UMLMember.h"
#include "UMLClass.h"

#include <string>
#include <vector>

class Parser
{
public:
    Parser(std::string filename);
    ~Parser();

    struct UMLTags
    {
        static std::string uclass()
        {
            return "class";
        }
        static std::string upublic()
        {
            return "+";
        }
        static std::string uprivate()
        {
            return "-";
        }

        static std::string udiv()
        {
            return "___";
        }
    };

    int find_class(std::string name);

    std::vector<UMLClass> parse_to_classes();
private:
    std::string _buff;
    std::vector<UMLClass> _classes;
};
