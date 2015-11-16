#ifndef INDEX_H
#define INDEX_H
#include "avl_tree.h"

class Index
{
private:
    AVL_Tree * masterAVL;
public:
    Index();
    AVL_Tree *& getMaster();
};

#endif // INDEX_H
