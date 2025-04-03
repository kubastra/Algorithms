#include "bstree.h"


int main() {
    BinarySearchTree<int> drzewo;

    drzewo.insert(50);
    drzewo.insert(75);
    drzewo.insert(25);
    drzewo.insert(12);
    drzewo.insert(6);
    drzewo.insert(45);
    drzewo.insert(2);
    drzewo.insert(90);

    int* najmniejsza_wartosc = drzewo.find_min();
    int* najwieksza_wartosc = drzewo.find_max();

    std::cout << "Dla drzewa binarnego: " << std::endl;
    drzewo.display();

    std::cout << "Find_min(): " << *najmniejsza_wartosc << std::endl;
    std::cout << "Find_max(): " << *najwieksza_wartosc << std::endl;

    assert(*najwieksza_wartosc == 90);
    assert(*najmniejsza_wartosc == 2);
    return 0;
}
