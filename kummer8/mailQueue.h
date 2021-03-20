// File: mailQueue.h
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/12/20

#pragma once
#include <iostream>
#include <string>
#include "mailStack.h"

//declaration of a mailbox queue
class MailQueue
{
    public:
        MailQueue(); //default constructor
        MailQueue(int); //param constructor
        MailQueue(const MailQueue&); //copy constructor
        ~MailQueue(); //destructor
        bool isEmptyQueue() const; //check if queue is empty
        bool isFullQueue() const; //check if queue is full
        void initializeQueue(); //set values of queue
        void destroyQueue(); //same as initialize
        MailStack front() const; //get the item from front of queue
        MailStack back() const; //get the item from back of queue
        void addQueue(MailStack); //add an item to the back of queue
        void removeFront(); //take item from the front of queue
        const MailQueue& operator=(MailQueue&); //assignment operator
        int getCount();
        int getQueueFront();
        int getQueueRear();

    private:
        int maxQueueSize; //how big the queue can be
        int count; //number of items in queue
        int queueFront; //position of item at front
        int queueRear; //position of item at rear
        MailStack* mailStack; //array of mail stacks
};
