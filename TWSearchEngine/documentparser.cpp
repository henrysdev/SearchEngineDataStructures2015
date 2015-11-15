#include "documentparser.h"
#include <string>
#include <iostream>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <string>
#include <ostream>
#include <sstream>
#include <streambuf>
#include "stemandstopremoval.h"

//using namespace std;

DocumentParser::DocumentParser()
{
    xmlName = "";
    stemStopRemoval = new StemAndStopRemoval();
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
    rapidxml::file<> xmlFile(xmlName.c_str());
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    rapidxml::xml_node<>* firstNode = doc.first_node();
    bool finishedParsingAllPages = false;
    rapidxml::xml_node<>* currentPageNode = firstNode->first_node("page");
    rapidxml::xml_node<>* firstTierNode = currentPageNode->first_node("revision");
    std::string pageText = firstTierNode->first_node("text")->value();
    int pageID = std::stoi(currentPageNode->first_node("id")->value());

    //rapidxml::xml_node<>* secondTierNode = firstTierNode->first_node("contributor");
    while(finishedParsingAllPages == false)
    {
        ParsePage(pageText,pageID);
        if(currentPageNode->next_sibling() == nullptr)
            finishedParsingAllPages = true;
        else
        {
            currentPageNode = currentPageNode->next_sibling();
            firstTierNode = currentPageNode->first_node("revision");
            pageText = firstTierNode->first_node("text")->value();
            pageID = std::stoi(currentPageNode->first_node("id")->value());
        }
    }
    std::cout<<"first node: "<<firstNode->first_attribute()->value()<<std::endl;
    //rapidxml::xml_node<> * firstNode = doc.first_node();
//    rapidxml::xml_document<> doc;
//    doc.parse<0>(xmlFile.data());
//    rapidxml::xml_node<>* root_node = doc.first_node();

}

void DocumentParser::ParsePage(std::string text, int pageID)
{
    std::cout<<"------------NEW PAGE--------------------"<<std::endl;
    std::istringstream textStream(text);
    std::string buf;
    while(textStream >> buf)
    {
        if(stemStopRemoval->IsStopWord(buf) == false)
        {
            std::cout<<buf<<std::endl;
        }
        else
        {
            //std::cout<<buf<<" IS a stop word"<<std::endl;
        }
    }
    std::cout<<"----------------------------------------"<<std::endl;
}
