#include "queryprocessor.h"

QueryProcessor::QueryProcessor()
{
    booleanCommands[0] = "AND";
    booleanCommands[1] = "OR";
    booleanCommands[2] = "NOT";

}

bool QueryProcessor::isCommand(std::string command)
{
    for(int i = 0; i < 3; i++)
    {
        if(command == booleanCommands[i])
        {
            return true;
        }
    }
    return false;
}

//std::vector<int> QueryProcessor::AND(std::vector<int>* ref1, std::vector<int>* ref2)
//{
//    std::vector<int> final;
//    for(int i = 0; i < ref1->size()-1; i++)
//    {
//        for(int j = 0; j < ref2->size()-1; j++)
//        {
//            if(ref1->at(i) == ref2->at(j))
//            {
//                final.push_back(ref1->at(i));
//            }
//        }
//    }
//    sort( final.begin(), final.end() );
//    final.erase( unique( final.begin(), final.end() ), final.end() );
//    return final;
//}

std::vector<int> QueryProcessor::AND(std::vector<int>* ref1, std::vector<int>* ref2)
{
    std::vector<int> refx;
    std::vector<int> refy;

    for(int i = 0; i < ref1->size(); i++)
    {
        refx.push_back(ref1->at(i));
    }
    for(int i = 0; i < ref2->size(); i++)
    {
        refy.push_back(ref2->at(i));
    }

    std::map<int, int> finalmap;
    std::map<int, int> occurances1;
    for(int i : refx)
        occurances1[i]++;
    std::map<int, int> occurances2;
    for(int i : refy)
        occurances2[i]++;

    for(auto& keyvalue1 : occurances1)
    {
        for(auto& keyvalue2 : occurances2)
        {
            if(keyvalue1.first == keyvalue2.first)
            {
                finalmap.insert(std::make_pair(keyvalue1.first, (keyvalue1.second + keyvalue2.second)));
            }
        }
    }

    return rank(finalmap);

//    std::vector<int> finalVector = rank(occurances);

//    sort(ref1->begin(), ref1->end());
//    sort(ref2->begin(), ref2->end());
//    unique_copy(ref1->begin(), ref1->end(), std::back_inserter(refx));
//    unique_copy(ref2->begin(), ref2->end(), std::back_inserter(refy));
//    std::set_intersection(refx.begin(),refx.end(), refy.begin(), refy.end(), std::back_inserter(final));

//    return final;
}

std::vector<int> QueryProcessor::AND2(std::vector<int>* ref1, std::vector<int>* ref2, std::vector<int>* ref3)
{
    std::vector<int> almostfinal;
    std::vector<int> final;
    std::vector<int> refx;
    std::vector<int> refy;
    std::vector<int> refz;

    for(int i = 0; i < ref1->size(); i++)
    {
        refx.push_back(ref1->at(i));
    }
    for(int i = 0; i < ref2->size(); i++)
    {
        refy.push_back(ref2->at(i));
    }
    for(int i = 0; i < ref3->size(); i++)
    {
        refz.push_back(ref3->at(i));
    }

    std::map<int, int> almostfinalmap;
    std::map<int, int> occurances1;
    for(int i : refx)
        occurances1[i]++;
    std::map<int, int> occurances2;
    for(int i : refy)
        occurances2[i]++;
    std::map<int, int> occurances3;
    for(int i : refz)
        occurances3[i]++;

    for(auto& keyvalue1 : occurances1)
    {
        for(auto& keyvalue2 : occurances2)
        {
            if(keyvalue1.first == keyvalue2.first)
            {
                almostfinalmap.insert(std::make_pair(keyvalue1.first, (keyvalue1.second + keyvalue2.second)));
            }
        }
    }
    std::map<int, int> finalmap;
    for(auto& keyvalue1 : almostfinalmap)
    {
        for(auto& keyvalue2 : occurances3)
        {
            if(keyvalue1.first == keyvalue2.first)
            {
                finalmap.insert(std::make_pair(keyvalue1.first, (keyvalue1.second + keyvalue2.second)));
            }
        }
    }

    return rank(finalmap);

//    sort(ref1->begin(), ref1->end());
//    sort(ref2->begin(), ref2->end());
//    sort(ref3->begin(), ref3->end());
//    unique_copy(ref1->begin(), ref1->end(), std::back_inserter(refx));
//    unique_copy(ref2->begin(), ref2->end(), std::back_inserter(refy));
//    unique_copy(ref3->begin(), ref3->end(), std::back_inserter(refz));

//    std::set_intersection(refx.begin(),refx.end(), refy.begin(), refy.end(), std::back_inserter(almostfinal));
//    std::set_intersection(almostfinal.begin(),almostfinal.end(), refz.begin(), refz.end(), std::back_inserter(final));
//    return final;
}

