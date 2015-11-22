#ifndef INDEX_H
#define INDEX_H
#include "avl_tree.h"
#include <vector>
#include <string>

class Index
{
private:
    AVL_Tree * masterAVL;
public:
    Index();
    AVL_Tree *& getMaster();
    std::vector<int> * findWord(std::string wordToFind);
};

#endif // INDEX_H
