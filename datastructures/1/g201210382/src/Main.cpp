/**
* @file Main.cpp
* @description Uygulamayı çalıştırır.
* @course 2.Öğretim/A
* @assignment 1. Ödev
* @date 10.11.2021
* @author Mehmet ATAŞ / mehmet.atas5@ogr.sakarya.edu.tr
*/
#include "DosyaOku.hpp"

int main(){
	DosyaOku *dosya = new DosyaOku();
	dosya->dosyaOku();
	delete dosya;
}