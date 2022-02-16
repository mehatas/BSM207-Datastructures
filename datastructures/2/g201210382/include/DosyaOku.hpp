#ifndef DOSYAOKU_HPP
#define DOSYAOKU_HPP

#include "DogruKuyrugu.hpp"
#include "AVL.hpp"
#include <fstream>
#include <string>
#include <sstream>

class DosyaOku{
private: 
	string satir="";
	int orjin=0;
	int satirsayisi=0;
	int sayi;
public:
	int NoktaOlustur(int, int, int);
	void dosyaOku();
};
#endif 