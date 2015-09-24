//
//  StringUtils.h
//  TankGame
//
//  Created by Jacob Gonzalez on 11/04/2015.
//  Copyright (c) 2015 Jacob Gonzalez. All rights reserved.
//

#pragma once

#include <string>
#include <vector>

typedef std::vector<std::string> vstring;
// :: static utility class for string manipulation ::
class StringUtils
{
public:
    // : returns num lines in instring :
    static int string_height(std::string instring);
    // : returns num characters of top line :
    static int string_width(std::string instring);
    // : returns a point for height and width :

    // : read lines from a file into a vector :
    static vstring readlines(std::string filename);
    // : read all text file into string :
    static std::string readall(std::string filename);
    // : split a string into a parts by the a multichar delimeter :
    static vstring split(std::string instring, std::string del);
    // : split a string using multiple single delimeters :
    static vstring tokens(std::string instring, std::string del);

    // : methods for removing whitespace from start and end of strings :
    static std::string ltrim(std::string instring, std::string whitespaces);
    static std::string rtrim(std::string instring, std::string whitespaces);
    static std::string trim(std::string instring);
    static std::string trim(std::string instring, std::string whitespaces);

    // : replace all occurances of <from> to <to> in <instring> :
    static std::string replace_all(std::string instring,
     std::string from,
     std::string to);
private:
    static void _recSplit(std::string instring, vstring &parts, std::string del, bool tokens);
};
