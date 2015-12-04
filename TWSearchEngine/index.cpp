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
