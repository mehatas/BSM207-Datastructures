/**
* @file DosyaOku.cpp
* @description Dosyadan veri okunmasini ve satirlarin komut olarak atanmasini saglar.
* @course 2.Öğretim/A
* @assignment 1. Ödev
* @date 10.11.2021
* @author Mehmet ATAŞ / mehmet.atas5@ogr.sakarya.edu.tr
*/
#include "DosyaOku.hpp"

void DosyaOku::dosyaOku(){
	DoublyLinkedList *isimler = new DoublyLinkedList();
	ifstream dosyaOku("doc/Veri.txt");
	while(!dosyaOku.eof()){
		dosyaOku.get(karakter);
		if (karakter=='E'){
			dosyaOku.get(karakter);
			dosyaOku>>konum;
			dosyaOku.get(karakter);
			getline(dosyaOku,veri);
			altVeri=veri.substr(0,veri.length()-1);
			isimler->insert(konum,altVeri);
		}
		else if(karakter=='S'){
			dosyaOku.get(karakter);
			dosyaOku>>konum;
			isimler->removeAt(konum);
			dosyaOku.get(karakter);
		}
	}
	dosyaOku.close();	
	
	system("ClS"); 
	cout << "Listenin son durumu:" << endl ;
	cout << *isimler ;
	cin.ignore();
	delete isimler;
}	