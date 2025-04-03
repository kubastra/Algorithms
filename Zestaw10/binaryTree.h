#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <stack>
#include <cassert>
#include <queue>

template <typename T>
struct BSTNode {
    T value;
    BSTNode *left, *right;


    BSTNode() : value(T()), left(nullptr), right(nullptr) {}

    BSTNode(const T& item) : value(item), left(nullptr), right(nullptr) {}

    ~BSTNode() { delete left; delete right; }
};

// Szablon dla przypadkowego drzewa binarnego.
template <typename T>
class RandomBinaryTree {
    BSTNode<T> *root;
public:
    RandomBinaryTree() : root(nullptr) {} // konstruktor domyślny
    ~RandomBinaryTree() { delete root; } // trzeba wyczyścić (rekurencyjnie)
    void clear() { delete root; root = nullptr; }
    bool empty() const { return root == nullptr; }
    T& top() { assert(root != nullptr); return root->value; } // podgląd korzenia
    void insert(const T& item) { root = insert(root, item); }
    //void remove(const T& item); // na razie nie usuwamy elementów
    // Szukając element dostajemy wskaźnik do elementu lub nullptr.
    T* search(const T& item) const {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }
    T* find_min();
    T* find_max();
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    void iter_preorder();
    void iter_inorder(); // trudne
    void iter_postorder(); // trudne
    void bfs(); // przejście poziomami (wszerz)
    void display() { display(root, 0); }

    // Metody bezpośrednio odwołujące się do node.
    // Mogą działać na poddrzewie.
    BSTNode<T> * insert(BSTNode<T> *node, const T& item); // zwraca nowy korzeń
    BSTNode<T> * search(BSTNode<T> *node, const T& item) const;
    void preorder(BSTNode<T> *node);
    void inorder(BSTNode<T> *node);
    void postorder(BSTNode<T> *node);
    void display(BSTNode<T> *node, int level);
    virtual void visit(BSTNode<T> *node) {
        assert(node != nullptr);
        std::cout << "visiting " << node->value << std::endl;
    }

    int calc_leaves_iteracyjnie();
    int calc_leaves_rekurencyjnie(){ return calc_leaves_rekurencyjnie(root); }
    int calc_leaves_rekurencyjnie(BSTNode<T>* node);

};

template<typename T>
void RandomBinaryTree<T>::postorder(BSTNode<T> *node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    visit(node);
}

template<typename T>
void RandomBinaryTree<T>::preorder(BSTNode<T> *node) {
    if (node == nullptr) return;
    visit(node);
    preorder(node->left);
    preorder(node->right);
}

template<typename T>
void RandomBinaryTree<T>::inorder(BSTNode<T> *node) {
    if (node == nullptr) return;
    inorder(node->left);
    visit(node);
    inorder(node->right);
}

template <typename T>
void RandomBinaryTree<T>::display(BSTNode<T>* node, int level) {
    if (node == nullptr) return;
    display(node->right, level + 1);
    for (int i = 0; i < level; i++) {
        std::cout << "   |";
    }
    std::cout << "---" << node->value << std::endl;
    display(node->left, level + 1);
}
template<typename T>
BSTNode<T> *RandomBinaryTree<T>::insert(BSTNode<T> *node, const T &item) {
    if (node == nullptr) {
        return new BSTNode<T>(item);
    }
    if (std::rand() % 2) { // można lepiej
        node->left = insert(node->left, item);
    } else {
        node->right = insert(node->right, item);
    }
    return node; // zwraca nowy korzeń;
}

template<typename T>
int RandomBinaryTree<T>::calc_leaves_iteracyjnie() {
    if (root == nullptr) return 0;

    std::stack<BSTNode<T>*> S;
    S.push(root);
    int leaf_count = 0;

    while (!S.empty()) {
        BSTNode<T>* node = S.top();
        S.pop();

        if (node->left == nullptr && node->right == nullptr) {
            ++leaf_count;
        }
        if (node->right != nullptr) S.push(node->right);
        if (node->left != nullptr) S.push(node->left);
    }
    return leaf_count;
}

template<typename T>
int RandomBinaryTree<T>::calc_leaves_rekurencyjnie(BSTNode<T>* node) {
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    return calc_leaves_rekurencyjnie(node->left) + calc_leaves_rekurencyjnie(node->right);
}


#endif
