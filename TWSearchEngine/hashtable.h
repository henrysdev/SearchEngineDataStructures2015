#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <algorithm>
#include <utility>
#include <string>
#include <iostream>
#include <functional>
#include <iomanip>
#include <avl_tree.h>


class HashTable
{
public:
    HashTable();
    void createHashTable();
    //void createPair(std::string, std::vector<int>);
    void insert(const std::string & term,const int ID);
    long hash(std::string);
    AVL_Tree * getBucket(int keyValue);
    void hashToFrequencyVector();
    std::vector<std::pair<std::string,int>> * GetFreqVector();

private:
    int buckets;
    //pair<string, vector<int>> indexHashTable[];
    //pair <string, vector<int>> wordAndPages;
    std::vector<std::pair<std::string,int>> frequencyVector;
    AVL_Tree ** indexHashTable;

};

#endif // HASHTABLE_H
