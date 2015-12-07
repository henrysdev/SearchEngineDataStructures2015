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
    DocumentParser * docParser = new DocumentParser;
    UserInterface * userInterface = new UserInterface(docParser);
    //docParser->renamePageFiles();
    //std::string filename = "WikiDumpPart9.xml";
    //docParser->ReadInXML(filename);
    userInterface->mainMenu(*docParser);
    //
    return 0;
}

