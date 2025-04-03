#include <iostream>
#include "listStack.h"
#include <cassert>

int main() {
    ListStack<int> stos;

    std::cout << "Do stosu dodajemy elementy od 0 do 9: " << std::endl;
    for(int i = 0; i < 10; i++){
        stos.push(i);
    }

    stos.display();

    assert(stos.size() == 10);
    assert(stos.top() == 9);

    std::cout << "Nastepnie usuwamy pierwsze 6 elementow: " << std::endl;
    for(int i = 0; i < 6; i++){
        stos.pop();
    }

    stos.display();

    std::cout << "W ostatnim kroku czyscimy stos: " << std::endl;
    stos.clear();
    stos.display();

    try {
        ListStack<int> stos1;

	std::cout << "Tworzymy nowy stos z 11 elementami wiec o 1 za duzo " << std::endl;

	for (int i = 0; i < 11; i++) {
            stos1.push(i);
        }
    } catch (const std::exception& e) {
        std::cout << "\033[31mBlad: " << e.what() << "\033[0m" <<std::endl;
    }

    return 0;
}
