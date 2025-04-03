// doublelist.h

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct DoubleNode {
    T value;
    DoubleNode *next;
    DoubleNode *prev;

    DoubleNode(): value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr = nullptr, DoubleNode *pptr = nullptr)
        : value(item), next(nptr), prev(pptr) {}
    ~DoubleNode() {}
};


template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList(); // tu trzeba wyczyscic wezly

    DoubleList(const DoubleList& other); // copy constructor
    // usage:   DoubleList<int> list2(list1);

    DoubleList(DoubleList&& other); // move constructor NIEOBOWIAZKOWE
    // usage:   DoubleList<int> list2(std::move(list1));

    DoubleList& operator=(const DoubleList& other); // copy assignment operator, return *this
    // usage:   list2 = list1;

    DoubleList& operator=(DoubleList&& other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1); NIEOBOWIAZKOWE

    bool empty() const { return head == nullptr; }
    std::size_t size() const; // O(n) bo trzeba policzyc
    void push_front(const T& item); // O(1)
    void push_front(T&& item); // O(1) NIEOBOWIAZKOWE
    void push_back(const T& item); // O(1)
    void push_back(T&& item); // O(1) NIEOBOWIAZKOWE
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(1)
    void clear(); // czyszczenie listy z elementow O(n)
    void display(); // O(n)
    void display_reversed(); // O(n)

    // Operacje z indeksami. NIEOBOWIAZKOWE
    T& operator[](std::size_t pos); // podstawienie L[pos]=item, odczyt L[pos]
    const T& operator[](std::size_t pos) const; // dostep do obiektu const
    void erase(std::size_t pos);
    int index(const T& item); // jaki index na liscie (-1 gdy nie ma) O(n)
    void insert(std::size_t pos, const T& item); // inserts item before pos,
    void insert(std::size_t pos, T&& item); // inserts item before pos,
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.
};

template<typename T>
void DoubleList<T>::display_reversed() {
    if(!empty()){
        DoubleNode<T>* odTylu = tail;
        while(odTylu != nullptr){
            std::cout << odTylu->value << " ";
            odTylu = odTylu->prev;
        }
    }
    std::cout << std::endl;
}

template<typename T>
void DoubleList<T>::display() {
    if(!empty()){
        DoubleNode<T>* obecny = head;
        while(obecny != nullptr){
            std::cout << obecny->value << " ";
            obecny = obecny->next;

        }
    }
    std::cout << std::endl;
}

template<typename T>
void DoubleList<T>::clear() {
    while(!empty()){
        pop_front();	
    }

}

template<typename T>
void DoubleList<T>::pop_back() {
    if(!empty()){
        DoubleNode<T>* temp = tail;
        if(head == tail){
            head = tail = nullptr;
        }else{

            tail = tail->prev;
            tail->next = nullptr;

        }
        delete temp;
    }
}

template<typename T>
void DoubleList<T>::pop_front() {
    if(!empty()){
        DoubleNode<T>* temp = head;
        if(head == tail){
            head = tail = nullptr;
        }else{
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

}

template<typename T>
std::size_t DoubleList<T>::size() const {
    std::size_t dlg = 0;

    DoubleNode<T> *i = head;
    while(i != nullptr){
        dlg++;
        i = i->next;
    }

    return dlg;
}

template<typename T>
DoubleList<T> &DoubleList<T>::operator=(DoubleList &&other){
    if(this != &other){
        clear();
        head = other.head;
        tail = other.tail;

        other.head = nullptr;
        other.tail = nullptr;

    }

    return *this;

}

template<typename T>
DoubleList<T>::DoubleList(DoubleList &&other) {
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

template<typename T>
DoubleList<T>::~DoubleList() {
    clear();
}

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    DoubleNode<T>* nowy = new DoubleNode<T>(item);
    if (!empty()) {
        nowy->next = head;
	head->prev = nowy;
    } else {
        tail = nowy;
    }
    head = nowy;
}

template <typename T>
void DoubleList<T>::push_front(T&& item) {
    DoubleNode<T>* nowy = new DoubleNode<T>(std::move(item));
    if(!empty()){
        nowy->next = head;
        head->prev = nowy;
    }else{
        tail = nowy;
    }
    head = nowy;
}

template <typename T>
void DoubleList<T>::push_back(const T& item){
	DoubleNode<T>* nowy = new DoubleNode<T>(item);
	if(!empty()){
		nowy->prev = tail;
		tail->next = nowy;
	}else{
		head = nowy;
	}
	tail = nowy;
}

template <typename T>
void DoubleList<T>::push_back(T&& item){
	DoubleNode<T>* nowy = new DoubleNode<T>(std::move(item));
	if(!empty()){
        	nowy->prev = tail;
        	tail->next = nowy;
	}else{
        	head= nowy;
	}
	tail = nowy;
}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList& other){
	head = nullptr;
	tail = nullptr;
	for(DoubleNode<T>* current = other.head; current != nullptr; current = current->next){
		push_back(current->value);
	}
}

template <typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList& other){
	if(this != &other){
		clear();
		for(DoubleNode<T>* current = other.head; current != nullptr; current = current->next){
			push_back(current->value);
		}
	}
	return *this;
}

#endif

