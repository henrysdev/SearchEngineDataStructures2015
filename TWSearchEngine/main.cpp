#include <iostream>
#include "documentparser.h"
#include "avl_tree.h"
#include "stemandstopremoval.h"
#include "index.h"
#include "porter2_stemmer.h"
#include <vector>
#include <string>

int main(int argc, char* argv[])
{
    DocumentParser * docParser = new DocumentParser;
    char* filename = argv[1];
    docParser->ReadInXML(filename);
    while(true)
    {
        std::cout<<"enter a word to find: ";
        std::string user_input;
        std::cin>>user_input;
        Index * index = docParser->GetIndex();
        StemAndStopRemoval * stemmer = docParser->getStemmer();
        stemmer->StemWord(user_input);
        if(user_input.length() <= 1)
            continue;
        std::vector<int> * wordReferences;
        if(index->findWord(user_input))
            wordReferences = index->findWord(user_input);
        else
            wordReferences->push_back(2);
        std::string outputList = "/0";
        std::cout<<"appears on page(s): "<<std::endl;
        for(int i = 0; i < wordReferences->size()-1; i++)
        {
            std::cout<<wordReferences->at(i)<<std::endl;
            //int numToBeAppended = wordReferences->at(i);
            //outputList += numToBeAppended;
            //outputList += " ";
        }
        }
    return 0;
}


