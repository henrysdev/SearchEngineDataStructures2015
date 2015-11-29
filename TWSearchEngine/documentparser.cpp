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
#include "sstream"
#include "index.h"

DocumentParser::DocumentParser()
{
    xmlName = "";
    stemStopRemoval = new StemAndStopRemoval();
    index = new Index(0);
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
    while(finishedParsingAllPages == false)
    {
        ParsePage(pageText,pageID);
        index->incrementPageCount();
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
    //index->getMasterTree()->printTree();
    index->getMasterTree()->TreeToFrequencyVector();
    std::cout<<"DONE with "<<pageCount<<" page"<<std::endl;
}

void DocumentParser::ParsePage(std::string text, int pageID)
{
    pageCount++;
    //std::cout<<pageCount<<std::endl;
    //std::cout<<"------------NEW PAGE--------------------"<<std::endl;
    std::istringstream textStream(text);
    std::string buf;
    while(textStream >> buf)
    {
        //checks first character of term to see if its alphabetic or ( or " or ', otherwise dont index
        //if(!isalpha(buf[0]) && buf[0] != 34 && buf[0] != 96 && buf[0] != 40)
        if(isalpha(buf[0]) || buf[0] == 34 || buf[0] == 96 || buf[0] == 40)
        {
            if(stemStopRemoval->IsStopWord(buf) == false)
            {
                //std::cout<<buf<<std::endl;
                stemStopRemoval->StemWord(buf);
                if(stemStopRemoval->IsStopWord(buf) == false)
                {
                    index->incrementWordCount();
                    if(index->getDataStructureID() == 0)
                        index->getMasterTree()->Insert(buf,pageID);
                    else
                        std::cout<<"hash table fail"<<std::endl;//index->getMasterHash()->createPair(buf,vector<int>);
                }
            }
        }
    }
    //std::cout<<"----------------------------------------"<<std::endl;
}

StemAndStopRemoval * DocumentParser::getStemmer()
{
    return stemStopRemoval;
}

Index * DocumentParser::GetIndex()
{
    return index;
}

std::string DocumentParser::retrievePage(int targetID)
{
    std::string filePath = "WikiDump/page";
    std::stringstream ss;
    ss << targetID;
    std::string s = ss.str();
    filePath.append(s);
    filePath += ".xml";
    std::cout<<"filepath: "<<filePath<<std::endl;
    rapidxml::file<> xmlFile(filePath.c_str());
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    rapidxml::xml_node<>* firstNode = doc.first_node();
    bool finishedParsingAllPages = false;
    rapidxml::xml_node<>* currentPageNode = firstNode->first_node("page");
    rapidxml::xml_node<>* firstTierNode = currentPageNode->first_node("revision");
    std::string pageText = firstTierNode->first_node("text")->value();
    int pageID = std::stoi(currentPageNode->first_node("id")->value());
    return pageText;
}

void DocumentParser::renamePageFiles()
{
    for(int i = 1; i < 235960; i++)
    {
        std::string filePath = "WikiDump/WikiDumpPart";
        std::stringstream ss;
        ss << i;
        std::string s = ss.str();
        filePath.append(s);
        filePath += ".xml";
        //std::cout<<"filepath: "<<filePath<<std::endl;
        rapidxml::file<> xmlFile(filePath.c_str());
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());
        rapidxml::xml_node<>* firstNode = doc.first_node();
        bool finishedParsingAllPages = false;
        rapidxml::xml_node<>* currentPageNode = firstNode->first_node("page");
        rapidxml::xml_node<>* firstTierNode = currentPageNode->first_node("revision");
        std::string pageText = firstTierNode->first_node("text")->value();
        int pageID = std::stoi(currentPageNode->first_node("id")->value());
        int result;
        std::string newFilePath = "WikiDump/page";
        std::stringstream nn;
        nn << pageID;
        std::string n = nn.str();
        newFilePath.append(n);
        newFilePath += ".xml";
        const char* oldname = filePath.c_str();
        const char* newname = newFilePath.c_str();
        result = rename(oldname,newname);
    }
}
