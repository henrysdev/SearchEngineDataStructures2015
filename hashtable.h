#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <algorithm>
#include <utility>
#include <string>
#include <iostream>
#include <functional>

#include <avl_tree.h>


class HashTable
{
public:
    HashTable();
    void createHashTable();
    //void createPair(std::string, std::vector<int>);
    void insert(const std::string & term,const int ID);
    long hash(std::string);


private:
    int buckets;
    //pair<string, vector<int>> indexHashTable[];
    //pair <string, vector<int>> wordAndPages;
    AVL_Tree * indexHashTable[];
    std::string element;
    std::vector<int>logCount;

};

#endif // HASHTABLE_H
