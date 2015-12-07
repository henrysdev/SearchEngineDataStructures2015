#include "userinterface.h"


UserInterface::UserInterface(DocumentParser * docP)
{
    hasLoaded = false;
    userInput = "NULL";
    queryProcessor = new QueryProcessor(docP);
}

void UserInterface::mainMenu(DocumentParser & docParser)
{
    std::cout<<"______________________________________________"<<std::endl;
    std::cout<<"Welcome to TWSearchEngine"<<std::endl;
    std::cout<<"Enter [1] to enter INTERACTIVE mode"<<std::endl;
    std::cout<<"Enter [2] to enter MAINTENANCE mode"<<std::endl;
    std::cout<<"Enter [3] to exit"<<std::endl;
    std::cin>>userInput;
    if(userInput == "1")
    {
        interactiveMode(&docParser);
    }
    else if(userInput == "2")
    {
        maintenanceMode(&docParser);
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
        std::cout<<"______________________________________________"<<std::endl;
        std::cout<<"Welcome to INTERACTIVE mode"<<std::endl;
        if(hasLoaded == false)
            std::cout<<"***WARNING*** DATA HAS NOT BEEN LOADED!"<<std::endl;
        std::cout<<"Enter [1] for WORD SEARCH"<<std::endl;
        std::cout<<"Enter [2] for TOP 50 WORDS"<<std::endl;
        std::cout<<"Enter [3] for PAGE COUNT"<<std::endl;
        std::cout<<"Enter [4] for WORD COUNT"<<std::endl;
        std::cout<<"Enter [5] to LOAD DATA INTO AVL TREE"<<std::endl;
        std::cout<<"Enter [6] to LOAD DATA INTO HASH TABLE"<<std::endl;
        std::cout<<"Enter [7] for MAIN MENU"<<std::endl;
        //std::cout<<"CHOICE: ";
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
            case 5:
            {
                docParser->GetIndex()->readInSaveFile(0);
                hasLoaded = true;
                break;
            }
            case 6:
            {
                docParser->GetIndex()->readInSaveFile(1);
                hasLoaded = true;
                break;
            }
            default:
                mainMenu(*docParser);
                break;
        }
    }
}

void UserInterface::maintenanceMode(DocumentParser * docParser)
{
    bool maintenance = true;
    while(maintenance == true)
    {
        std::cout<<"______________________________________________"<<std::endl;
        std::cout<<"Welcome to MAINTENANCE mode"<<std::endl;
        std::cout<<"Enter [1] to add a document to the index"<<std::endl;
        std::cout<<"Enter [2] to clear the index"<<std::endl;
        std::cout<<"Enter [3] to go back to the main menu"<<std::endl;
        int user_choice;
        std::cin>>user_choice;
        switch(user_choice)
        {
            case 1:
            {
                std::cout<<"Please provide the path to the file to be indexed: ";
                std::string filePath;
                std::cin>>filePath;
                docParser->ReadInXML(filePath);
                break;
            }
            case 2:
                docParser->GetIndex()->ClearIndex();
                break;
            default:
                maintenance = false;
                mainMenu(*docParser);
                break;
        }
    }
}

void UserInterface::exit()
{
    std::exit(1);
}

void UserInterface::PrintTopWords(DocumentParser * docParser)
{
    Index * index = docParser->GetIndex();
    std::vector<std::pair<std::string,int>> * freqList;
    if(index->getDataStructureID() == 0)
    {
        freqList = index->sortByFrequency(index->getMasterTree()->GetFreqVector());
        for(int i = 0; i < 50; i++)
        {
            std::cout<<"#"<<i+1<<". "<<freqList->at(freqList->size()-i-1).first<<", "<<freqList->at(freqList->size()-i-1).second<<std::endl;
        }
        std::cout<<std::endl;
    }
    else
    {
        freqList = index->sortByFrequency(index->getMasterHash()->GetFreqVector());
        for(int i = 0; i < 50; i++)
        {
            std::cout<<"#"<<i+1<<". "<<freqList->at(freqList->size()-i-1).first<<", "<<freqList->at(freqList->size()-i-1).second<<std::endl;
        }
        std::cout<<std::endl;
    }
}

void UserInterface::WordSearch(DocumentParser * docParser)
{
    Index * index = docParser->GetIndex();
    queryProcessor->query();
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

