#include <iostream>
#include "documentparser.h"
#include "avl_tree.h"

int main(int argc, char* argv[])
{
    AVL_Tree * masterAVL = new AVL_Tree();
    std::string testStrings[] = {"z","b","c","d","aae","fa","al","fds","lmao"};
    for(int i = 0; i < 8; i++)
    {
        masterAVL->Insert(testStrings[i],i);
    }
    masterAVL->printTree();
    /*
    DocumentParser * docParser = new DocumentParser;
    char* filename = argv[1];
    docParser->ReadInXML(filename);
    */
    return 0;
}
