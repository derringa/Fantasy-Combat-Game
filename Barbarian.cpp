/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#include "Barbarian.hpp"


   
/**************************************************************************
 * Passed: 
 * Returns:
 * Description: Default constructor sends its default values through the
 * base class constructor and makes only it's type unique.
**************************************************************************/
Barbarian::Barbarian() : Character(0, 12, 2, 6, 2, 6)
{
     type = "Barbarian";
}



/**************************************************************************
 * Passed: string for name of character
 * Returns:
 * Description: Loaded constructor sends its default values through the
 * base class constructor and makes it's type and name unique.
**************************************************************************/
Barbarian::Barbarian(string inputName) : Character(0, 12, 2, 6, 2, 6)
{
     name = inputName;
     type = "Barbarian";
}



Barbarian::~Barbarian() {}

