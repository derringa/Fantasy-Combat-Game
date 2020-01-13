/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#include "BlueMen.hpp"
#include "helperFunctions.hpp"

#include <iostream>
#include<ctime> //for random number generator seed



   
/**************************************************************************
 * Passed: 
 * Returns:
 * Description: Passes it's default values through the base consructor
 * whenever object is default constructed
**************************************************************************/
BlueMen::BlueMen() : Character(3, 12, 2, 10, 3, 6)
{
     type = "Blue Men";
}



/**************************************************************************
 * Passed: string for name of character
 * Returns:
 * Description: Loaded constructor sends its default values through the
 * base class constructor and makes it's type and name unique.
**************************************************************************/
BlueMen::BlueMen(string inputName) : Character(3, 12, 2, 10, 3, 6)
{
     name = inputName;
     type = "BlueMen";
}



BlueMen::~BlueMen() {}



/**************************************************************************
 * Passed: 
 * Returns: 
 * Description: Virtual defend function is unique from main in that it
 * is the only derived class where the number of dice rolled for defense
 * must be changed depending on the health.
*************************************************************************/
int BlueMen::defend()
{
     if(strengthPoints > 8)
     {
          defenseDice = 3;
     }else if(strengthPoints > 4 && strengthPoints < 9)
     {
          defenseDice = 2;
     }else
     {
          defenseDice = 1;
     }

     std::srand(std::time(0));

     return Character::defend();
}

