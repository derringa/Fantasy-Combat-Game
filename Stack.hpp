/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include "QueueNode.hpp"
#include "Character.hpp"



class Stack
{
     protected:
          QueueNode* head;

     public:
          // Default Constructor
          Stack();
          //Destructor
          ~Stack();

          // Member Functions
          //void addToHead(Character*);
          void addToHead(Character*);
          void printList();
};

#endif
