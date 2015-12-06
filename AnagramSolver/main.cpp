/************************************\
|*   Copyright 2015 Jacob Gonzalez  *|
|*             a1687803             *|
|* -------------------------------- *|
|*          (╯°□°）╯︵ ┻━┻           *|
\************************************/

#include "ASolver.h"
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "pls give 1 word so it can be timed against sam's" << std::endl;
        return 0;
    }

    // just load in the word list here.. who cares
    std::ifstream file("words.txt");
    if (file) {
        wordlist words;
        std::string line;

        while (getline(file, line)) {
            // remove new lines. avoiding it the don't have any
            if (*line.end() == '\n') {
                line.erase(line.end());
            }
            words.push_back(line);
        }

        //solve
        std::string word(argv[1]);
        std::cout << "trying for: " << word << std::endl;
        wordlist::iterator solved = ASolver::solve(words.begin(), words.end(), word);

        if (solved == words.end()) {
            std::cout << "not found" << std::endl;
        } else {
            std::cout << "found: " << *solved << std::endl;
        }

    } else {
        std::cout << "missing words.txt" << std::endl;
    }

    return 0;
}
