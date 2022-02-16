/** 
* @file DogruKuyrugu.cpp
* @description DogruKuyrugu sınıfına ait kurucu, ekleme, silme, peek, oncelikli olarak cikarma(peekMax()),ekrana yazdırma ve yıkıcı 
* fonksiyonlarını içerir.Kuyruk düğümleri de bu dosya icerisinde olusturulur.Kısaca kuyruk nesnesi olusturur.
* (Oncelik eklerken degil cikartilirken saglanir).
* @course 2.Öğretim/A
* @assignment 2. Ödev
* @date 26.12.2021
* @author Mehmet ATAŞ / mehmet.atas5@ogr.sakarya.edu.tr
*/
#include "DogruKuyrugu.hpp"
Node::Node (int itm,int uz, Node *nxt=NULL){
	item=itm;
	uzunluk=uz;
	next=nxt;
}
Node* DogruKuyrugu::previousMaxNode() const{
	Node *prev=NULL;
	Node *tmp=front;
	int max=front->item;
	while(tmp->next!=NULL){
		if(tmp->next->item < max){
			max=tmp->next->item;
			prev=tmp;
		}
		tmp=tmp->next;
	}
	return prev;
}
DogruKuyrugu::DogruKuyrugu(){
	front=back=NULL;
	lenght=0;
}
bool DogruKuyrugu::isEmpty()const{
	return lenght == 0;
}
void DogruKuyrugu::enqueue(int item, int uzunluk){
	Node *last = new Node (item, uzunluk);
	if(isEmpty()) front=back=last;
	else{
		back->next=last;
		back=last;
	}
	lenght++;
}
int DogruKuyrugu::peek() const{
	if(isEmpty()) throw "Hata";	
	return front->item;
}
int DogruKuyrugu::peekMax() const{
	if(isEmpty()) throw "Hata";
	Node *prev = previousMaxNode();
	if(prev==NULL) return peek();
	return prev->next->item;
}
void DogruKuyrugu::dequeue(){
	if(isEmpty()) throw "Hata";
	Node *del =front;
	front=front->next;
	delete del;
	lenght--;
}
void DogruKuyrugu::dequeueMax(){
	if(isEmpty()) throw "Hata";
	Node *prev = previousMaxNode();
	Node *del;
	if(prev==NULL) {
		dequeue();
	}
	else{
		if(prev->next == back) back=prev;
		del=prev->next;
		prev->next=del->next;
		delete del;
		lenght--;
	}
}
ostream& operator<<(ostream& screen, DogruKuyrugu& right){
	while(right.front!=NULL){
		screen<<setw(5)<<right.peekMax();
		if(right.front->next!=NULL)
			screen<<" ";
		right.dequeueMax();
	}
	return screen;
}
void DogruKuyrugu::clear(){
	while(!isEmpty())
		dequeue();
}
DogruKuyrugu::~DogruKuyrugu(){
	clear();
}