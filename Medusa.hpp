/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"



class Medusa : public Character
{
     public:
          // Default Constructor
          Medusa();
          // Loaded Constructor
          Medusa(string);
          // Destructor
          virtual ~Medusa();

          // Member Functions
          virtual int attack();
};

#endif
