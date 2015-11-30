#include "userinterface.h"


UserInterface::UserInterface()
{
    userInput = "NULL";
}

void UserInterface::mainMenu(char* fileName)
{

    std::cout<<"______________________________________________"<<std::endl;
    std::cout<<"Welcome to TWSearchEngine"<<std::endl;
    std::cout<<"Enter [1] to enter INTERACTIVE mode"<<std::endl;
    std::cout<<"Enter [2] to enter MAINTENANCE mode"<<std::endl;
    std::cout<<"Enter [3] to exit"<<std::endl;
    std::cin>>userInput;
    if(userInput == "1")
    {
        interactiveMode(fileName);
    }
    else if(userInput == "2")
    {
        maintenanceMode(fileName);
    }
    else if(userInput == "3")
    {
        exit();
    }

}


void UserInterface::interactiveMode(char* fileName)
{
    DocumentParser * docParser = new DocumentParser;
    while(true)
    {
        std::cout<<"______________________________________________"<<std::endl;
        std::cout<<"Welcome to INTERACTIVE mode"<<std::endl;
        std::cout<<"Enter [1] to build index as an AVL tree"<<std::endl;
        std::cout<<"Enter [2] to build index as a hash table"<<std::endl;
        std::cout<<"Enter [3] to enter a query"<<std::endl;
        std::cout<<"Enter [4] for statistics"<<std::endl;
        std::cout<<"Enter [5] to go back to the main menu"<<std::endl;

        std::cin>>userInput;

        if(userInput == "1")
        {
            docParser -> ReadInXML(fileName);
        }
        if(userInput == "2")
        {

        }
        if(userInput == "3")
        {
            QueryProcessor * query = new QueryProcessor;
            query->query(docParser);
        }
        if(userInput == "4")
        {
            Statistics * stats = new Statistics;
            stats->stats(docParser);
        }
        if(userInput == "5")
        {
            mainMenu(fileName);
        }
    }
}

void UserInterface::maintenanceMode(char* filename)
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
        mainMenu(filename);
    }
}

void UserInterface::exit()
{
    std::exit(1);
}
