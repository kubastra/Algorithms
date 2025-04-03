#include "arraylist.h"


//w funkcji main bedziemy testować nasz arraylist.h
int main(){
	std::cout << std::endl;

	std::cout << "---------- Test domyslnego konstruktora -----------" << std::endl;
	std::cout <<"----- Test push_back i push_front ------" << std::endl;
	std::cout << std::endl;

	ArrayList<int> lista;
	lista.push_back(1);
	lista.push_front(2);
	lista.push_back(3);

	std::cout << "Lista powinna pokazywac: 2 1 3" << std::endl;
	lista.display();

	std::cout << std::endl;
	std::cout << "Test empty()" << std::endl;
	std::cout << "Czy lista pusta?" <<(lista.empty() ? " Tak " : " Nie ") << std::endl;

	std::cout << std::endl;
	std::cout << "Test maksymalnego rozmiaru" << std::endl;
	std::cout << lista.max_size() << std::endl;

	std::cout << std::endl;
	std::cout << "---------- Test konstruktora kopiujajcego -----------" << std::endl;
	std::cout << std::endl;

	ArrayList<int> kopiaListy(lista);

	std::cout << "Pierwsza lista: " << std::endl;
	lista.display();
	std::cout << "Skopiowana lista: " << std::endl;
	kopiaListy.display();
	std::cout << std::endl;

	std::cout << "---------- Test konstruktora move -----------" << std::endl;
	std::cout << std::endl;

	ArrayList<int> movedLista(std::move(lista));
	std::cout << "Przeniesiona lista: " << std::endl;
	movedLista.display();
	std::cout << "Oryginalna lista: " << std::endl;
	lista.display();

	std::cout << std::endl;
	std::cout << "---------- Test operatora kopiujacego przypisania ----------" << std::endl;
	std::cout << std::endl;

	ArrayList<int> lista1;
	lista1.push_back(80);
	lista1.push_back(81);
	lista1.push_back(82);

	std::cout << "Lista pierwsza: " << std::endl;
	lista1.display();

	ArrayList<int> lista2;
	lista2 = lista1;

	std::cout << "Lista druga po przypisaniu: " << std::endl;
	lista2.display();
	std::cout << std::endl;

	std::cout << "----------- Test insert -------------" <<std::endl;
	std::cout << std::endl;

	lista2.insert(1,2);

	std::cout << "Lista druga po insert(1,2)" << std::endl;
	lista2.display();
	std::cout << std::endl;

	std::cout << "------------- Test pop, erase, clear, reverse ------------------" << std::endl;
	std::cout << std::endl;

	ArrayList<int> l1;
	ArrayList<int> l2;

	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l1.push_front(4);
	l1.push_front(5);

	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	l2.push_back(4);
	l2.push_back(5);

	std::cout << "Posiadamy dwie listy: " << std::endl;
	l1.display();
	std::cout << std::endl;
	l2.display();
	std::cout << std::endl;

	std::cout << "Pierwsza lista po pop_front(): " << std::endl;
	l1.pop_front();
	l1.display();

	std::cout << std::endl;
	std::cout << "Druga lista po pop_back(): " << std::endl;

	l2.pop_back();
	l2.display();

	std::cout << std::endl;

	std::cout <<"Pierwsza lista po uzyciu erase(1): " << std::endl;
	l1.erase(1);
	l1.display();
	std::cout << std::endl;

	std::cout << "Pierwsza lista po clear(): " << std::endl;
	l1.clear();
	l1.display();

	std::cout << "Druga lista: " << std::endl;
	l2.display();
	std::cout << std::endl;

	std::cout << "Druga lista po uzyciu reverse(): " << std::endl;
	l2.reverse();

	l2.display();

	std::cout << std::endl;

        return 0;

}
