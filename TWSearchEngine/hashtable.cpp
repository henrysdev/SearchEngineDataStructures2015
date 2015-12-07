#include "hashtable.h"
#include "avl_tree.h"

HashTable::HashTable()
{
    buckets = 101;
    indexHashTable = new AVL_Tree*[buckets];
    createHashTable();
}

void HashTable::createHashTable()
{
    for(int i = 0; i < buckets; i++)
    {
        indexHashTable[i] = new AVL_Tree;//nullptr;
    }
}

void HashTable::insert(const std::string & term,const int ID)
{
    int arrayLoc = hash(term);
    indexHashTable[arrayLoc]->Insert(term,ID);
    /*
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
        indexHashTable[arrayLoc]->Insert(term,ID);

    }
    */
}

//this is the hash function that decides where the pair is going to go in the array
AVL_Tree * HashTable::getBucket(int keyValue)
{
    return indexHashTable[keyValue];
}

long HashTable::hash(std::string word)
{
    std::hash<std::string> hashFunction;
    size_t stringHasher = hashFunction(word);
    return stringHasher % buckets;
}

void HashTable::hashToFrequencyVector()
{
    for(int i = 0; i < buckets; i++)
    {
        if(indexHashTable[i] != nullptr)
        {
            indexHashTable[i]->TreeToFrequencyVector();
            std::vector<std::pair<std::string,int>> * subFreqVector = indexHashTable[i]->GetFreqVector();
            frequencyVector.reserve(frequencyVector.size() + subFreqVector->size());
            for(int n = 0; n < subFreqVector->size(); n++)
            {
                frequencyVector.push_back(subFreqVector->at(n));
            }
            /*
            std::vector<std::pair<std::string,int>> * combinedFreqVector;
            combinedFreqVector->reserve( frequencyVector.size() + subFreqVector->size() ); // preallocate memory
            combinedFreqVector->insert( combinedFreqVector->end(), frequencyVector.begin(), frequencyVector.end() );
            combinedFreqVector->insert( combinedFreqVector->end(), subFreqVector->begin(), subFreqVector->end() );
            std::cout<<"";
            */
        }
    }
}

std::vector<std::pair<std::string,int>> * HashTable::GetFreqVector()
{
    return &frequencyVector;
}