//std::vector<int> QueryProcessor::OR(std::vector<int>* ref1, std::vector<int>* ref2)
//{
//    std::vector<int> final;
//    for(int i = 0; i < ref1->size()-1; i++)
//    {
//        final.push_back(ref1->at(i));
//    }

//    for(int i = 0; i < ref2->size()-1; i++)
//    {
//        final.push_back(ref2->at(i));
//    }

//    //delete duplicates

//    return final;
//}

std::vector<int> QueryProcessor::OR(std::vector<int>* ref1, std::vector<int>* ref2)
{
    std::vector<int> refx;
    std::vector<int> refy;

    for(int i = 0; i < ref1->size(); i++)
    {
        refx.push_back(ref1->at(i));
    }
    for(int i = 0; i < ref2->size(); i++)
    {
        refy.push_back(ref2->at(i));
    }

    std::map<int, int> finalmap;
    std::map<int, int> occurances1;
    for(int i : refx)
        occurances1[i]++;
    std::map<int, int> occurances2;
    for(int i : refy)
        occurances2[i]++;

    for(auto& keyvalue : occurances1)
    {
        finalmap.insert(std::make_pair(keyvalue.first, keyvalue.second));
    }
    for(auto& keyvalue : occurances2)
    {
        finalmap.insert(std::make_pair(keyvalue.first, keyvalue.second));
    }

    return rank(finalmap);


//    std::vector<int> final;
//    std::vector<int> refx;
//    std::vector<int> refy;
//    sort(ref1->begin(), ref1->end());
//    sort(ref2->begin(), ref2->end());
//    unique_copy(ref1->begin(), ref1->end(), std::back_inserter(refx));
//    unique_copy(ref2->begin(), ref2->end(), std::back_inserter(refy));
//    std::set_union(refx.begin(),refx.end(), refy.begin(), refy.end(), std::back_inserter(final));
//    return final;
}


std::vector<int> QueryProcessor::NOT(std::vector<int>* ref1, std::vector<int>* ref2)
{
    std::vector<int> refx;
    std::vector<int> refy;

    for(int i = 0; i < ref1->size(); i++)
    {
        refx.push_back(ref1->at(i));
    }
    for(int i = 0; i < ref2->size(); i++)
    {
        refy.push_back(ref2->at(i));
    }

    std::map<int, int> occurances1;
    for(int i : refx)
        occurances1[i]++;
    std::map<int, int> occurances2;
    for(int i : refy)
        occurances2[i]++;

    for(auto& keyvalue1 : occurances1)
    {
        for(auto& keyvalue2 : occurances2)
        {
            if(keyvalue1.first == keyvalue2.first)
            {
                occurances1.erase(keyvalue1.first);
            }
        }
    }

    return rank(occurances1);

//    std::vector<int> final;
//    std::vector<int> refx;
//    std::vector<int> refy;
//    sort(ref1->begin(), ref1->end());
//    sort(ref2->begin(), ref2->end());
//    unique_copy(ref1->begin(), ref1->end(), std::back_inserter(refx));
//    unique_copy(ref2->begin(), ref2->end(), std::back_inserter(refy));
//    std::set_difference(refx.begin(),refx.end(), refy.begin(), refy.end(), std::back_inserter(final));

//    return final;
}

//std::vector<int> QueryProcessor::NOT(std::vector<int>* ref1, std::vector<int>* ref2)
//{
//    std::vector<int> final;
//    for(int i = 0; i < ref1->size()-1; i++)
//    {
//        final.push_back(ref1->at(i));
//    }
//    for(int i = 0; i < final.size()-1; i++)
//    {
//        for(int j = 0; j < ref2->size()-1; j++)
//        {
//            if(final[i] == ref2->at(j))
//            {
//                std::cout<<"we want to delete: " << final[i] << std::endl;
//            }

//        }
//    }

//    return final;
//}

