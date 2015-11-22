#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "avl_tree.h"
#include "stemandstopremoval.h"
#include "index.h"

class DocumentParser
{
private:
    std::ifstream xmlStream;
    std::string xmlName;
    StemAndStopRemoval * stemStopRemoval;
    AVL_Tree * masterTree;
    Index * index;
public:
    DocumentParser();
    StemAndStopRemoval * getStemmer();
    void Parse();
    void ReadInXML(char* fileName);
    void ParsePage(std::string text, int pageID);
    Index * GetIndex();
};

#endif // DOCUMENTPARSER_H
