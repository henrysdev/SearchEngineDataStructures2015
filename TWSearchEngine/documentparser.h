#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "avl_tree.h"
#include "hashtable.h"
#include "stemandstopremoval.h"
#include "index.h"

class DocumentParser
{
private:
    int pageCount;
    std::ifstream xmlStream;
    std::string xmlName;
    StemAndStopRemoval * stemStopRemoval;
    Index * index;
public:
    DocumentParser();
    StemAndStopRemoval * getStemmer();
    void Parse();
    void ReadInXML(char* fileName);
    void ParsePage(std::string text, int pageID);
    Index * GetIndex();
    std::string retrievePage(int targetID);
    void renamePageFiles();
};

#endif // DOCUMENTPARSER_H
