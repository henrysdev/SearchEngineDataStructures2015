//#ifndef QUERYPROCESSOR_H
//#define QUERYPROCESSOR_H

#include <string>

class QueryProcessor
{
public:
    QueryProcessor();
    vector<string> userQuery(string);
    vector<string>  rank(HashTable<string, int>);
    void createAVLIndex();
    void createHashTableIndex();
    void changeIndex(int);
    void indexFile(string);
    void clearIndex();
    void outputIndex();
    void correctCommand();

private:
    string booleanCommands[3];
};

//#endif // QUERYPROCESSOR_H
