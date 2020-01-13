/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

//#include "Character.hpp"
#include "Medusa.hpp"
#include "helperFunctions.hpp"
// passed string library from here

#include <iostream>
#include<ctime> //for random number generator seed



   
/**************************************************************************
 * Passed: 
 * Returns:
 * Description: passes all it's default values to base loaded constructor.
**************************************************************************/
Medusa::Medusa() : Character(3, 8, 2, 6, 1, 6)
{
     type = "Medusa";
}



/**************************************************************************
 * Passed: string for name of character
 * Returns:
 * Description: Loaded constructor sends its default values through the
 * base class constructor and makes it's type and name unique.
**************************************************************************/
Medusa::Medusa(string inputName) : Character(3, 8, 2, 6, 1, 6)
{
     name = inputName;
     type = "Medusa";
}



Medusa::~Medusa() {}



/**************************************************************************
 * Passed: 
 * Returns: 
 * Description:i If rolled attack = 12 then value becomes -1 which defensive
 * damage tallying recognizes as the value assigned to a fatal attack.
*************************************************************************/
int Medusa::attack()
{
     int offensive = Character::attack();

     if(offensive == 12)
     {
          offensive = -1;
     }

     return offensive;
}

