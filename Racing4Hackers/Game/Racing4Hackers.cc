//
//Racing4Hackers.cc
//
//Main function for the program. Creates a StartMenu object and
//calls StartMenu::run().
#include "StartMenu.h"
#include <iostream>
using namespace std;

int main()
{
    StartMenu startMenu;
    try
    {
	startMenu.run();
    }
    catch(...)
    {
	cout << "Program terminated due to unexpected error." << endl;
    }
    return 0;
}
