/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#include "HarryPotter.hpp"
#include "helperFunctions.hpp"
// passed string library from here

#include <iostream>
#include<ctime> //for random number generator seed



   
/**************************************************************************
 * Passed: 
 * Returns:
 * Description: passes class default values to base class loaded constructor
**************************************************************************/
HarryPotter::HarryPotter() : Character(1, 10, 1, 12, 1, 6)
{
     type = "Harry Potter";
     resurrected = false;
}



/**************************************************************************
 * Passed: string for name of character
 * Returns:
 * Description: Loaded constructor sends its default values through the
 * base class constructor and makes it's type and name unique.
**************************************************************************/
HarryPotter::HarryPotter(string inputName) : Character(1, 10, 1, 12, 1, 6)
{
     name = inputName;
     type = "Harry Potter";
     resurrected = false;
}

HarryPotter::~HarryPotter() {}




/**************************************************************************
 * Passed: attack and defense rolls from tha ht round by reference
 * Returns: 
 * Description: Lets base class equivalent do it's job, but after if
 * Harry has no life left but resurrected = false, then life is reset
 * to 20 and resurrected = true. Can't happen again once true.
*************************************************************************/
int HarryPotter::tallyDamage(int& attack, int& defense)
{
     int damage = Character::tallyDamage(attack, defense);

     if(strengthPoints <= 0 && !resurrected)
     {
          //std::cout << "Harry Potter was killed in battle but was resurrected\n"
          //          << "by the power of the deathly hallows"
          //          << std::endl << std::endl;

          strengthPoints = 20;
          resurrected = true;
     }

     return damage;
}
