/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#include "Character.hpp"
#include "helperFunctions.hpp"
// passed string library from here

#include <iostream>
#include <ctime> //for random number generator seed



   
/**************************************************************************
 * Passed: integers for member variables for armor, strength, and dice information 
 * Returns:
 * Description: though base is abstract each class passes most of it's default
 * constructor values through the base loaded constructor
**************************************************************************/
Character::Character(int inputArmor, int inputStrength, int inputAttDice, int attDiceSides, int inputDefDice, int defDiceSides)
{
     name = "None";
     type = "None";
     armor = inputArmor;
     strengthPoints = inputStrength;
     attackDice = inputAttDice;
     attackDiceSides = attDiceSides;
     defenseDice = inputDefDice;
     defenseDiceSides = defDiceSides;
}



Character::~Character() {}



/**************************************************************************
 * Passed: 
 * Returns: total attack value after all dice rolls
 * Description: Time seed assigned in main. Loops through by number of
 * attack dice and produces a range of outcomes between 1 and max dice sides.
*************************************************************************/
int Character::attack()
{
     int offensive = 0;

     for(int i = 0; i < attackDice; i++)
     {
          offensive += getRandomInteger(1, attackDiceSides);
     }

     return offensive;
}



/**************************************************************************
 * Passed: 
 * Returns: total defense value after all dice rolls
 * Description: Time seed assigned in main. Loops through by number of
 * defense dice and produces a range of outcomes between 1 and max dice sides.
*************************************************************************/
int Character::defend()
{
     int defense = 0;

     for(int i = 0; i < defenseDice; i++)
     {
          defense += getRandomInteger(1, defenseDiceSides);
     }

     return defense;
}



/**************************************************************************
 * Passed: attack and defense of that round by reference
 * Returns: total damage
 * Description: receives by reference so that values can be changed
 * acccording to certain conditions. Damage is equal to attack minus
 * defense and armor. If special value -1 then we know Medusa rolled for
 * a glare attack in which case her attack is recalculated to perfectly
 * remvhove all remaining strength points.
*************************************************************************/
int Character::tallyDamage(int& attack, int& defense)
{
     if(attack == -1)
     {
          //std::cout << "Medusa used glare to turn her foe into stone!"
          //          << std::endl << std::endl;

          defense = 0;
          attack = strengthPoints + armor;
     }

     int damage = attack - (defense + armor);

     if(damage > 0)
     {
          strengthPoints -= damage;
     }else{
          damage = 0;
     }

     return damage;
}



/**************************************************************************
 * Passed: 
 * Returns: true or false depending on strength points
 * Description: If strength of object is greater than zero then this returns
 * true, otherwise false.
*************************************************************************/
bool Character::isAlive()
{
     bool alive = false;

     if(strengthPoints > 0)
     {
          alive = true;
     }

     return alive;
}



/**************************************************************************
 * Passed: 
 * Returns: string value for name member variable
 * Description: Used by main to print name of character during fights.
*************************************************************************/
string Character::getName()
{
     return name;
}



/**************************************************************************
 * Passed: 
 * Returns: string value for type of character variable.
 * Description: Used by main to print type of character during fights.
*************************************************************************/
string Character::getType()
{
     return type;
}



/**************************************************************************
 * Passed: 
 * Returns: 
 * Description:
*************************************************************************/
int Character::getArmor()
{
     return armor;
}



/**************************************************************************
 * Passed: 
 * Returns: 
 * Description:
*************************************************************************/
int Character::getStrengthPoints()
{
     return strengthPoints;
}



/**************************************************************************
 * Passed: 
 * Returns: 
 * Description:
*************************************************************************/
void Character::regenerate(int health)
{
     strengthPoints += health;
}
