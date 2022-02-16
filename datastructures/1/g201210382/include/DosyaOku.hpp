#ifndef DOSYAOKU_HPP
#define DOSYAOKU_HPP

#include "DoublyLinkedList.hpp"
#include <fstream>

class DosyaOku{
private:
	char karakter;
	int konum;
	string veri="";
	string altVeri="";
public:
	void dosyaOku();
};

#endif