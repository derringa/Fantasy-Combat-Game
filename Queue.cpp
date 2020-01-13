/**************************************************************************
 * Program: Circular Linked Lists
 * Author: Andrew Derringer
**************************************************************************/

#include "Queue.hpp"

#include <iostream>



/**************************************************************************
 * Passed:
 * Returns: 
 * Description: Queues are always geenrated empty and wait for user
 * input to add additional nodes.  
**************************************************************************/
Queue::Queue()
{
     head = nullptr;
}



/**************************************************************************
 * Passed:
 * Returns: 
 * Description: Looks for 3 conditions. Is the list empty? Then simply
 * return. Does the list contain only the head node? Just delete the head.
 * Is the length of the list 2 or greater? Then break the circular list
 * into a linear one and use a while loop to iterate through and delete
 * each node.
**************************************************************************/
Queue::~Queue()
{

     // If the list is already empty then don't try to delete anything.
     if(isEmpty())
     {
          return;

     // If the list has only one node, the head, simplty delete it.
     }else if(head->getNextNode() == nullptr)
     {
          delete head;
          head = nullptr;

     // If length >1 then sever list into line and crawl through to delete.
     }else{

          // Get tail by finding head's previous node.
          QueueNode* lastNode = head->getPreviousNode();

          // Unlink the head and tail to make linear list.
          lastNode->setNextNode(nullptr);
          head->setPreviousNode(nullptr);

          QueueNode* currentPtr = head;

          // Iterate through list and delete nodes after grabbing
          // address for next node.
          while(currentPtr != nullptr)
          {
               QueueNode* garbage = currentPtr;
               currentPtr = currentPtr->getNextNode();
               delete garbage;
               garbage = nullptr;
          }
     }
}



/**************************************************************************
 * Passed:
 * Returns: bool T/F depending on if the list is completely empty. 
 * Description: Used by various member functions when conditionals need to
 * know if the list is empty before they can proceed.
**************************************************************************/
bool Queue::isEmpty()
{
     bool empty = true;

     // Head assigned to nullptr when constructed and reassigned when
     // list is deleted down to length 0.
     if(head != nullptr)
     {
          empty = false;
     }

     return empty;
}



/**************************************************************************
 * Passed: Input value for the new node to hold
 * Returns: 
 * Description: Looks for 3 conditions. Is the list empty? Initializes a
 * new QueueNode struct holding the input value and nullptr for previous
 * and next nodes. Is there only one node? The head's next node is set
 * to a new node holding the new value and properly linked.  Now a "circle"
 * of 2. Is the list length >1? Iterate through the list until reaching the
 * tail, set next node, and properly link them.
**************************************************************************/
void Queue::addBack(Character* inputFighter)
{

     // Empty list head is initialized with new struct and no links.
     if(isEmpty())
     {
          head = new QueueNode(inputFighter, nullptr, nullptr);

     // Queue of only one has head's next node inialized with a new
     // node that is linked on both sides to head.
     }else if(head->getNextNode() == nullptr){

          head->setNextNode(new QueueNode(inputFighter, head, head));

          QueueNode* lastNode = head->getNextNode();
          head->setPreviousNode(lastNode);

     // A queue of >1 uses a while loop to iterate until a node has
     // head as it's next node, or the tail.
     }else{
          QueueNode* currentPtr = head;

          while(currentPtr->getNextNode() != head)
          {
               currentPtr = currentPtr->getNextNode();
          }

          // Once the tail is found it's next node is reassigned to a new
          // node whose previous node is assigned to the old tail and next
          // node to the head. The head's previous node is then reassigned
          // to the new tail.
          currentPtr->setNextNode(new QueueNode(inputFighter, currentPtr, head));
          QueueNode* lastNode = currentPtr->getNextNode();
          head->setPreviousNode(lastNode);
     }
}



