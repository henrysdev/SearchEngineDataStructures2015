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
    QueryProcessor();
    void query(DocumentParser* docParser);
    bool isCommand(std::string);
    std::vector<int> AND(std::vector<int>*, std::vector<int>*);
    std::vector<int> OR(std::vector<int>*, std::vector<int>*);
    std::vector<int> NOT(std::vector<int>*, std::vector<int>*);
    std::vector<int> AND2(std::vector<int>*, std::vector<int>*, std::vector<int>*);
    std::map<int,int> ANDnot(std::vector<int>*, std::vector<int>*);
    std::vector<int> NOTand(std::map<int, int> , std::vector<int>*);
    std::vector<int> rank(std::map<int, int>);
private:
    std::string booleanCommands[3];
   // std::vector<int>* final;

};

#endif // QUERYPROCESSOR_H

