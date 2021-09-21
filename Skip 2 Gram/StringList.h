#include <iostream>

using namespace std;

class StringList
{
private:
	struct Node
	{
		string data;
		Node* next;
	};
	Node *head;
public:
	StringList();
	void appendNode(string newVal);
  void skip2Gram();
	void printList() const;
};
