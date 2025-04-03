#include "my_apqueue.h"

int main() {
    MyPriorityQueue<int> myqueue;
    assert(myqueue.empty());

    myqueue.push(10);
    myqueue.push(20);
    myqueue.push(15);
    myqueue.display();
    assert(myqueue.size() == 3);

    std::cout << "Top element: " << myqueue.top() << std::endl;

    std::cout << "Po pop: " << std::endl;
    myqueue.pop();
    myqueue.display();
    assert(myqueue.size() == 2);

    MyPriorityQueue<int> myqueueCopy(myqueue);
    std::cout << "Test copy constructor: " << std::endl;
    myqueueCopy.display();

    MyPriorityQueue<int> myqueueAssign = myqueueCopy;
    std::cout << "Test copy assignment constructor: " << std::endl;
    myqueueAssign.display();

    std::cout << std::endl;
    MyPriorityQueue<int> moveMyqueue(std::move(myqueue));
    std::cout << "Test move constructor " << std::endl;
    std::cout << "Oryginalna po move: " << std::endl;
    myqueue.display();
    assert(myqueue.empty());
    std::cout << "Przeniesiona: " << std::endl;
    moveMyqueue.display();

    std::cout << "Test clear przeniesionej: " << std::endl;
    moveMyqueue.clear();
    moveMyqueue.display();
    assert(moveMyqueue.empty());
    return 0;
}
