#include "doublelist.h"
#include <iostream>

int main(){
    std::cout << " Testy sprawdzajace dzialanie DoubleList " << std::endl;
    DoubleList<int> lista;

    lista.push_back(1);
    lista.push_back(2);
    lista.push_front(0);

    std::cout << " Lista po dodaniu 1 2 0 za pomoca push_back i front " << std::endl;
    lista.display();

    assert(lista.size() == 3);
    assert(!lista.empty());

    lista.pop_front();
    lista.pop_back();

    assert(lista.size() == 1);
    std::cout << " Lista po usunieciu 0 i 2 za pomoca pop_front i back " << std::endl;

    lista.display();

    DoubleList<int> lista2 = lista;

    std::cout << " Lista 2 = oryginalnej " << std::endl;
    lista2.display();

    lista.push_back(100);

    lista2 = lista;

    std::cout << " Lista 2 po dodaniu do listy 1 100 i przypisaniu lista2 = lista1 " << std::endl;
    lista2.display();

    return 0;
}
