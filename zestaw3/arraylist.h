#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>     // assert()
#include <algorithm>

template <typename T>
class ArrayList {
    T* tab;
    int msize; // najwieksza mozliwa liczba elementow
    int last; // pierwsza wolna pozycja
public:
    ArrayList(int s=10) : msize(s), last(0) {
        assert( s > 0 && "the maximum size of elements is <= 0");
        tab = new T[s];
        assert( tab != nullptr && "list is nullptr");
    } // default constructor

    ~ArrayList() {
	delete[] tab;
    }

    //copy constructor    usage: ArrayList<int> list2(list1);
    ArrayList(const ArrayList& other){
	msize = other.msize;
	last = other.last;
	tab = new T[msize];
	for(int i = 0; i < last; i++) tab[i] = other.tab[i];
    }

    // move constructor NIEOBOWIAZKOWE   // usage:   ArrayList<int> list2(std::move(list1));
    ArrayList(ArrayList&& other){
	tab = other.tab;
	msize = other.msize;
	last = other.last;

	other.tab = nullptr;
	other.msize = 0;
	other.last = 0;
    }

     // usage:   list2 = list1; // copy assignment operator, return *this
    ArrayList& operator=(const ArrayList& other){
	if(this != &other){
		delete[] tab;
		msize = other.msize;
		last = other.last;
		tab = new T[msize];
		for(int i = 0; i < last; i++) tab[i] = other.tab[i];
	}
	return *this;
    }

    // move assignment operator, return *this  // usage:   list2 = std::move(list1); NIEOBOWIAZKOWE
    ArrayList& operator=(ArrayList&& other){
	if(this != &other){
		delete []tab;
		tab = other.tab;
		msize = other.msize;
		last = other.last;
		other.tab = nullptr;
		other.msize = 0;
		other.last = 0;
	}
	return *this;
    }

    bool empty() const { return last == 0; } // checks if the container has no elements
    bool full() const { return last == msize; } // checks if the container is full
    int size() const { return last; } // liczba elementow na liscie
    int max_size() const { return msize; } // najwieksza mozliwa liczba elementow


    void push_front(const T& item){
	assert(full() == false && "Lista pelna");

	for(int i = last; i > 0; i--) tab[i] = tab[i - 1];
	tab[0] = item;
	last++;
    }

    // dodanie na poczatek NIEOBOWIAZKOWE
    void push_back(T&& item){
	assert(full() == false && "Lista pelna");
	tab[last++] = std::move(item);
    }

    void push_back(const T& item){
	assert(full() == false && "Lista pelna");
	tab[last++] = item;
    }

    // dodanie na koniec NIEOBOWIAZKOWE
    void push_front(T&& item){
	assert(full() == false && "Lista pelna");
	for(int i = last; i > 0; i--) tab[i] = std::move(tab[i - 1]);

	tab[0] = std::move(item);
	last++;

    }

    // zwraca poczatek, nie usuwa, error dla pustej listy
    T& front(){
	assert(empty() == false && "Lista pusta");
	return tab[0];
    }

    // zwraca koniec, nie usuwa, error dla pustej listy
    T& back(){
	assert(empty() == false && "Lista pusta");
	return tab[last - 1];
    }

    // usuwa poczatek, error dla pustej listy
    void pop_front(){
	assert(empty() == false && "Lista pusta");
	for(int i = 0; i < last; i++) tab[i] = tab[i + 1];
	last--;
    }

    // usuwa koniec, error dla pustej listy
    void pop_back(){
	assert(empty() == false && "Lista pusta");
	last--;
    }

    // czyszczenie listy z elementow
    void clear(){
	last = 0;
    }

    // lepiej zdefiniowac operator<<
    void display(){
	for(int i = 0; i < last; i++) std::cout<<tab[i]<<" ";
	std::cout<<std::endl;
    }

    // odwracanie kolejnosci
    void reverse(){
	for(int i = 0; i < last / 2; i++) std::swap(tab[i], tab[last - i - 1]);
    }

    //sortowanie listy
    void sort(){
	std::sort(tab, tab + last);
    }

    void merge(ArrayList& other); //  merges two sorted lists into one NIEOBOWIAZKOWE

    // Operacje z indeksami. NIEOBOWIAZKOWE
    // https://en.cppreference.com/w/cpp/language/operators
    // Array subscript operator

    // podstawienie L[pos]=item, odczyt L[pos]
    T& operator[](int pos){
	assert(pos >= 0 && pos < last && "Indeks poza lista");
	return tab[pos];
    }

    // dostep do obiektu const
    const T& operator[](int pos) const{
	assert(pos >= 0 && pos < last && "Indeks poza lista");
	return tab[pos];
    }

    // usuniecie elementu na pozycji pos
    void erase(int pos){
	assert(pos >= 0 && pos < last && "Indeks poza lista");
	for(int i = pos; i < last - 1; i++) tab[i] = tab[i + 1];
	last--;
    }

    // jaki index na liscie (-1 gdy nie ma)
    int index(const T& item){
	for(int i = 0; i < last; i++){
		if(tab[i] == item) return i;
	}
	return -1;
    }

    // inserts item before pos
    void insert(int pos, const T& item){
	assert(full() == false && pos >= 0 && pos < last && "Indeks poza lista, badz pelna");
	for(int i = last; i > pos; i--){
		tab[i] = tab[i - 1];
	}
	tab[pos] = item;
	last++;
    }

    // inserts item before pos
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.
    void insert(int pos, T&& item){
	assert(full() == false && pos >=0 && pos < last && "Indeks poza lista, badz pelna");
	for(int i = last; i > pos; i--) tab[i] = tab[i - 1];

	tab[pos] = std::move(item);
	last++;
    }

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) {
            os << L.tab[i] << " ";
        }
        return os;
    }
};

#endif
