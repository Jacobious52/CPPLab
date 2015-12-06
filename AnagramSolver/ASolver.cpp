/************************************\
|*   Copyright 2015 Jacob Gonzalez  *|
|*             a1687803             *|
|* -------------------------------- *|
|*          (╯°□°）╯︵ ┻━┻           *|
\************************************/

#include "ASolver.h"

wordlist::iterator ASolver::solve(wordlist::iterator begin, wordlist::iterator end, std::string anagram) {
    // sort anagram so we can permute it
    std::sort(anagram.begin(), anagram.end());
    do {
        auto result = binarySearch(begin, end, anagram); // equal range is binary search but STL style
        if (result != end) {
            return result;
        }
    } while (std::next_permutation(anagram.begin(), anagram.end()));

    return end;
}

wordlist::iterator ASolver::binarySearch(wordlist::iterator begin, wordlist::iterator end, std::string anagram) {
    // iterative bin search because we need to keep the end for notFound
    const auto notFound = end;

    while (begin < end) {

        const auto mid = begin + (std::distance(begin, end) / 2);
        if (*mid == anagram) {
            return mid;
        }
        else if (*mid > anagram) {
            end = mid;
        }
        else {
            begin = mid + 1;
        }
    }

    return notFound;
}
