#include "queryprocessor.h"

QueryProcessor::QueryProcessor()
{
    booleanCommands[0] = "and";
    booleanCommands[1] = "or";
    booleanCommands[2] = "not";
}


// create an AVL index
void QueryProcessor::AVL()
{
    index = new Index(false);
}

// create an HashTable index
void QueryProcessor::HashTable()
{
    index = new Index(true);
}

// this is the boolean AND operation
void QueryProcessor::ANDoperation(unordered_map<string, int>& map1, unordered_map<string, int>& map2)
{
    unordered_map<string,int> final;
    for (auto& x : map1)
    {
        for (auto& y : map2)
        {
            if (x.first == y.first)
            { // insert the item into the new map and add the frequencies
                final.insert(make_pair(x.first, (x.second + y.second)));
            }
        }
    }
    map1 = final;
}

// this is the boolean OR operation which will have all of the items in both lists together
void QueryProcessor::ORoperation(unordered_map<string, int>& map1, unordered_map<string, int>& map2)
{
    // this will add the second map to the first map
    unordered_map<string,int> final;
    for (auto& x: map1)
    {
        final.insert(make_pair(x.first,x.second));
    }
    for (auto& x: map2)
    {
        final.insert(make_pair(x.first,x.second));
    }
    map1=final;
}

// this is the boolean NOT operation, map1 will equal the map without items in the notMap
void QueryProcessor::NOToperation(unordered_map<string, int>& map1, unordered_map<string, int>& notMap)
{
    for (auto& x : map1)
    {
        for (auto& y : notMap)
        {
            if (x.first == y.first)
            { // remove the item from map1
                map1.erase(x.first);
            }
        }
    }
}

bool QueryProcessor::isCommand(string str)
{
    for (int i=0; i<3; i++)
    {
        if (str == booleanCommands[i])
            return true;
    }
    return false;
}



vector<string> QueryProcessor::query(string str)
{
    unordered_map<string, int> temp1;
    unordered_map<string, int> temp2;

    // read in query to stringstream
    stringstream stream(str);
    string temp = "NULL";
    vector<string> words;
    while (stream >> temp)
    {
        words.push_back(temp);
    } // words is now a vector of the words in the query

    string currentCommand =  "NULL";
    for (size_t i = 0; i < words.size(); i++)
    {
        if (isCommand(words[i]) == true)
        {
            currentCommand = words[i];
        }
        else if (i == 0 && isCommand(words[i]) == false)
        {
            temp1 = index->search(words[i]);
        }
        else if (i == 1 && !isCommand(words[i]) == false)
        {
            temp1 = index->search(words[i]);
        }
        else
        {
            temp2 = index->search(words[i]);
            if (currentCommand == booleanCommands[0]) // AND
            {
                ANDoperation(temp1, temp2);
            }
            else if (currentCommand == booleanCommands[1]) // OR
            {
                ORoperation(temp1, temp2);
            }
            else if (currentCommand == booleanCommands[2]) // NOT
            {
                NOToperation(temp1, temp2);
            }
        }
    }

    // now temp1 hold the list of docIDs and frequencies for the query
    return rank(temp1);
}


vector<string> QueryProcessor::rank(unordered_map<string, int> map)
{
    // for calculating the TFIDF for each word
    double frequency;
    double totalTermsInDoc;
    double TF; // = frequency / totalTermsInDoc
    double totalDocs;//something
    int numDocsWithWord = map.size();
    double IDF; // = log e (totalDocs/numDocsWithWord)
    double TFIDF;
    ifstream fin;
    string indexPath;
    string buffer;
    double t;
    unordered_map<string,double> temp;
    vector<string> rankedlist;

    for (auto& x : map)
    {
        fin.open(indexPath);

        // to calculate number of words in the document
        int f = 0;
        while (fin >> buffer)
        {
            f++;
            buffer = "";
        }

        totalTermsInDoc = f;
        fin.close();

        // to calculate TFIDF
        TF = frequency/totalTermsInDoc;
        t = totalDocs/numDocsWithWord;
        IDF = log(t);
        TFIDF = TF*IDF;

        // insert it into new map
        temp.insert(make_pair(x.first,TFIDF));
    }
    // now temp has all of the docs and the TFIDF, but not ranked

    // do RANKING

    return rankedlist;
}
