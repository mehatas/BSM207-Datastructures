/** 
* @file AVL.cpp
* @description AVL sınıfına ait kurucu, ekleme, silme, postorder olarak dolaşma, yıkıcı gibi  
* fonksiyonlarını içerir.AVL agacı olusturulmasını saglayan kod.
* @course 2.Öğretim/A
* @assignment 2. Ödev
* @date 26.12.2021
* @author Mehmet ATAŞ / mehmet.atas5@ogr.sakarya.edu.tr
*/
#include "AVL.hpp"
Dugum::Dugum(DogruKuyrugu*& itm,Dugum *sl=NULL,Dugum *sg=NULL){
			kuyruk=new DogruKuyrugu();
			kuyruk=itm;
			data=itm->front->uzunluk;
			left = sl;
			right = sg;
			height=0;
		}
Dugum* AVL::SearchAndAdd(Dugum *subNode,const int& data, DogruKuyrugu*& item){
	if(subNode == NULL) subNode = new Dugum(item);
	else if(data <= subNode->data){
		subNode->left = SearchAndAdd(subNode->left,data,item);
				
		if(Height(subNode->left) == Height(subNode->right)+2){
			if(data <= subNode->left->data)
				subNode = SwapWithLeftChild(subNode);
			else{
				subNode->left = SwapWithRightChild(subNode->left);
				subNode = SwapWithLeftChild(subNode);
			}
		}
	}
	else if(data > subNode->data){
		subNode->right = SearchAndAdd(subNode->right,data,item);
				
		if(Height(subNode->right) == Height(subNode->left)+2){
			if(data > subNode->right->data)
				subNode = SwapWithRightChild(subNode);
			else{
				subNode->right = SwapWithLeftChild(subNode->right);
				subNode = SwapWithRightChild(subNode);
			}
		}
	}
	else;
			
	subNode->height = Height(subNode);
	return subNode;
}
Dugum* AVL::SwapWithLeftChild(Dugum *subNode){
	Dugum *tmp = subNode->left;
	subNode->left = tmp->right;
	tmp->right = subNode;
			
	subNode->height = Height(subNode);
	tmp->height = 1+max(Height(tmp->left),subNode->height);
			
	return tmp;
}
Dugum* AVL::SwapWithRightChild(Dugum *subNode){
	Dugum *tmp = subNode->right;
	subNode->right = tmp->left;
	tmp->left = subNode;
			
	subNode->height = Height(subNode);
	tmp->height = 1+max(Height(tmp->right),subNode->height);
			
	return tmp;
}
bool AVL::DeleteNode(Dugum *&subNode){
	Dugum *delNode = subNode;
			
	if(subNode->right == NULL) subNode = subNode->left;
	else if(subNode->left == NULL) subNode = subNode->right;
	else{
		delNode = subNode->left;
		Dugum *parentNode = subNode;
		while(delNode->right != NULL){
			parentNode = delNode;
			delNode = delNode->right;
		}
		subNode->data = delNode->data;
		if(parentNode == subNode) subNode->left = delNode->left;
		else parentNode->right = delNode->left;
	}
	delete delNode;
	return true;
}
void AVL::postorder(Dugum* subNode){
	if(subNode != NULL){
		postorder(subNode->left);
		postorder(subNode->right);
		cout<<*subNode->kuyruk<<" "<<endl;
	}
}
int AVL::Height(Dugum *subNode){
	if(subNode == NULL) return -1;
	return 1+max(Height(subNode->left),Height(subNode->right));
}
AVL::AVL(){
	root = NULL;
}
bool AVL::isEmpty()const{
	return root == NULL;
}
void AVL::Add(const int& data, DogruKuyrugu*& item){
	root = SearchAndAdd(root,data,item);
}
void AVL::postorder(){
	postorder(root);
}
int AVL::Height(){
	return Height(root); 
}
void AVL::Clear(){
	while(!isEmpty()) DeleteNode(root);
}
AVL::~AVL(){
	Clear();
}