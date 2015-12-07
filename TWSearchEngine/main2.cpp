#include <iostream>
#include "documentparser.h"

using namespace std;

int main(int argc, char* argv[])
{
    DocumentParser * docParser = new DocumentParser;
    char* filename = argv[1];
    docParser->ReadInXML(filename);
    return 0;
}



