/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#include "Vampire.hpp"
#include "helperFunctions.hpp"
// passed string library from here

#include <iostream>
#include<ctime> //for random number generator seed



   
/**************************************************************************
 * Passed: 
 * Returns:
 * Description: default values passed to base loaded constructor
**************************************************************************/
Vampire::Vampire() : Character(1, 18, 1, 12, 1, 6)
{
     type = "Vampire";
}



/**************************************************************************
 * Passed: string for name of character
 * Returns:
 * Description: Loaded constructor sends its default values through the
 * base class constructor and makes it's type and name unique.
**************************************************************************/
Vampire::Vampire(string inputName) : Character(1, 18, 1, 12, 1, 6)
{
     name = inputName;
     type = "Vampire";
}



Vampire::~Vampire() {}




/**************************************************************************
 * Passed: attack and defense rolled for that round by reference
 * Returns: integer for total damage. 
 * Description: Has it's own coin flip. If yes then attack = 0.
*************************************************************************/
int Vampire::tallyDamage(int& attack, int& defense)
{
     if(getRandomInteger(1,2) == 1)
     {
          //std::cout << "The vampire rolled for charm and stopped his foe from attacking!" << std::endl;
          attack = 0;
          defense = 0;
     }

     return Character::tallyDamage(attack, defense);
}
