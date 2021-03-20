#include "Mailbox.h"
#include "Mail.h"

Mailbox()
{
	std::string name = "Empty Box";
	Mail curMail [50] = {};
}

Mailbox(std::string tmpName) //empty mailbox constructor
{
	std::string name = tmpName;
	Mail curMail [50] = {};
}

Mailbox(std::string tmpName, Mail [] tmpMailStack) //full mailbox constructor
{
	int numOfMailToCopy = sizeof(tmpMailStack)/sizeof(tmpMailStack[0]);
	std::string name = tmpName;
	Mail curMail [50] = {};

	for(x=0; x < numOfMailToCopy; x++)
	{
		curMail[x] = tmpMailStack[0];
	}	
}

Mailbox(const Mailbox& tmpMailbox) //copy constructor
{

}

std::string getBoxName() //return name of the mailbox
{
	return this.name;
}

Mail [] dumpMail() //delete mail stack from box and return to whatever called it
{

}

Mail popMail() //removes item of mail at the front of array
{

}

pushMail(Mail tmpMail) //adds singular mail onto mail stack
{

}

