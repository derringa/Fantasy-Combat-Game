/**************************************************************************
 * Program: Circular Queue Lists
 * Author: Andrew Derringer
**************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueNode.hpp"




class Queue
{
     protected:
          QueueNode* head;

     public:
          // Default Constructor
          Queue();
          //Destructor
          ~Queue();

          // Member Functions
          bool isEmpty();
          void addBack(Character*);
          void removeFront();
          void moveToBack();
          void printQueue();
          void setFighter(Character*);
          Character* getFighter();
          QueueNode* getHead();
};

#endif
