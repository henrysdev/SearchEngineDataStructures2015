#include "index.h"
#include "avl_tree.h"
#include <vector>
#include <string>

Index::Index()
{
    masterAVL = new AVL_Tree();
}

AVL_Tree *& Index::getMaster()
{
    return masterAVL;
}

std::vector<int> * Index::findWord(std::string wordToFind)
{
    if(masterAVL->GetNode(wordToFind) != nullptr)
    //if(masterAVL->GetNode(wordToFind)->logCount.empty() == false)
        return &masterAVL->GetNode(wordToFind)->logCount;
    else
    {
        std::vector<int> * newFuckingVector;
        newFuckingVector->push_back(-1);
        return newFuckingVector;
    }
}

