#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H


#include "documentparser.h"
#include "avl_tree.h"
#include "stemandstopremoval.h"
#include "index.h"
#include "porter2_stemmer.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <utility>

class QueryProcessor
{
public:
    QueryProcessor(DocumentParser *origParser);
    void query();
    bool isCommand(std::string);
    std::vector<std::pair<int, double> > AND(std::vector<int>*, std::vector<int>*);
    std::vector<std::pair<int, double> > OR(std::vector<int>*, std::vector<int>*);
    std::vector<std::pair<int, double> > NOT(std::vector<int>*, std::vector<int>*);
    std::vector<std::pair<int, double> > AND2(std::vector<int>*, std::vector<int>*, std::vector<int>*);
    std::map<int,int> ANDnot(std::vector<int>*, std::vector<int>*);
    std::vector<std::pair<int, double> > NOTand(std::map<int, int> , std::vector<int>*);
    std::vector<std::pair<int, double> > rank(std::map<int, int>);
    void PrintSearchResults(std::vector<std::pair<int, double>> finalVector);
private:
    DocumentParser * docParser;
    std::string booleanCommands[3];
    std::vector<int> finalVector;
    std::map<int, double> printIDFmap;
   // std::vector<int>* final;

};

#endif // QUERYPROCESSOR_H
