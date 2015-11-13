#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include <iostream>
#include <fstream>
#include <string>

class DocumentParser
{
private:
    std::ifstream xmlStream;
    std::string xmlName;
    std::string fullText;
public:
    DocumentParser();
    void Parse();
    void ReadInXML(char* fileName);
};

#endif // DOCUMENTPARSER_H
