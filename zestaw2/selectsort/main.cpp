#include "selectsort.h"
#include <vector>


int main(){

	cout<<endl;
	//Przyklad dla tablicy int
	int tab[] = {10, 3, 1, 4, 12, 8, 9};
	int size  = sizeof(tab)/sizeof(tab[0]);

	cout<<"Nieposortowana tablica poczatkowa int: "<<endl;

	for(int i = 0; i < size; i++){
		cout<<tab[i]<<" ";
	}

	select_sort(tab, tab + size);

	cout<<endl<<"Tablica int po posortowaniu: "<<endl;

	for(int i = 0; i < size; i++){
		cout<<tab[i]<< " ";
	}

	cout<<endl;

	cout<<endl<<endl<<"Vector char przed posortowaniem:"<<endl;

	vector<char> vec = {'z', '3', '1','0' , '4', '2', '4'};

	for(auto i : vec){
		cout<<i<< " ";
	}

	cout<<endl<<"Posortowany vector char"<<endl;

	select_sort(vec.begin(), vec.end());

	for(auto i : vec){
                cout<<i<< " ";
        }

	cout<<endl<<endl;

	return 0;


}
