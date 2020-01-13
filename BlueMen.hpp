/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"



class BlueMen : public Character
{
     public:
          // Default Constructor
          BlueMen();
          // Loaded Constructor
          BlueMen(string); 
          // Destructor
          virtual ~BlueMen();

          // Member Functions
          virtual int defend();
};

#endif
