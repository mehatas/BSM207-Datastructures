#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "Node.hpp"

class DoublyLinkedList{
private:
	Node *head;
	int size;
	
	Node* FindPreviosNode(int);
public:
	DoublyLinkedList();
	void insert(int, const string&);
	void removeAt(int);
	friend ostream& operator<<(ostream&,DoublyLinkedList&);
	~DoublyLinkedList();
};
#endif