/**************************************************************************
 * Passed:
 * Returns: 
 * Description: If the list is empty then nothing happens. If only one
 * node is in the list then all of the ptrs are reassigned to null. If
 * The list has 2 or more nodes then head is reassigned to the next node
 * and that new head's previous node is set to null.
**************************************************************************/
void Queue::removeFront()
{

     // If empty then don't try to delete anything.
     if(isEmpty())
     {
          return;

     // If only one node then delete the head and set to nullptr.
     }else if(head->getNextNode() == nullptr){
          delete head;
          head = nullptr;

     // If the queue is >1 then assign a new head by getting the current
     // head's next node. Get the last node, delete the old head and
     // reassign it to the new head, and finish by linking the new head
     // and old tail.
     }else{

          // Assign the new head before deleting the old one and making
          // the new one impossible to reach.
          QueueNode* newHead = head->getNextNode();
          QueueNode* lastNode = head;

          // Way of finding the tail that is more complicated than
          // it needs to be...
          while(lastNode->getNextNode() != head)
          {
               lastNode = lastNode->getNextNode();
          }

          // delete the old head and reassign to new head.
          delete head;
          head = newHead;

          // if they are noth the same then there is only one node.
          // set previous and next to null.
          if(head == lastNode)
          {
               head->setPreviousNode(nullptr);
               head->setNextNode(nullptr);

          // If more than one node left then link tail and head
          // into a circle.
          }else{
          lastNode->setNextNode(head);
          head->setPreviousNode(lastNode);
          }
     }
}



/**************************************************************************
 * Passed:
 * Returns: 
 * Description: If the list is >1 then the head is reassigned to the next
 * node in the queue which effectively shifts the old head to the back of
 * the queue.
**************************************************************************/
void Queue::moveToBack()
{
     // if empty then nothing to move.
     if(isEmpty())
     {
          return;
     // if only one element then nothing to move.
     }else if(head->getNextNode() == nullptr){
          return;
     // if more than one element then shift head to next, effectively putting
     // the old head at the back of the queue.
     }else{
          head = head->getNextNode();
     }
}



/**************************************************************************
 * Passed:
 * Returns: 
 * Description: Different behavior under 3 conditions. If empty then it
 * tells you so. If only one node then it prints that value. If length
 * is >1 then itereate through the lista nd print values until it reaches
 * the head again.
**************************************************************************/
void Queue::printQueue()
{
     // If empty then tell me so for testing sake.
     if(isEmpty())
     {
          std::cout << "The Queue is empty." << std::endl << std::endl;

     // If only one value then print that. Could have made a single else
     // with either next node = to head or next node = nullptr.
     }else if(head->getNextNode() == nullptr){
          Character* fighter = head->getFighter();

          std::cout << fighter->getName() << "(" << fighter->getType() << ")";

     // Iterate through list and print values until the currentPtr goes
     // around the circle and reaches the head again.
     }else{
          QueueNode* currentPtr = head;

          do{

               Character* fighter = currentPtr->getFighter();

               std::cout << fighter->getName() << "(" << fighter->getType() << ")   ";
               currentPtr = currentPtr->getNextNode();
         } while(currentPtr != head);
     }
}



/**************************************************************************
 * Passed:
 * Returns: Character pointer for variety of derived classes
 * Description: Used in main to acess object for immediate use of functions.
**************************************************************************/
Character* Queue::getFighter()
{
     return head->getFighter();
}



/**************************************************************************
 * Passed: Either Character derived class pointer or nullptr.
 * Returns: 
 * Description: Used in main to reassign character to null so that when a
 * node is deleted from a queue, the character that was added to a node in
 * the loser stack is not deleted by the destructor call.
**************************************************************************/
void Queue::setFighter(Character* inputFighter)
{
     head->setFighter(inputFighter);
}



/**************************************************************************
 * Passed:
 * Returns: Pointer to queuenode object in memory/
 * Description: Created for main in attempt to share nodes, but alternatives
 * to deep copying were easier.
**************************************************************************/
QueueNode* Queue::getHead()
{
          return head;
}
