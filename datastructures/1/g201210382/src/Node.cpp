/** 
* @file Main.cpp
* @description Düğüm oluşturulmasını sağlar.
* @course 2.Öğretim/A
* @assignment 1. Ödev
* @date 7.11.2021
* @author Mehmet ATAŞ / mehmet.atas5@ogr.sakarya.edu.tr
*/
#include "Node.hpp"

Node::Node(const string& data, Node *nx=NULL, Node *pr=NULL){
	this -> data = data ;
	next = nx ;
	prev= pr;	
}	