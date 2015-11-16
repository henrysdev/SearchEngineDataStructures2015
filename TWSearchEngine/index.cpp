#include "index.h"
#include "avl_tree.h"

Index::Index()
{
    masterAVL = new AVL_Tree();
}

AVL_Tree *& Index::getMaster()
{
    return masterAVL;
}

