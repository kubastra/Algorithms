#include "mydeque.h"


int main(){
	MyDeque<int> deque(4);
	assert(deque.empty());

	deque.push_front(1);
	deque.push_back(2);
	deque.push_back(3);

	assert(deque.size() == 3);

	std::cout << "Kolejka o rozmiarze 4 wygladajaca tak: " << std::endl;
	deque.display();
	deque.display_reversed();

	deque.pop_front();
	deque.pop_back();

	std::cout << "Kolejka po pop front i back " << std::endl;

	deque.display();

	assert(deque.front() == 2);
	assert(deque.back() == 2);

	deque.pop_back();

	assert(deque.empty());

	deque.push_back(1);
	deque.push_back(3);

	std::cout << " Kolejka: " << std::endl;

	deque.display();

	deque.insert(1, 2);

	std::cout <<" Kolejka po insert: " << std::endl;

	deque.display();

	deque.erase(1);

	std::cout << "Kolejka po erase: " << std::endl;

	deque.display();

	int indeks = deque.index(1);
	std::cout<< "indeks powinien byc 0:" << indeks << std::endl;
	std::cout << std::endl;

	deque.clear();

	std::cout << "Kolejka po clear: " << std::endl;

	deque.display();

	return 0;
}
