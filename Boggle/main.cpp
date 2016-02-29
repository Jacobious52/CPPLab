#include <iostream>
#include "Boggle.h"

int main() {

    Table b = {
            {"O", "I", "S", "O"},
            {"L", "Y", "Y", "S"},
            {"L", "B", "A", "P"},
            {"H", "T", "Y", "A"}
    };

    Boggle boggle(b);
    boggle.loadWords("/Users/Jacob/Developer/C++/Boggle/words.txt");

    boggle.print();
    auto words = boggle.findWords();

    std::cout << std::endl << "Found Words:" << std::endl << std::endl;

    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}
