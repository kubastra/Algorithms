#ifndef QUICKSORT_H
#define QUICKSORT_H


#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
int podzial(T* tablica, int lewy, int prawy){
	if(tablica == nullptr){
		throw invalid_argument("Pusty wskaźnik (tablica)!");
	}

	if(lewy < 0 || prawy < 0 || lewy > prawy){
		throw invalid_argument("blad (lewy, prawy)!");
	}

	T pivot = tablica[prawy];
	int i = lewy - 1;

	for(int j = lewy; j < prawy; j++){
		if(tablica[j] < pivot){
			i ++;
			swap(tablica[i], tablica[j]);
		}
	}
	swap(tablica[i + 1], tablica[prawy]);
	return i + 1;

}
template <typename T>
void quicksort(T* tablica, int lewy, int prawy){

	if(lewy < prawy){
		int piv = podzial(tablica, lewy, prawy);

		quicksort(tablica, lewy, piv - 1);
		quicksort(tablica, piv + 1, prawy);
	}
}

#endif
