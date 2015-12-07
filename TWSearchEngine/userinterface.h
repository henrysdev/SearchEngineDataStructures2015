#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include "documentparser.h"
#include "avl_tree.h"
#include "stemandstopremoval.h"
#include "index.h"
#include "porter2_stemmer.h"
#include "queryprocessor.h"
#include <vector>
#include <string>

class UserInterface
{
public:
    UserInterface(DocumentParser *docP);
    void mainMenu(DocumentParser &docParser);
    void interactiveMode(DocumentParser *docParser);
    void maintenanceMode(DocumentParser *docParser);
    void WordSearch(DocumentParser *docParser);
    void PrintTopWords(DocumentParser *docParser);
    void PageCount(DocumentParser *docParser);
    void WordCount(DocumentParser *docParser);
    void exit();


private:
    bool hasLoaded;
    std::string userInput;
    QueryProcessor * queryProcessor;
};

#endif // USERINTERFACE_H
