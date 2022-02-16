/**
* @file Test.cpp
* @description Uygulamayı çalıştırır.
* @course 2.Öğretim/A
* @assignment 2. Ödev
* @date 26.12.2021
* @author Mehmet ATAŞ / mehmet.atas5@ogr.sakarya.edu.tr
*/
#include "DosyaOku.hpp"
int main(){
	DosyaOku *Dosya = new DosyaOku();
	Dosya->dosyaOku();
	delete Dosya;
	return 0;
}