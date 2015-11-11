#include "documentparser.h"
#include <string>
#include <iostream>
//#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

using namespace std;

DocumentParser::DocumentParser()
{

}

void DocumentParser::ReadInXML(char *fileName)
{
    xmlName = fileName;
    xmlStream.open(fileName);
    char* firstLineTest = new char[100];
    xmlStream.getline(firstLineTest,5000);
    cout<<firstLineTest<<endl;
    Parse();
}

void DocumentParser::Parse()
{
    int x = 0;
    rapidxml::file<> xmlFile(xmlName.c_str());
//    rapidxml::xml_document<> doc;
//    doc.parse<0>(xmlFile.data());
//    rapidxml::xml_node<>* root_node = doc.first_node();

}
