/**************************************************************************
 * Program: Fantasy Game Tournament
 * Author: Andrew Derringer
**************************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP



#include "Character.hpp"



struct QueueNode
{
     Character* fighter;
     QueueNode* previousNode;
     QueueNode* nextNode;

     // Loaded  Constructor
     QueueNode(Character*, QueueNode*, QueueNode*);

     // destructor
     ~QueueNode();

     // Member functions
     void setFighter(Character*);
     Character* getFighter();
     void setPreviousNode(QueueNode*);
     QueueNode* getPreviousNode();
     void setNextNode(QueueNode*);
     QueueNode* getNextNode();
};

#endif
