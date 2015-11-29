#include "hashtable.h"

HashTable::HashTable()
{
    buckets = 153;
}

//creates the hash table of the number of buckets

void HashTable::createHashTable()
{
    pair<string, vector<int>> indexHashTable[buckets];
}

//creates a pair, one string, and one vector of IDlists

void HashTable::createPair(string word, vector<int> IDlist)
{
    pair <string, vector<int>> wordAndPages;
    wordAndPages = make_pair(word, IDlist);
    //hash the word
    int arrayLoc = hash(word);
    indexHashTable[arrayLoc] = wordAndPages;
}

//this is the hash function that decides where the pair is going to go in the array

long HashTable::hash(string word)
{
    std::hash<string> hashFunction;
    size_t stringHasher = hashFunction(word);
    return stringHasher % buckets;
}
