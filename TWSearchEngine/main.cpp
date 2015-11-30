#include <iostream>
#include "documentparser.h"
#include "avl_tree.h"
#include "stemandstopremoval.h"
#include "index.h"
#include "porter2_stemmer.h"
#include "userinterface.h"
#include <vector>
#include <utility>
#include <string>

int main(int argc, char* argv[])
{
    std::cout<<"PARSING AND INDEXING..."<<std::endl;
    DocumentParser * docParser = new DocumentParser;
    UserInterface * userInterface = new UserInterface;
    char* filename = argv[1];
    docParser->ReadInXML(filename);
    userInterface->mainMenu(docParser);
    //docParser->renamePageFiles();
    return 0;
}

