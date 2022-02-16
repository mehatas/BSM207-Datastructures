/** 
* @file DoublyLinkedList.cpp
* @description DoublyLinkedList sınıfına ait kurucu, eleman ekleme, silme, ekrana yazdırma ve yıkıcı 
* fonksiyonlarını içerir.Kısaca eleman ekleme, silme ve listeyi ekrana yazdırma işlemlerini gerçekleştirir.
* @course 2.Öğretim/A
* @assignment 1. Ödev
* @date 7.11.2021
* @author Mehmet ATAŞ / mehmet.atas5@ogr.sakarya.edu.tr
*/
#include "DoublyLinkedList.hpp"
	
Node* DoublyLinkedList::FindPreviosNode(int index){
	Node *prv = head;
	int i=1;
	for (Node *itr = head ; itr -> next !=NULL && i != index ; itr=itr->next, i++){
		prv = prv-> next;
	}
	return prv; 
}	
DoublyLinkedList::DoublyLinkedList(){
	head = NULL;
	size=0;
}
void DoublyLinkedList::insert(int index, const string& item){
	if (index<0) throw "HATA";
	if (size == 0){
		head = new Node(item, head, head);
		if (head->next != NULL){
			head->next->prev== head;
		}
	}
	else if(index >= size){
		Node *prv = FindPreviosNode(size);
		prv->next=new Node(item,prv->next,prv);
	}
	else{
		Node *prv = FindPreviosNode(size);
		prv->next=new Node(prv->data,prv->next,prv);
		for(int i=size-1;i>index;i--){
			prv->data=prv->prev->data;
			prv=prv->prev;
		}
		prv->data=item;		
	}
	size++;
}
void DoublyLinkedList::removeAt(int index){
	if (index<0) throw "HATA";
	Node *del;	
	if(index>=size || index==(size-1)){
		if(size==1 || index==0){
			del = head;
			head = head->next;
			if(head!=NULL)
				head->prev = NULL ;
		}	
		else{
			Node *prv = FindPreviosNode(size-1);
			del = prv->next;
			prv->next= del->next;
		}
	}
	else{				
		Node *prv = FindPreviosNode(index+1);
		del=prv->next;
		for(int i=index+1;i<size; i++){
			prv->data=del->data;
			if(del->next==NULL){
				prv->next=del->next; 
			}
			else{
				prv=prv->next;
				del=del->next;
			}
		}
	}
	size--;
	delete del;
}	
ostream& operator<<(ostream& screen,DoublyLinkedList& rgt){
	for(Node *itr=rgt.head;itr!=NULL; itr=itr->next){
		screen<<itr->data;
		if(itr->next!=NULL) screen << "<-->";
	}
	screen<< endl ;
	return screen;
}	
DoublyLinkedList::~DoublyLinkedList(){
	while(size!=0)
		removeAt(0);
}