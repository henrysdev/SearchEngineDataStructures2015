#include "avl_tree.h"
#include <iostream>
#include <string>

AVL_Tree::AVL_Node::AVL_Node(const std::string &theElement, const int id, AVL_Node *lt, AVL_Node *rt, int h)
{
    element = theElement;
    left = lt;
    right = rt;
    height = h;
    logCount.push_back(id);
}

void AVL_Tree::insert(const std::string & term,const int ID, AVL_Node * & t)
{
    if(t == nullptr)
        t = new AVL_Node(term,ID,nullptr,nullptr);
    else if(term.compare(t->element) < 0)
    {
        insert(term,ID,t->left);
        if(height(t->left) - height(t->right) == 2)
        {
            if(term.compare(t->left->element) < 0)
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);
        }
    }
    else if(term.compare(t->element) > 0)
    {
        insert(term,ID,t->right);
        if(height(t->right) - height(t->left) == 2)
        {
            if(term.compare(t->right->element) > 0)
                rotateWithRightChild(t);
            else
                doubleWithRightChild(t);
        }
    }
    else
    {
        t->logCount.push_back(ID);
        //duplicate handling
    }
    t->height = max(height(t->left),height(t->right)) + 1;
}

void AVL_Tree::rotateWithLeftChild(AVL_Node *&k2)
{
    AVL_Node * k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left),height(k2->right)) + 1;
    k1->height = max(height(k1->left),k2->height) + 1;
    k2 = k1;
}

void AVL_Tree::rotateWithRightChild(AVL_Node *&k1)
{
    AVL_Node * k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

void AVL_Tree::doubleWithLeftChild(AVL_Node *&k3)
{
    rotateWithRightChild(k3->left); //case 2
    rotateWithLeftChild(k3); //case 1
}

void AVL_Tree::doubleWithRightChild(AVL_Node *&k1)
{
    rotateWithLeftChild(k1->right); //case 2
    rotateWithRightChild(k1); //case 1
}

void AVL_Tree::Insert(const std::string &x, const int ID)
{
    insert(x,ID,root);
}

int AVL_Tree::height(AVL_Node *t) const
{
    return t == nullptr ? -1: t->height;
}

int AVL_Tree::max(int lhs, int rhs)
{
    return lhs > rhs ? lhs : rhs;
}

AVL_Tree::AVL_Node *AVL_Tree::getRoot()
{
    return root;
}

AVL_Tree::AVL_Node * AVL_Tree::getNode(std::string nodeName)
{
    AVL_Tree::AVL_Node * currentNode = root;
    bool found = false;
    while(found == false)
    {
        if(currentNode == nullptr)
            return nullptr;
        if(nodeName.compare(currentNode->element) < 0)
        {
            currentNode = currentNode->left;
        }
        else if(nodeName.compare(currentNode->element) > 0)
        {
            currentNode = currentNode->right;
        }
        else if(nodeName.compare(currentNode->element) == 0)
        {
            found = true;
        }
    }
    return currentNode;
}

AVL_Tree::AVL_Node * AVL_Tree::GetNode(std::string nodeName)
{
    return getNode(nodeName);
}

void AVL_Tree::PrintTree(AVL_Tree::AVL_Node *& rootNode)
{
    bool hasLeft = false;
    bool hasRight = false;
    if(rootNode == nullptr)
        return;
    else
    {
        if(rootNode->left != nullptr)
        {
            hasLeft = true;
            PrintTree(rootNode->left);
        }
        if(rootNode->right != nullptr)
        {
            hasRight = true;
            PrintTree(rootNode->right);
        }
    }
    if(hasLeft && hasRight)
        std::cout<<"NODE: "<<rootNode->element<<", LEFT: "<<rootNode->left->element<<", RIGHT: "<<rootNode->right->element<<std::endl;
    else if(hasLeft && !hasRight)
        std::cout<<"NODE: "<<rootNode->element<<", LEFT: "<<rootNode->left->element<<", NO RIGHT: "<<std::endl;
    else if(!hasLeft && hasRight)
        std::cout<<"NODE: "<<rootNode->element<<", NO LEFT: "<<", RIGHT: "<<rootNode->right->element<<std::endl;
    else
        std::cout<<"NODE: "<<rootNode->element<<", NO LEFT: "<<", NO RIGHT: "<<std::endl;
}

void AVL_Tree::printTree()
{
    PrintTree(root);
}



