//
// Created by Jacob Gonzalez on 27/02/2016.
//

#ifndef BOGGLE_BOGGLE_H
#define BOGGLE_BOGGLE_H

#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::vector<std::string> > Table;

class Boggle {
public:
    Boggle(Table &t);
    ~Boggle();

    void print();
    void loadWords(const char *fname);

    bool checkWord(std::string word);
    bool search(std::string word, size_t c, int x, int y, std::vector<std::vector<uint8_t > > &visited);
    std::vector<std::string> findWords();

    Table board;
    std::vector<std::string> words;
    size_t maxWord;
};


#endif //BOGGLE_BOGGLE_H
