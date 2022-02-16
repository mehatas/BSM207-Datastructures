/**
* @file DosyaOku.cpp
* @description Dosyadan veri okunmasini, okunan veriyi işlemlerden geçirerek kuyruk nesnesine, kuyruk nesnesi de
* AVL ağacına atilmasini saglar. 
* @course 2.Öğretim/A
* @assignment 2. Ödev
* @date 26.12.2021
* @author Mehmet ATAŞ / mehmet.atas5@ogr.sakarya.edu.tr
*/
#include "DosyaOku.hpp"
int DosyaOku::NoktaOlustur(int x, int y, int z){
	orjin=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}
void DosyaOku::dosyaOku(){
	AVL *agac = new AVL();
	ifstream dosyaOku("doc/Noktalar.txt");
	if(dosyaOku.is_open()){
		while(getline(dosyaOku, satir)){
			DogruKuyrugu *kuyruk = new DogruKuyrugu();
			int satirdakiSayi=0 , i = 0;
			istringstream is(satir);
			while(is>>sayi)
				satirdakiSayi++;
			int *sayilar= new int[satirdakiSayi];
			istringstream is1(satir);
			while(is1>>sayi){
				sayilar[i]=sayi;
				i++;
			}
			
			int mesafe=0;
			int toplamUzunluk=0;
			for(int k=0;k<i-3;k++){
				mesafe=sqrt(pow(sayilar[k]-sayilar[(k+3)],2)+pow(sayilar[k+1]-sayilar[(k+4)],2)+pow(sayilar[k+2]-sayilar[(k+5)],2));
				toplamUzunluk+=mesafe;
				k=k+2;
			}

			for(int j = 0 ; j < i ; j++){
				NoktaOlustur(sayilar[j], sayilar[j+1], sayilar[j+2]);
				kuyruk->enqueue(orjin, toplamUzunluk);
				j=j+2;
			}
				
			agac->Add(toplamUzunluk,kuyruk);
			delete [] sayilar;
		}
	}
 	dosyaOku.close();
	
	system("ClS");
	cout<< "Postorder : "<<endl;
	agac->postorder();
	cin.ignore();
	delete agac;
}
