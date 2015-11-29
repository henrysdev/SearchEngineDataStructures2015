#ifndef INDEX_H
#define INDEX_H
#include <utility>
#include "avl_tree.h"
#include "hashtable.h"
#include <vector>
#include <string>

class Index
{
private:
    AVL_Tree * masterAVL;
    HashTable * masterHash;
    int dataStructure;
    int totalPageCount;
    int totalWordCount;
public:
    Index(int i);
    int getDataStructureID();
    void incrementPageCount();
    void incrementWordCount();
    int getPageCount();
    int getWordCount();
    AVL_Tree *& getMasterTree();
    HashTable *&getMasterHash();
    std::vector<int> * findWord(std::string wordToFind);
    std::vector<std::pair<std::string,int>> * sortByFrequency(std::vector<std::pair<std::string,int>> * frequencyVector);
};

#endif // INDEX_H
