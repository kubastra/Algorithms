#include "quick.h"


int main(){

	int tab[] = {41, 2, 45,1,0,99, 41};
	int rozmiar = sizeof(tab)/sizeof(tab[0]);

	cout<<"Tablica przed sortowaniem:"<<endl;
	for(int i = 0; i < rozmiar; i++){
		cout<<tab[i]<<" ";
	}
	cout<<endl<<"Tablica po sortowaniu:"<<endl;

	quicksort(tab, 0, rozmiar - 1);

	for(int i = 0; i < rozmiar; i++){
		cout<<tab[i]<<" ";
	}
	cout<<endl;

	return 0;
}
