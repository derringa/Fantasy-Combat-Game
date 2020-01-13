/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"



class HarryPotter : public Character
{
     private:
          bool resurrected;

     public:
          // Default Constructor
          HarryPotter();
          // Loaded Constructor
          HarryPotter(string);
          // Destructor
          virtual ~HarryPotter();

          // Member Functions
          virtual int tallyDamage(int&, int&);
};

#endif
