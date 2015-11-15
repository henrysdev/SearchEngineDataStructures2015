#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "stemandstopremoval.h"

class DocumentParser
{
private:
    std::ifstream xmlStream;
    std::string xmlName;
    StemAndStopRemoval * stemStopRemoval;
public:
    DocumentParser();
    void Parse();
    void ReadInXML(char* fileName);
    void ParsePage(std::string text, int pageID);
};

#endif // DOCUMENTPARSER_H
