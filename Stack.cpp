/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
**************************************************************************/

#include "Stack.hpp"

#include <iostream>



/**************************************************************************
 * Passed:
 * Returns: 
 * Description: NodeLists are always geenrated empty and wait for user
 * input to add additional nodes.  
**************************************************************************/
Stack::Stack()
{
     head = nullptr;
}



/**************************************************************************
 * Passed:
 * Returns: 
 * Description: Crawls through the list, reassigning it's current the location
 * and holding on the the previoud node long enough to get it's next node
 * and delete it.
**************************************************************************/
Stack::~Stack()
{
     QueueNode* currentPtr = head;

     while(currentPtr != nullptr)
     {
          QueueNode* garbage = currentPtr;
          currentPtr = currentPtr->getNextNode();
          delete garbage;
     }
}



/**************************************************************************
 * Passed: Input value for the new head node to hold
 * Returns: 
 * Description: If empty then assigns all ptrs to the single node, otherwise
 * new node is created with current head as next node and nullptr as previous
 * before head is reassigned to the new node.
**************************************************************************/
void Stack::addToHead(Character* inputFighter)
{
     if(head == nullptr)
     {
          head = new QueueNode(inputFighter, nullptr, nullptr);
     }else{
          head->setPreviousNode(new QueueNode(inputFighter, nullptr, head));
          head = head->getPreviousNode();
     }
}



/**************************************************************************
 * Passed:
 * Returns: 
 * Description: Crawls through the list as long as the current node is not
 * equal to null or empty. It prints the node with space and changes the 
 * node that it's pointing at to the current node's next node.
**************************************************************************/
void Stack::printList()
{
     QueueNode* currentPtr = head;

     while(currentPtr != nullptr)
     {
          Character* loser = currentPtr->getFighter();

          std::cout << loser->getName() << "(" << loser->getType() << ")   ";
          currentPtr = currentPtr->getNextNode();
     }
}
