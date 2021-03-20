// File: mailQueue.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/24/20

#include "mailQueue.h"
#include "constants.h"
#include <cassert>

/*
Description:
Creates a queue of stacks of mail. Each queue represents a box that holds mail
so that it can be quarentined an appropriate amount of time.
*/

//Default constructor
MailQueue::MailQueue() 
{
	maxQueueSize = 6;
	queueFront = 0;
    queueRear = maxMailboxSize - 1;
    count = 0;
    mailStack = new MailStack[maxMailboxSize];  
}

//Parameter Constructor
MailQueue::MailQueue(int queueSize) 
{
    if (queueSize <= 0) //don't allow queues of 0 or negative values
    {
		maxQueueSize = maxMailboxSize;
    }

    else
	{
   		maxQueueSize = queueSize;
	}

    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
    mailStack = new MailStack[maxQueueSize];  
	assert(mailStack != NULL);
}

//Copy Constructor
MailQueue::MailQueue(const MailQueue& otherQueue)
{
    maxQueueSize = otherQueue.maxQueueSize;
    count = otherQueue.count;
    queueFront = otherQueue.queueFront;
    queueRear = otherQueue.queueRear;
    mailStack  = new MailStack[maxQueueSize];

    for (int i=0; i<maxQueueSize; i++)
	{
		mailStack[i] = otherQueue.mailStack[i];
	}     
}

//Destructor
MailQueue::~MailQueue()
{
   delete [] mailStack;
}

//Check if there are any items in the queue
bool MailQueue::isEmptyQueue() const
{
   return(count == 0);
}

//Check if the queue has reached its maximum size
bool MailQueue::isFullQueue() const
{
   return(count == maxQueueSize);
}

//Restore queue to default values
void MailQueue::initializeQueue()
{
	queueFront = 0; //first index
    queueRear = maxQueueSize - 1; //last index possible
	count = 0; //number of queues
}

//Restore queue to default values
void MailQueue::destroyQueue()
{
	queueFront = 0; //first index
    queueRear = maxQueueSize - 1; //last index possible
	count = 0; //number of queues
}


//Get the item from the front of the queue or close the program if the queue is empty
MailStack MailQueue::front() const
{
    assert(!isEmptyQueue()); //close program to prevent accessing data that doesn't exist
    if(!isEmptyQueue())
    {
        return mailStack[queueFront]; 
    }
}

//Get the item from the rear of the queue or close the protram if the queue is empty
MailStack MailQueue::back() const
{
    assert(!isEmptyQueue()); //close program to prevent accessing data that doesn't exist
    if(!isEmptyQueue())
    {
        return mailStack[queueRear];
    }
}

//Add another item to the back of the queue
void  MailQueue::addQueue(MailStack newMailStack)
{
   if (!isFullQueue())
   {   
		queueRear = (queueRear + 1) % maxQueueSize; //inserts back at beginning if attempts to go out of range
   		count++;
   		mailStack[queueRear] = newMailStack;
   }

   else //shouldn't encounter if check for full queue is done
   {
 		std::cout << "! Mailbox is Full !" << std::endl;
   }
}

//Get the item from the front of the queue
void MailQueue::removeFront()
{
   if (!isEmptyQueue())
   {   
       count--;
       queueFront = (queueFront + 1) % maxQueueSize; //inserts back at beginning if attempts to go out of range
   }

   else //shouldn't encounter this if check for empty stack is done
   {
		std::cout << "! The Queue is Empty !" << std::endl;
   }	
}

//Queue assignment operator
const MailQueue& MailQueue::operator=(MailQueue& otherQueue)
{
    if(this != &otherQueue)
    {
        delete [] mailStack;
        maxQueueSize = otherQueue.maxQueueSize;
        count = otherQueue.count;
        queueFront = otherQueue.queueFront;
        queueRear = otherQueue.queueRear;
        mailStack = new MailStack[maxQueueSize];

        for (int i=0; i < maxQueueSize; i++) //go through all stacks and copy into new queue
        {
            mailStack[i] = otherQueue.mailStack[i];
        }
    }    

    return *this;
}

int MailQueue::getCount()
{
    return count;
}

int MailQueue::getQueueFront()
{
    return queueFront;
}

int MailQueue::getQueueRear()
{
    return queueRear;
}