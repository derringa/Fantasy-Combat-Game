/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

using std::string;



class Character
{
     protected:
          string name;
          string type;
          int armor;
          int strengthPoints;

          int attackDice;
          int attackDiceSides;
          int defenseDice;
          int defenseDiceSides;

     public:
          // Default Constructor
          Character(int, int, int, int, int, int);
          // Destructor
          virtual ~Character() = 0;

          // Member Functions
          virtual int attack();
          int defend();
          virtual int tallyDamage(int&, int&);
          bool isAlive();

          string getName();
          string getType();
          int getArmor();
          int getStrengthPoints();
          void regenerate(int);
};

#endif
