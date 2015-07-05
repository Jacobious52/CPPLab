//
//  String.cpp
//  Tools
//
//  Created by Jacob Gonzalez on 11/04/2015.
//  Copyright (c) 2015 Jacob Gonzalez. All rights reserved.
//

#include <fstream>
#include <sstream>
#include "String.h"

namespace Tools
{

int String::string_height(std::string instring)
{
    vstring lines = split(instring, "\n");
    return lines.size();
}

int String::string_width(std::string instring)
{
    size_t count = 0;
    count = instring.find_first_of("\n");

    if (count == std::string::npos)
    {
        count = instring.length();
    }

    return count;
}

std::string String::replace_all(std::string instring,
                                     std::string from,
                                     std::string to)
{
    size_t i = 0;
    while ((i = instring.find(from)) != std::string::npos)
    {
        instring.replace(i, from.length(), to);
        i += to.length();
    }
    return instring;
}

std::string String::readall(std::string filename)
{
    std::ifstream file(filename.c_str());
    std::stringstream ss;
    ss << file.rdbuf();
    if (!file)
    {
        return "$NO FILE";
    }
    file.close();
    return ss.str();
}

vstring String::readlines(std::string filename)
{
    vstring lines;
    std::string line;
    std::ifstream file(filename.c_str());

    if (!file)
    {
        return lines;
    }

    while (getline(file, line))
    {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

vstring String::tokens(std::string instring, std::string del)
{
    vstring parts;
    _recSplit(instring, parts, del, true);
    return parts;
}

vstring String::split(std::string instring, std::string del)
{
    vstring parts;
    _recSplit(instring, parts, del, false);
    return parts;
}

void String::_recSplit(std::string instring, vstring &parts,
                            std::string del, bool tokens)
{
    size_t i = !tokens ? instring.find(del) : instring.find_first_of(del);
    if (i == std::string::npos)
    {
        if (!instring.empty())
        {
            parts.push_back(instring);
        }
        return;
    }
    else if (i > 0 && i < instring.length())
    {
         parts.push_back(instring.substr(0, i));
    }

    if (!tokens)
    {
        if (i+del.length() <= instring.length())
        {
            _recSplit(instring.substr(i+del.length()), parts, del, tokens);
        }
    }
    else
    {
        if (i+1 <= instring.length())
        {
            _recSplit(instring.substr(i+1), parts, del, tokens);
        }
    }
}

std::string String::trim(std::string instring, std::string whitespaces)
{
    return ltrim(rtrim(instring, whitespaces), whitespaces);
}

std::string String::ltrim(std::string instring, std::string whitespaces)
{
    size_t i = instring.find_first_not_of(whitespaces);
    if (i == std::string::npos)
    {
        return instring;
    }
    else
    {
        return instring.substr(i, instring.size());
    }
}

std::string String::rtrim(std::string instring, std::string whitespaces)
{
    size_t i = instring.find_last_not_of(whitespaces);
    if (i == std::string::npos)
    {
        return instring;
    }
    else
    {
        return instring.substr(0, i+1);
    }
}

std::string String::trim(std::string instring)
{
    return trim(instring, " \t\n");
}

} // Tools
