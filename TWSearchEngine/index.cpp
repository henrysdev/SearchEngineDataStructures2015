#include "index.h"
#include "avl_tree.h"
#include "hashtable.h"
#include <vector>
#include <algorithm>
#include <string>

Index::Index(int i)
{
    dataStructure = i;
    totalPageCount = 0;
    totalWordCount = 0;
    if(i == 0)
        masterAVL = new AVL_Tree();
    else
        masterHash = new HashTable();
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
        //if(masterAVL->GetNode(wordToFind)->logCount.empty() == false)
            return &masterAVL->GetNode(wordToFind)->logCount;
        else
        {
            return nullptr;
            /*
            std::vector<int> * newVector;
            newVector->push_back(-1);
            return newVector;
            */
        }
    }
    else
    {
        std::cout<<"hash table fail"<<std::endl;
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
