#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <algorithm>
#include <utility>
#include <string>
#include <iostream>
#include <functional>

using namespace std;


class HashTable
{
public:
    HashTable();
    void createHashTable();
    void createPair(string, vector<int>);
    long hash(string);


private:
    int buckets;
    pair<string, vector<int>> indexHashTable[];
    pair <string, vector<int>> wordAndPages;

};

#endif // HASHTABLE_H
