#ifndef AVL_HPP
#define AVL_HPP

#include "DogruKuyrugu.hpp"
#include <cmath>

class Dugum{
	public:
		int data;
		int height;
		Dugum *left;
		Dugum *right;
		DogruKuyrugu *kuyruk;
		
		Dugum(DogruKuyrugu*&,Dugum*,Dugum*);
};
class AVL{
	private:	
		Dugum *root;
		
		Dugum* SearchAndAdd(Dugum*,const int&, DogruKuyrugu*&);
		Dugum* SwapWithLeftChild(Dugum*);
		Dugum* SwapWithRightChild(Dugum*);
		bool DeleteNode(Dugum*&);
		void postorder(Dugum*);
		int Height(Dugum*);
	public:
		AVL();
		bool isEmpty()const;
		void Add(const int&, DogruKuyrugu*&);
		void postorder();
		int Height();
		void Clear();
		~AVL();
};

#endif