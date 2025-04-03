#include "singlelist.h"
#include <iostream>


int main(){
	std::cout << "Test dla copy konstruktora" << std::endl;
	SingleList<int> Lista1;
	Lista1.push_back(10);
	Lista1.push_back(11);
	Lista1.push_back(12);
	Lista1.push_back(13);

	std::cout << "Oryginalna lista:" <<std::endl;
	Lista1.display();
	std::cout << std::endl;

	SingleList<int> skopiowana(Lista1);
	assert(skopiowana.size() == Lista1.size());

	assert(skopiowana.compare(Lista1));

	std::cout << "Lista skopiowana po testach" << std::endl;
	skopiowana.display();

	std::cout << std::endl;


	SingleList<int> list;

	assert(list.empty() == true);
	assert(list.size() == 0);

	list.push_back(2);
	list.push_front(1);

	assert(list.size() == 2);
	assert(list.front() == 1);
	assert(list.back() == 2);

	std::cout << "Lista po dodaniu elementow: " << std::endl;
	list.display();
	std::cout << std::endl;

	list.push_back(3);
	list.push_front(0);

	std::cout << "Lista po dodaniu 0 i 3" << std::endl;
	list.display();

	list.pop_front();
	assert(list.size() == 3);
	assert(list.front() == 1);
	list.pop_back();

	std::cout << std::endl;

	std::cout << "Lista po popfront i popback" << std::endl;
	list.display();


	std::cout << std::endl;

	list.reverse();
	std::cout << "Lista po reverse()" << std::endl;

	list.display();

	std::cout << std::endl;

	list.clear();
	assert(list.empty() == true);
	assert(list.size() == 0);

	std::cout << "Lista po clear()" << std::endl;

	list.display();

	std::cout << "Testy przebiegly pomyslnie" << std::endl;



	return 0;
}
