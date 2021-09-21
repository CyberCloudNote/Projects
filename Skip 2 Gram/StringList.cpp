#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "StringList.h"

using namespace std;

StringList::StringList()
{
	head = nullptr;
}
void StringList::appendNode(string newVal)
{
	//check if list is empty
	if (head == nullptr)
	{
		head = new Node;
		head->data = newVal;
		head->next = nullptr;
	}
	else
	{
		// create new nodeNode 
		Node *newNode = new Node;
    Node * nodePtr = head;
		newNode->data = newVal;
		newNode->next = nullptr;
		// Travel to end of list and append node
		
		while (true)
		{
			//are we at the end of the list
			if (nodePtr->next == nullptr)
			{
				// yes we are
				nodePtr->next = newNode;
				break;
			}
			nodePtr = nodePtr->next;
		}
	}
}
void StringList::skip2Gram()
{
	ifstream inQuotes;
	inQuotes.open("quotes.txt");
	StringList completeList;
	string word, fileLine, space;
	int count = 0;

	if (inQuotes.is_open())
	{
    while(inQuotes.good())
    { 
      string tempA, tempB;
      int count = 0;
      istringstream is(fileLine);
      getline(inQuotes,fileLine);

      while ( is >> word ) 
      {
        if (count == 0)
			  {
				  completeList.appendNode(word);
			  }
			  else if (count == 1)
			  {
			  	tempA = word;
			  }
			  else if (count == 2)
			  {
			  	completeList.appendNode(word);
			  	tempB = word;
			  }
			  else if (count % 2 == 1)
			  {
			  	completeList.appendNode(tempA);
			  	completeList.appendNode(word);
			  	tempA = word;
			  }
			  else if (count % 2 == 0)
			  {
			  	completeList.appendNode(tempB);
			  	completeList.appendNode(word);
			  	tempB = word;
			  }
			  count++;
		  }
        completeList.appendNode(space);
      }
      completeList.printList();
      inQuotes.close();
    }
  }

void StringList::printList() const
{
	Node* currPtr = head;
	while (currPtr != nullptr)
	{
		cout << currPtr->data << endl;
		currPtr = currPtr->next;
	}
}