std::map<int,int> QueryProcessor::ANDnot(std::vector<int>* ref1, std::vector<int>* ref2)
{
    std::vector<int> refx;
    std::vector<int> refy;

    for(int i = 0; i < ref1->size(); i++)
    {
        refx.push_back(ref1->at(i));
    }
    for(int i = 0; i < ref2->size(); i++)
    {
        refy.push_back(ref2->at(i));
    }

    std::map<int, int> andmap;
    std::map<int, int> occurances1;
    for(int i : refx)
        occurances1[i]++;
    std::map<int, int> occurances2;
    for(int i : refy)
        occurances2[i]++;

    for(auto& keyvalue1 : occurances1)
    {
        for(auto& keyvalue2 : occurances2)
        {
            if(keyvalue1.first == keyvalue2.first)
            {
                andmap.insert(std::make_pair(keyvalue1.first, (keyvalue1.second + keyvalue2.second)));
            }
        }
    }

    return andmap;

//    return rank(finalmap);

//    std::vector<int> final;
//    sort(ref1->begin(), ref1->end());
//    sort(ref2->begin(), ref2->end());

//    std::set_intersection(ref1->begin(),ref1->end(), ref2->begin(), ref2->end(), std::back_inserter(final));

//    return final;
}

std::vector<int> QueryProcessor::NOTand(std::map<int,int> andmap, std::vector<int>* ref3)
{
    std::vector<int> refz;


    for(int i = 0; i < ref3->size(); i++)
    {
        refz.push_back(ref3->at(i));
    }

    std::map<int, int> occurances3;
    for(int i : refz)
        occurances3[i]++;

    for(auto& keyvalue1 : andmap)
    {
        for(auto& keyvalue2 : occurances3)
        {
            if(keyvalue1.first == keyvalue2.first)
            {
                andmap.erase(keyvalue1.first);
            }
        }
    }

    return rank(andmap);

//    std::vector<int> final;
//    std::sort(and1.begin(), and1.end());
//    std::sort(ref3->begin(), ref3->end());
//    std::unique(and1.begin(), and1.end());
//    std::unique(ref3->begin(), ref3->end());

//    std::set_difference(and1.begin(),and1.end(), ref3->begin(), ref3->end(), std::back_inserter(final));

//    return final;
}


