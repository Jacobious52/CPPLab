/************************************\
 *   Copyright 2015 Jacob Gonzalez  *
 *             a1687803             *
 * -------------------------------- *
 *          (╯°□°）╯︵ ┻━┻           *
\************************************/

#include "StringUtils.h"
#include "UMLDiv.h"
#include "UMLMember.h"
#include "UMLClass.h"
#include "Parser.h"

#include <string>
#include <vector>

 int main(int argc, char const *argv[])
 {
    if (argc == 2)
    {
        std::string filename(argv[1]);
        Parser parser(filename);
        std::vector<UMLClass> classes = parser.parse_to_classes();

        for (auto &uclass : classes)
        {
            printf("======================\n");

            printf("%s inherits %s\n", uclass.name.c_str(), uclass.parent == "" ? "none" : uclass.parent.c_str());

            for (auto &umem : uclass.members)
            {
                umem->draw();
            }

            printf("======================\n\n");
        }
    }

    return 0;
}
