#include "documentparser.h"
#include <string>
#include <iostream>
//#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <string>
#include <ostream>


//using namespace std;

DocumentParser::DocumentParser()
{
    xmlName = "";
}

void DocumentParser::ReadInXML(char *fileName)
{
    std::string toStr = std::string(fileName);
    xmlName = toStr;
    xmlStream.open(fileName);
    char* firstLineTest = new char[100];
    /*
    while(xmlStream.good())
    {
        xmlStream.getline(firstLineTest,5000);
        std::cout<<firstLineTest<<std::endl;

    }
    */
    Parse(firstLineTest);
}

void DocumentParser::Parse(char* line)
{
    int x = 0;
    rapidxml::file<> xmlFile(xmlName.c_str());
    rapidxml::xml_document<> doc;
    //doc.parse<0>(xmlFile.data());
    //rapidxml::xml_node<> * firstNode = doc.first_node();
//    rapidxml::xml_document<> doc;
//    doc.parse<0>(xmlFile.data());
//    rapidxml::xml_node<>* root_node = doc.first_node();

}
