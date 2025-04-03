#include <iostream>
#include "myStackArray.h"
#include <cassert>

int main() {

    int const size = 5;
    ArrayStack<int, size> my_array;

    assert(my_array.empty());

    my_array.push(5);

    assert(my_array.size() == 1);

    std::cout << "Wyswietlenie top po dodaniu '5': " << my_array.top() << std::endl;

    my_array.clear();

    std::cout << "Wyczyszczenie stosu: " << std::endl;
    my_array.display();

    assert(my_array.size() == 0);
    assert(my_array.empty());

    std::cout << "Dodanie 0 1 2 3 4 do stosu i stos.display(): " << std::endl;
    for(int i = 0; i < size; i++){
        my_array.push(i);
    }

    my_array.display();

    std::cout << "Uzycie pop" << std::endl;

    my_array.pop();
    my_array.display();

    assert(my_array.size() == 4);
    assert(!my_array.full());

    return 0;
}
