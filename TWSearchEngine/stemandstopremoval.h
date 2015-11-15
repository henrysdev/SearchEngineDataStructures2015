#ifndef STEMANDSTOPREMOVAL_H
#define STEMANDSTOPREMOVAL_H
#include <string>
#include <unordered_map>
#include "avl_tree.h"

class StemAndStopRemoval
{
private:
    std::unordered_map<std::string,int> stop_map;
    AVL_Tree stop_tree;
public:
    StemAndStopRemoval();
    bool IsStopWord(std::string word);
    void StemWord(std::string word);
};

#endif // STEMANDSTOPREMOVAL_H
