#include "documentparser.h"
#include <string>
#include <iostream>
//#include "rapidxml_iterators.hpp"
//#include "rapidxml_print.hpp"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <string>
#include <ostream>
#include <streambuf>


//using namespace std;

DocumentParser::DocumentParser()
{
    xmlName = "";
}

void DocumentParser::ReadInXML(char *fileName)
{
    std::string toStr = std::string(fileName);
    xmlName = toStr;
    Parse();
}

void DocumentParser::Parse()
{
    int x = 0;
    //const char* cText = fullText.c_str();
    rapidxml::file<> xmlFile(xmlName.c_str());
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    rapidxml::xml_node<>* firstNode = doc.first_node();
    std::cout<<"first node: "<<firstNode->first_attribute()->value()<<std::endl;
    //rapidxml::xml_node<> * firstNode = doc.first_node();
//    rapidxml::xml_document<> doc;
//    doc.parse<0>(xmlFile.data());
//    rapidxml::xml_node<>* root_node = doc.first_node();

}
