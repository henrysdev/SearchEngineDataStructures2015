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
    index = new Index(1);
}

void DocumentParser::ReadInXML(std::string fileName)
{
    std::string toStr = std::string(fileName);
    xmlName = toStr;
    Parse();
}

void DocumentParser::Parse()
{
    std::cout<<"PARSING AND INDEXING..."<<std::endl;
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
    //index->getMasterTree()->TreeToFrequencyVector();
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
            if(buf.size() > 1)
            {
                if(stemStopRemoval->IsStopWord(buf) == false)
                {
                    //return;
                    //std::cout<<"before stem: "<<buf;
                    stemStopRemoval->StemWord(buf);
                    //std::cout<<", after stem: "<<buf<<std::endl;
                    index->incrementWordCount();
                    if(index->getDataStructureID() == 0)
                        index->getMasterTree()->Insert(buf,pageID);
                    else
                        index->getMasterHash()->insert(buf,pageID);
                }
            }
        }
        //else
        //    return;
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
    //std::cout<<"filepath: "<<filePath<<std::endl;
    rapidxml::file<> xmlFile(filePath.c_str());
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    rapidxml::xml_node<>* firstNode = doc.first_node();
    bool finishedParsingAllPages = false;
    rapidxml::xml_node<>* currentPageNode = firstNode->first_node("page");
    std::string title = currentPageNode->first_node("title")->value();
    rapidxml::xml_node<>* firstTierNode = currentPageNode->first_node("revision");
    std::string pageText = firstTierNode->first_node("text")->value();
    int pageID = std::stoi(currentPageNode->first_node("id")->value());
    return pageText;
}

std::string DocumentParser::getFileName(int targetID)
{
    std::string filePath = "WikiDump/page";
    std::stringstream ss;
    ss << targetID;
    std::string s = ss.str();
    filePath.append(s);
    filePath += ".xml";
    return filePath;
}

std::string DocumentParser::retrieveAttribute(int targetID, int attributeID)
{
    std::string filePath = "WikiDump/page";
    std::stringstream ss;
    ss << targetID;
    std::string s = ss.str();
    filePath.append(s);
    filePath += ".xml";
    rapidxml::file<> xmlFile(filePath.c_str());
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    rapidxml::xml_node<>* firstNode = doc.first_node();
    rapidxml::xml_node<>* currentPageNode = firstNode->first_node("page");
    rapidxml::xml_node<>* revisionPageNode = currentPageNode->first_node("revision");
    if(attributeID == 0)
    {
        std::string title = currentPageNode->first_node("title")->value();
        return title;
    }
    else if(attributeID == 1)
    {
        std::string timestamp = revisionPageNode->first_node("timestamp")->value();
        return timestamp;
    }
    else if(attributeID == 2)
    {
        rapidxml::xml_node<>* contributorPageNode = revisionPageNode->first_node("contributor");
        rapidxml::xml_node<>* usernamePageNode = contributorPageNode->first_node("username");
        std::string username = "Unknown Author";
        if(usernamePageNode != nullptr)
        {
            username = usernamePageNode->value();
        }
        return username;
    }
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
