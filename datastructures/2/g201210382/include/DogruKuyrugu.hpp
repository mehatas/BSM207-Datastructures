#ifndef DOGRUKUYRUGU_HPP
#define DOGRUKUYRUGU_HPP

#include <iostream>
#include <iomanip>

using namespace std;

class Node{
public: 
	int item;
	int uzunluk;
	Node *next;
		
	Node (int ,int ,Node*);

};
class DogruKuyrugu{
private:
	Node *previousMaxNode() const;
public:
	Node *front;
	Node *back;
	int lenght;
		
	DogruKuyrugu();
	bool isEmpty()const;
	void enqueue(int ,int);
	int peek() const;
	int peekMax() const;
	void dequeue();
	void dequeueMax();
	friend ostream& operator<<(ostream& ,DogruKuyrugu&);
	void clear();
	~DogruKuyrugu();
};
#endif 