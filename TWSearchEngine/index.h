#ifndef INDEX_H
#define INDEX_H
#include <utility>
#include "avl_tree.h"
#include "hashtable.h"
#include <vector>
#include <string>
#include <deque>

class Index
{
private:
    AVL_Tree * masterAVL;
    HashTable * masterHash;
    int dataStructure;
    int totalPageCount;
    int totalWordCount;
    std::vector<std::pair<std::string,int>> masterVector;
    std::deque<std::pair<std::string,int>> masterDeque;
public:
    Index(int i);
    int getDataStructureID();
    void incrementPageCount();
    void incrementWordCount();
    void insertItem(std::string term, int pageID);
    void ClearIndex();
    void writeIndexToDisc();
    void writeStatsToDisc();
    void readInSaveFile(int structureID);
    void readInStatsFile();
    int getPageCount();
    int getWordCount();
    AVL_Tree *& getMasterTree();
    HashTable *&getMasterHash();
    std::vector<int>errorVec;
    std::vector<int> * findWord(std::string wordToFind);
    std::vector<std::pair<std::string,int>> * sortByFrequency(std::vector<std::pair<std::string,int>> * frequencyVector);
};

#endif // INDEX_H
