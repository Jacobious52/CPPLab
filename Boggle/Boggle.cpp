//
// Created by Jacob Gonzalez on 27/02/2016.
//

#include "Boggle.h"
#include <fstream>
#include <algorithm>

Boggle::Boggle(Table &t) : board(t) { }

Boggle::~Boggle() { }

void Boggle::print() {
    for (auto r : board) {
        for (auto c : r) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}

void Boggle::loadWords(const char *fname) {
    std::ifstream file(fname);
    std::string line;

    while (getline(file, line)) {
        if (line.size() > 3) {
            std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c) {
                return std::toupper(c);
            });
            if (!line.empty() && line[line.size() - 1] == '\r') {
                line.erase(line.size() - 1);
            }
            if (line.size() > maxWord) {
                maxWord = line.size();
            }
            words.push_back(line);
        }
    }
    file.close();
}

std::vector<std::string> Boggle::findWords() {
    std::vector<std::string> found;

    for (size_t i = 0; i < words.size(); ++i) {
        //std::cout << "check word: " << words[i] << std::endl;
        if (checkWord(words[i])) {
            found.push_back(words[i]);
        }
    }

    return  found;
}

bool Boggle::checkWord(std::string word) {

    // every tile
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[0].size(); ++j) {
            std::vector<std::vector<uint8_t> > visited = {
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
            };
            //std::cout << "start: " << i << ", " << j << " - " << board[i][j] << std::endl;
            if (search(word, 0, (int)i, (int)j, visited)) {
                return true;
            }
        }
    }

    return false;
}

bool Boggle::search(std::string word, size_t c, int x, int y, std::vector<std::vector<uint8_t> > &visited) {
    visited[x][y] = 1;
    if (board[x][y][0] == word[c]) {
        //std::cout << "(" << x << ", " << y << ") - " << c << ": " << word[c] << " == " << board[x][y] << "\t\t";
        if (c == word.size() - 1) {
            //std::cout << "found: " << word << std::endl;
            return true;
        }

        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                int nx = x + i;
                int ny = y + j;
                if (nx > -1 && ny > -1 && nx < 4 && ny < 4) {
                    if (visited[nx][ny] == 0) {
                        //std::cout << i << ", " << i << std::endl;
                        //std::cout << "next: (" << nx << ", " << ny << ") - " << c + 1 << ": " << word[c + 1] << a<<" == " << board[nx][ny] << "\t\t" << std::endl;
                        if (search(word, c + 1, nx, ny, visited)) {
                            return true;
                        }
                    }
                }
            }
        }
    } else {
        return false;
    }

    return false;
}
