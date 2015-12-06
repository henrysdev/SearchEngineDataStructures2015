#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <vector>
#include <utility>
#include <string>

class AVL_Tree
{
private:

    class AVL_Node
    {
    public:
        std::string element;
        std::vector<int>logCount;
        AVL_Node * left;
        AVL_Node * right;
        int height;
        AVL_Node();
        AVL_Node(const std::string & theElement, const int id, AVL_Node * lt, AVL_Node * rt, int h=0);
    };
    std::vector<std::pair<std::string,int>> frequencyVector;
    void treeToFrequencyVector(AVL_Tree ::AVL_Node *& rootNode);
    void insert(const std::string &term, const int id, AVL_Node * & t);
    void rotateWithLeftChild(AVL_Node * & k2);
    void rotateWithRightChild(AVL_Node * & k1);
    void doubleWithLeftChild(AVL_Node * & k3);
    void doubleWithRightChild(AVL_Node * & k1);

    AVL_Node * getNode(std::string nodeName);
    int height(AVL_Node * t) const;
    int max(int lhs, int rhs);
    void PrintTree(AVL_Node *&rootNode);
    AVL_Node * root;
public:
    AVL_Node * getRoot();
    AVL_Tree(): root(NULL){}
    void printTree();
    void TreeToFrequencyVector();
    AVL_Node * GetNode(std::string nodeName);
    void Insert(const std::string & x, const int ID);
    std::vector<std::pair<std::string,int>> * GetFreqVector();
};

#endif // AVL_TREE_H
