#include <iostream>
#include "documentparser.h"
#include "avl_tree.h"

using namespace std;

int main(int argc, char* argv[])
{
    AVL_Tree * masterAVL = new AVL_Tree();
    string p1 = "aaa";
    string p2 = "aab";
    string p3 = "aac";
    string p4 = "aad";
    masterAVL->Insert(p1,3);
    masterAVL->Insert(p2,4);
    masterAVL->Insert(p3,5);
    masterAVL->Insert(p4,5);
    masterAVL->PrintTree();
    /*
    DocumentParser * docParser = new DocumentParser;
    char* filename = argv[1];
    docParser->ReadInXML(filename);
    */
    return 0;
}
