#include "userinterface.h"


UserInterface::UserInterface()
{
    userInput = "NULL";
}

void UserInterface::mainMenu(DocumentParser * docParser)
{
    std::cout<<"______________________________________________"<<std::endl;
    std::cout<<"Welcome to TWSearchEngine"<<std::endl;
    std::cout<<"Enter [1] to enter INTERACTIVE mode"<<std::endl;
    std::cout<<"Enter [2] to enter MAINTENANCE mode"<<std::endl;
    std::cout<<"Enter [3] to exit"<<std::endl;
    std::cin>>userInput;
    if(userInput == "1")
    {
        interactiveMode(docParser);
    }
    else if(userInput == "2")
    {
        maintenanceMode(docParser);
    }
    else if(userInput == "3")
    {
        exit();
    }

}


void UserInterface::interactiveMode(DocumentParser * docParser)
{
    while(true)
    {
        std::cout<<"[1 = WORD SEARCH] [2 = TOP 50 WORDS] [3 = PAGE COUNT] [4 = WORD COUNT]"<<std::endl;
        std::cout<<"CHOICE: ";
        int user_choice;
        std::cin>>user_choice;
        switch(user_choice)
        {
            case 1:
                WordSearch(docParser);
                break;
            case 2:
                PrintTopWords(docParser);
                break;
            case 3:
                PageCount(docParser);
                break;
            case 4:
                WordCount(docParser);
                break;
        }
    }
}

void UserInterface::maintenanceMode(DocumentParser * docParser)
{
    std::cout<<"______________________________________________"<<std::endl;
    std::cout<<"Welcome to MAINTENANCE mode"<<std::endl;
    std::cout<<"Enter [1] to add a document to the index"<<std::endl;
    std::cout<<"Enter [2] to clear the index"<<std::endl;
    std::cout<<"Enter [3] to go back to the main menu"<<std::endl;

    std::cin>>userInput;

    if(userInput == "1")
    {

    }
    if(userInput == "2")
    {

    }
    if(userInput == "3")
    {
        mainMenu(docParser);
    }
}

void UserInterface::exit()
{
    std::exit(1);
}

void UserInterface::PrintTopWords(DocumentParser * docParser)
{
    Index * index = docParser->GetIndex();
    vector<std::pair<std::string,int>> * freqList = index->sortByFrequency(index->getMasterTree()->GetFreqVector());
    for(int i = 0; i < 50; i++)
    {
        std::cout<<"#"<<i+1<<". "<<freqList->at(freqList->size()-i-1).first<<", "<<freqList->at(freqList->size()-i-1).second<<std::endl;
    }
    std::cout<<std::endl;
}

void UserInterface::WordSearch(DocumentParser * docParser)
{
    Index * index = docParser->GetIndex();
    queryProcessor->query(docParser);
    /*
    StemAndStopRemoval * stemmer = docParser->getStemmer();
    std::cout<<"WORD TO SEARCH: ";
    std::string user_input;
    std::cin>>user_input;
    stemmer->StemWord(user_input);
    if(user_input.length() <= 1)
        return;
    std::vector<int> * wordReferences;
    if(index->findWord(user_input) != nullptr)
        wordReferences = index->findWord(user_input);
    else
    {
        std::cout<<"NO RESULTS FOR "<<user_input<<std::endl;
        return;
    }
    bool browsingResults = true;
    int visitNum = 0;
    while(browsingResults == true)
    {
        int choice;
        if(visitNum > 0)
        {
            std::cout<<"[1 = BROWSE RESULTS] [2 = NEW SEARCH] [3 = HOME]"<<std::endl;
            std::cout<<"CHOICE: ";
            std::cin>>choice;
        }
        else
        {
            choice = 999;
            visitNum++;
        }
        switch(choice)
        {
            default:
                std::cout<<"'"<<user_input<<"' APPEARS ON PAGES: "<<std::endl;
                for(int i = 0; i < wordReferences->size()-1; i++)
                {
                    std::cout<<"PAGE "<<wordReferences->at(i)<<std::endl;

                }
                std::cout<<"RESULT ID TO BROWSE: ";
                int entryNum;
                std::cin>>entryNum;
                try
                {
                    std::vector<int>::iterator pageID = std::find(wordReferences->begin(), wordReferences->end(),entryNum);
                    std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
                    std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
                    std::cout<<docParser->retrievePage(pageID.base()[0])<<std::endl;
                    std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
                    std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
                }
                catch(exception e)
                {

                }
                break;
            case 2:
                WordSearch(docParser);
                browsingResults = false;
                break;
            case 3:
                browsingResults = false;
                break;
        }
    }
    */
}

void UserInterface::PageCount(DocumentParser * docParser)
{
    Index * index = docParser->GetIndex();
    std::cout<<"TOTAL PAGE COUNT: "<<index->getPageCount()<<std::endl;
}

void UserInterface::WordCount(DocumentParser * docParser)
{
    Index * index = docParser->GetIndex();
    std::cout<<"TOTAL WORD COUNT: "<<index->getWordCount()<<std::endl;
}

