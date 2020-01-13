/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

#include <string>

using std::string;



class Vampire : public Character
{
     public:
          // Default Constructor
          Vampire();
          // Loaded Constructor
          Vampire(string);
          // Destructor
          virtual ~Vampire();

          // Member Functions
          virtual int tallyDamage(int&, int&);
};

#endif
