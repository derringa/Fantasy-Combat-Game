/**************************************************************************
 * Program: Fantasy Game Tournament
 * Author: Andrew Derringer
**************************************************************************/

#include "QueueNode.hpp"
#include "Queue.hpp"



/**************************************************************************
 * Passed: Int for node to hold, ptrs to nodes for previous and next
 * Returns:
 * Description: Node only created through Queue class. When adding
 * to the tail, prevNode set to old tail and next node of new tail
 * set to head of the queue. In Queue, head's previous node is also set to
 * the new tail.
**************************************************************************/
QueueNode::QueueNode(Character* inputFighter, QueueNode* pNode, QueueNode* nNode)
{
     fighter = inputFighter;
     previousNode = pNode;
     nextNode = nNode;
}



/**************************************************************************
 * Passed
 * Returns:
 * Description:
**************************************************************************/
QueueNode::~QueueNode()
{
     delete fighter;
     fighter = nullptr;
}



/**************************************************************************
 * Passed: Pointer to derived classes of Character class.
 * Returns:
 * Description: Used by Queue in main to reassign character* to nullptr before
 * the destruvtor is called so that the character object is not deleted
 * by the destructor.
**************************************************************************/
void QueueNode::setFighter(Character* inputFighter)
{
     fighter = inputFighter;
}



/**************************************************************************
 * Passed
 * Returns: Pointer to Character base class
 * Description: Used in Queue print functions as it goes through nodes.
**************************************************************************/
Character* QueueNode::getFighter()
{
     return fighter;
}



/**************************************************************************
 * Passed: Node ptr assigned to previous node link
 * Returns:
 * Description: Used in Queue class when reassigning the head to a new
 * tail or when deleting the old head and reassignming the new head to
 * the old tail
**************************************************************************/
void QueueNode::setPreviousNode(QueueNode* pNode)
{
     previousNode = pNode;
}



/**************************************************************************
 * Passed:
 * Returns: Node ptr of a node's previous node in list
 * Description: Used in Queue class in instances where the address of the
 * last node in the queue needs to be located. Done so by instancing the
 * head node with a call to this function. 
**************************************************************************/
QueueNode* QueueNode::getPreviousNode()
{
     return previousNode;
}



/**************************************************************************
 * Passed: Node ptr assigned to next node link
 * Returns:
 * Description: Used in Queue class when removing the old head and setting
 * the link of the old tail to the new head. Also used to assign next link
 * to nullptr when list length goes down to one node after a deletion.
**************************************************************************/
void QueueNode::setNextNode(QueueNode* nNode)
{
     nextNode = nNode;
}



/**************************************************************************
 * Passed:
 * Returns: Node ptr of a node's previous node in list
 * Description: Used in Queue to reassign head when the current head is
 * being removed and to access and assign a new tail within member functions.
**************************************************************************/
QueueNode* QueueNode::getNextNode()
{
     return nextNode;
}
