#include "hashtable.h"

HashTable::HashTable()
{
    buckets = 3;
    createHashTable();
}

void HashTable::createHashTable()
{
    for(int i = 0; i < buckets; i++)
    {
        //AVL_Tree * localAVL = new AVL_Tree;
        indexHashTable[i] = nullptr;
    }
}

void HashTable::insert(const std::string & term,const int ID)
{
    int arrayLoc = hash(term);
    //if no AVL tree
    if(indexHashTable[arrayLoc] == nullptr)
    {
        //create AVL tree
        AVL_Tree * bucketTree = new AVL_Tree;
        indexHashTable[arrayLoc] = bucketTree;
        bucketTree->Insert(term,ID);
        //create AVL node
    }
    else
    {
        if(indexHashTable[arrayLoc]->GetNode(term) != nullptr)
        {
            if(indexHashTable[arrayLoc]->GetNode(term)->element.compare(term) == 0)
            {
                logCount.push_back(ID);
                std::cout<<std::endl;
            }
            else if(indexHashTable[arrayLoc]->GetNode(term)->element.compare(term) != 0)
            {
                indexHashTable[arrayLoc]->Insert(term,ID);
            }
        }
    }
}

//this is the hash function that decides where the pair is going to go in the array

long HashTable::hash(std::string word)
{
    std::hash<std::string> hashFunction;
    size_t stringHasher = hashFunction(word);
    return stringHasher % buckets;
}
