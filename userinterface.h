#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include "documentparser.h"
#include "avl_tree.h"
#include "stemandstopremoval.h"
#include "index.h"
#include "porter2_stemmer.h"
#include "queryprocessor.h"
#include "statistics.h"
#include <vector>
#include <string>

class UserInterface
{
public:
    UserInterface();
    void mainMenu(char*);
    void interactiveMode(char*);
    void maintenanceMode(char*);
    void exit();


private:
    std::string userInput;

};

#endif // USERINTERFACE_H