void QueryProcessor::query(DocumentParser* docParser)
{
    bool finishedQuery = false;
    while(finishedQuery != true)
    {
        Index * index = docParser->GetIndex();
        StemAndStopRemoval * stemmer = docParser->getStemmer();
        std::cout << "Enter a word or phrase to find: ";
        std::string userInput = "NULL";
        getline(std::cin, userInput);
        std::stringstream stream(userInput);
        std::string temp = "NULL";
        std::vector<std::string> words;
        std::vector<int>* wordReferences1;
        std::vector<int>* wordReferences2;
        std::vector<int>* wordReferences3;
        std::map<int, int> andMap;
        std::vector<int> finalVector;
        while(stream >> temp)
        {
            words.push_back(temp);
        }

        //words vector of the query

        std::string currentCommand = "NULL";
        int wordsSize = words.size();

        if(wordsSize == 1)
        {
            std::vector<int>* finalVector1Word;
            stemmer->StemWord(temp);
            finalVector1Word = index->findWord(temp);

            std::vector<int> values;
            for(int i = 0; i < finalVector1Word->size(); i++)
            {
                values.push_back(finalVector1Word->at(i));
            }

            std::map<int, int> occurances;
            for(int i : values)
                occurances[i]++;

            std::vector<int> finalVector = rank(occurances);

            std::cout<<"appears on page(s): "<<std::endl;
            for(int i = 0; i < finalVector.size(); i++)
            {
                std::cout<<finalVector[i]<<std::endl;
            }

            finishedQuery = true;
        }

        if(wordsSize == 3)
        {
            for(size_t i = 0; i < words.size(); ++i)
            {
                if(isCommand(words[i]))
                {
                    currentCommand = words[i];
                }
                else if(i == 0 && !isCommand(words[i]))
                {

                    stemmer->StemWord(words[i]);
                    wordReferences1 = index->findWord(words[i]);
                }
                else if(i == 1 && !isCommand(words[i]))
                {

                    stemmer->StemWord(words[i]);
                    wordReferences1 = index->findWord(words[i]);
                }
                else
                {
                    stemmer->StemWord(words[i]);
                    wordReferences2 = index->findWord(words[i]);

                    if(currentCommand == booleanCommands[0])
                    {
                        finalVector = AND(wordReferences1, wordReferences2);
                    }
                    else if(currentCommand == booleanCommands[1])
                    {
                        finalVector = OR(wordReferences1, wordReferences2);
                    }
                    else if(currentCommand == booleanCommands[2])
                    {
                        finalVector = NOT(wordReferences1, wordReferences2);
                    }
                }
            }

            std::cout<<"appears on page(s): "<<std::endl;
            for(int i = 0; i < finalVector.size(); i++)
            {
                std::cout<<finalVector[i]<<std::endl;
            }

            finishedQuery = true;
        }

        if(wordsSize == 4)
        {
            for(size_t i = 0; i < words.size(); ++i)
            {
                if(isCommand(words[i]))
                {
                    currentCommand = words[i];
                }
                else if(i == 0 && !isCommand(words[i]))
                {

                    stemmer->StemWord(words[i]);
                    wordReferences1 = index->findWord(words[i]);
                }
                else if(i == 1 && !isCommand(words[i]))
                {

                    stemmer->StemWord(words[i]);
                    wordReferences1 = index->findWord(words[i]);
                }
                else if(i == 2 && !isCommand(words[i]))
                {
                    stemmer->StemWord(words[i]);
                    wordReferences2 = index->findWord(words[i]);
                }
                else
                {
                    stemmer->StemWord(words[i]);
                    wordReferences3 = index->findWord(words[i]);

                    if(currentCommand == booleanCommands[0])
                    {
                        finalVector = AND2(wordReferences1, wordReferences2, wordReferences3);
                    }
                }
            }

            std::cout<<"appears on page(s): "<<std::endl;
            for(int i = 0; i < finalVector.size(); i++)
            {
                std::cout<<finalVector[i]<<std::endl;
            }

            finishedQuery = true;

        }


        if(wordsSize == 5)
        {
            for(size_t i = 0; i < words.size(); ++i)
            {
                if(isCommand(words[i]))
                {
                    currentCommand = words[i];
                }
                else if(i == 0 && !isCommand(words[i]))
                {

                    stemmer->StemWord(words[i]);
                    wordReferences1 = index->findWord(words[i]);
                }
                else if(i == 1 && !isCommand(words[i]))
                {
                    stemmer->StemWord(words[i]);
                    wordReferences1 = index->findWord(words[i]);
                }
                else if(i == 2 && !isCommand(words[i]))
                {
                    stemmer->StemWord(words[i]);
                    wordReferences2 = index->findWord(words[i]);
                    andMap = ANDnot(wordReferences1, wordReferences2);
                }

                else
                {
                    stemmer->StemWord(words[i]);
                    wordReferences3 = index->findWord(words[i]);

                    if(currentCommand == booleanCommands[2])
                    {
                        finalVector = NOTand(andMap, wordReferences3);
                    }
                }
            }

            std::cout<<"appears on page(s): "<<std::endl;
            for(int i = 0; i < finalVector.size(); i++)
            {
                std::cout<<finalVector[i]<<std::endl;
            }

            finishedQuery = true;

        }


    }
}

std::vector<int> QueryProcessor::rank(std::map<int, int> map)
{
    double freq = 0.0;
    double docTerms = 1000.0;
    double TF = 0.0;
    double t;
    double docs = 235972.0;
    double numWordsappears = map.size();
    double IDF;
    double TFIDF;
    std::vector<int> rankedvector;
    std::map<int, double> IDFmap;
    int docID = 0;

    //go into where the word appears and then calculate how many words are in the vector
    for(auto & keyvalue : map)
    {
        freq = keyvalue.second;
        //caluclate doc terms by going in through ID


        TF = freq/ docTerms;
        t = docs/numWordsappears;
        IDF = log(t);
        TFIDF = TF * IDF;

        IDFmap.insert(std::make_pair(keyvalue.first, TFIDF));
    }
    for(int i =0; i < 15; i++)
    {
        double freq1 = IDFmap.begin()->second;
        for(auto keyvalue : IDFmap)
        {
            if(keyvalue.second >= freq1)
            {
                docID = keyvalue.first;
                freq1 = keyvalue.second;
            }

        }
        rankedvector.push_back(docID);
        IDFmap.erase(docID);
        if(IDFmap.size() == 0)
        {
            break;
        }
    }
    return rankedvector;

}
