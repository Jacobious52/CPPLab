/************************************\
|*   Copyright 2015 Jacob Gonzalez  *|
|*             a1687803             *|
|* -------------------------------- *|
|*          (╯°□°）╯︵ ┻━┻           *|
\************************************/

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

typedef std::vector<std::string> wordlist;

class ASolver {
public:
    static wordlist::iterator solve(wordlist::iterator begin, wordlist::iterator end, std::string anagram);
    static wordlist::iterator binarySearch(wordlist::iterator begin, wordlist::iterator end, std::string anagram);
};
