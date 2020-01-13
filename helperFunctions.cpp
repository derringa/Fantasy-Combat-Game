/**************************************************************************
 * File: General Helper Functions
 * Author: Andrew Derringer
 * Last Modified: 2/12/2019
 * Description: Includes random number generators for int and double, automated
 * menu writers,
**************************************************************************/

#include "helperFunctions.hpp"   // Receives <string>
#include "inputValidation.hpp"

#include <iostream>
#include <string>
#include <cstdlib> //for random number generator
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::max;
/*
#include <limits>
#include <chrono>
#include <thread>


using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::string;
*/


int getRandomInteger(int min, int max)   // In main "std::srand(std::time(0));"
{
	int randomInt = (rand() % (max - min + 1)) + min;
	return randomInt;
}



double getRandomDouble(double min, double max)   // In main "std::srand(std::time(0));"
{
	double randomDouble = ((double)rand() / (max - min + 1)) + min;
	return randomDouble;
}



int writeMenu(string menuTitle, string* stringArray, int arrayLength)
{
     cout << menuTitle << endl << endl
          << "------------------------------" << endl;

     for(int i = 0; i < arrayLength; i++)
     {
          cout << i + 1 << ") " << stringArray[i] << endl;
     }

     cout << "------------------------------" << endl
          << "Your choice:" << endl;

     int choice = integerRangeValidate(("Error: You must pick an integer between 1 and "
                  + std::to_string(arrayLength) + ". Try again:"), 1, arrayLength);

     return choice;
}



bool runProgram(string title, string inquiry)
{
     cout << "|--------------------------------------------------|\n"
          << "|" + title + "|\n"
          << "|--------------------------------------------------|\n\n\n"

          << inquiry << endl;

     bool choice = boolValidate();

     return choice;
}



bool runAgain(string title)
{
     cout << "Would you like to run " + title + " again?" << endl;

     bool choice = boolValidate();

     return choice;
}



/**************************************************************************
 * Passed: nothing
 * Returns: Nothing
 * Description: Prompts the user to press enter before continuing to the
 * next function or clear screen.
**************************************************************************/
void pauseUntilInput()
{
     cout << "Press enter to continue." << endl;
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
