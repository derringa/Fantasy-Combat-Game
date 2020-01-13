/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"



class Barbarian : public Character
{
     public:
          // Default Constructor
          Barbarian();
          // Loaded Constructor
          Barbarian(string);
          // Destructor
          virtual ~Barbarian();
};

#endif
