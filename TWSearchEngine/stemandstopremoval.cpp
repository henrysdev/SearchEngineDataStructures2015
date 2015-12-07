#include "stemandstopremoval.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <unordered_map>
#include <hash_fun.h>
#include "porter2_stemmer.h"

StemAndStopRemoval::StemAndStopRemoval()
{
    std::ifstream stopWords;
    stopWords.open("stopwords.txt");
    char* line = new char[30];
    while(stopWords.good())
    {
        stopWords.getline(line,30);
        stop_tree.Insert(line,0);
    }
    //stop_tree.printTree();
}

bool StemAndStopRemoval::IsStopWord(std::string& word)
{
    if(stop_tree.GetNode(word) == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void StemAndStopRemoval::StemWord(std::string& word)
{
    std::string origWord = word;
    //std::cout<<"ORIG WORD: "<<origWord<<" ,";

    Porter2Stemmer::trim(word);
    Porter2Stemmer::stem(word);

    //std::cout<<"STEM WORD: "<<word<<" "<<word.length()<<std::endl;
    /*
    if(word.length() == 0)
    {
        std::ofstream stopWordsFile;
        stopWordsFile.open("stopwords.txt", std::ios::app);
        stopWordsFile<<origWord<<std::endl;
        stop_tree.Insert(origWord,0);
    }
    */
}

