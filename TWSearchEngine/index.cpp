#include "index.h"
#include "avl_tree.h"
#include "hashtable.h"
#include <ostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

Index::Index(int i)
{
    //masterVector.reserve(99999999);
    dataStructure = i;
    totalPageCount = 0;
    totalWordCount = 0;
    masterAVL = new AVL_Tree();
    masterHash = new HashTable();
    errorVec.push_back(0);
}

AVL_Tree *& Index::getMasterTree()
{
    return masterAVL;
}

HashTable *&Index::getMasterHash()
{
    return masterHash;
}

std::vector<int> * Index::findWord(std::string wordToFind)
{
    //if its an AVL tree...
    if(dataStructure == 0)
    {
        if(masterAVL->GetNode(wordToFind) != nullptr)
            return &masterAVL->GetNode(wordToFind)->logCount;
        else
        {
            return &errorVec;
        }
    }
    else
    {
        int key = masterHash->hash(wordToFind);
        if(masterHash->getBucket(key) != nullptr)
        {
            return &masterHash->getBucket(key)->GetNode(wordToFind)->logCount;
        }
        else
        {
            return &errorVec;
        }
    }
}

std::vector<std::pair<std::string,int>> * Index::sortByFrequency(std::vector<std::pair<std::string,int>> * freqVector)
{
    struct sort_pred
    {
        bool operator()(const std::pair<std::string,int> &left, const std::pair<std::string,int> &right) {
            return left.second < right.second;
        }
    };
    std::sort(freqVector->begin(), freqVector->end(), sort_pred());
    return freqVector;
}

void Index::ClearIndex()
{
    masterAVL = nullptr;
    masterHash = nullptr;
    masterAVL = new AVL_Tree;
    masterHash = new HashTable;
    std::ofstream clearFile("persisted_index.txt");
    //clearFile.open();
    clearFile.close();
}

void Index::insertItem(std::string term, int pageID)
{
    masterDeque.push_back(std::make_pair(term,pageID));

    if(totalWordCount%1000000 == 0)
    {
        std::cout<<"chunk appended"<<std::endl;
        writeIndexToDisc();
    }

}

void Index::writeIndexToDisc()
{
    std::ofstream saveFile ("persisted_index.txt", std::ofstream::out | std::ofstream::app);
    for(int i = 0; i < masterDeque.size(); i++)
    {
        saveFile << masterDeque.at(i).first << " " << masterDeque.at(i).second<<std::endl;
    }
    masterDeque.clear();
}

void Index::writeStatsToDisc()
{
    std::ofstream saveFile ("persisted_stats.txt");
    saveFile << totalPageCount <<std::endl;
    saveFile << totalWordCount <<std::endl;
}

void Index::readInStatsFile()
{
    std::string line;
    std::ifstream saveFile ("persisted_stats.txt");
    if (saveFile.is_open())
    {
        getline(saveFile,line);
        totalPageCount += std::stoi(line);
        getline(saveFile,line);
        totalWordCount += std::stoi(line);
        saveFile.close();
    }
}

void Index::readInSaveFile(int structureID)
{
    //ClearIndex();
    std::cout<<"LOADING DATA INTO STRUCTURE..."<<std::endl;
    dataStructure = structureID;
    std::string line;
    std::ifstream saveFile ("persisted_index.txt");
    if (saveFile.is_open())
    {
        while ( getline (saveFile,line) )
        {
            std::string buf;
            std::stringstream fullLine(line);
            int iterator = 0;
            std::string term;
            int pageID;
            while(fullLine >> buf)
            {
                if(iterator == 0)
                    term = buf;
                else
                    pageID = std::stoi(buf);
                iterator++;
            }
            if(dataStructure == 0)
            {
                masterAVL->Insert(term,pageID);
            }
            else
            {
                masterHash->insert(term,pageID);
            }
        }
        saveFile.close();
    }
    readInStatsFile();
    if(dataStructure == 0)
        masterAVL->TreeToFrequencyVector();
    else
        masterHash->hashToFrequencyVector();
}

int Index::getDataStructureID()
{
    return dataStructure;
}

void Index::incrementWordCount()
{
    totalWordCount++;
}

void Index::incrementPageCount()
{
    totalPageCount++;
}

int Index::getPageCount()
{
    return totalPageCount;
}

int Index::getWordCount()
{
    return totalWordCount;
}
