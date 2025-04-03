#include "binaryTree.h"

int main() {
    RandomBinaryTree<int> drzewo;

    drzewo.insert(10);
    drzewo.insert(7);
    drzewo.insert(20);
    drzewo.insert(5);
    drzewo.insert(6);
    drzewo.insert(1);
    drzewo.display();
    std::cout<< drzewo.calc_leaves_iteracyjnie() << std::endl;
    std::cout<< drzewo.calc_leaves_rekurencyjnie() << std::endl;

    return 0;
}
