/************************************\
 *   Copyright 2015 Jacob Gonzalez  *
 *             a1687803             *
 * -------------------------------- *
 *          (╯°□°）╯︵ ┻━┻           *
\************************************/

#include "Parser.h"

#include <fstream>

 Parser::Parser(std::string filename)
 {
     _buff = StringUtils::readall(filename);
 }

 Parser::~Parser()
 {}

 int Parser::find_class(std::string name)
 {
    for (size_t i = 0; i < _classes.size(); ++i)
    {
        if (_classes[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

std::vector<UMLClass> Parser::parse_to_classes()
{
    // split into classes
    std::vector<std::string> uclasses = StringUtils::split(_buff, UMLTags::uclass());
    for (auto &uclass : uclasses)
    {
        uclass = StringUtils::trim(uclass);

        UMLClass new_class;

        // get class name / inherit
        std::vector<std::string> tokens = StringUtils::split(uclass, " ");
        tokens[0] = StringUtils::trim(tokens[0]);
        new_class.name = tokens[0];
        if (StringUtils::trim(tokens[1]) == "->")
        {
            new_class.parent = StringUtils::trim(tokens[2]);
        }

        // get the members
        // split into lines
        std::vector<std::string> lines = StringUtils::split(uclass, "\n");
        for (auto &line : lines)
        {
            line = StringUtils::trim(line);

            if (line == UMLTags::udiv())
            {
                new_class.members.push_back(new UMLDiv());
            }
            else
            {
                std::vector<std::string> parts = StringUtils::split(line, " ");

                // feild
                if (parts.size() == 4)
                {
                    UMLField *ufield = new UMLField();
                    ufield->name = StringUtils::trim(parts[1]);
                    ufield->type = StringUtils::trim(parts[3]);

                    for (char c : StringUtils::trim(parts[0]))
                    {
                        ufield->modifiers.push_back(std::to_string(c));
                    }

                    new_class.members.push_back(ufield);
                }
                else if (parts.size() == 5)
                {
                    UMLMethod *umeth = new UMLMethod();
                    umeth->name = StringUtils::trim(parts[1]);
                    umeth->type = StringUtils::trim(parts[4]);

                    for (char c : StringUtils::trim(parts[0]))
                    {
                        umeth->modifiers.push_back(std::to_string(c));
                    }

                    // get args
                    std::vector<std::string> args = StringUtils::tokens(parts[2], "(),");
                    for (auto c : args)
                    {
                        umeth->args.push_back(StringUtils::trim(c));
                    }

                    new_class.members.push_back(umeth);
                }
            }
        }

        _classes.push_back(new_class);
    }
    return _classes;
}
