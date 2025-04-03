#include "myqueue.h"

int main() {

    MyQueue<int> kolejka(5);
    assert(kolejka.empty());
    assert(!kolejka.full());

    kolejka.push(1);
    kolejka.push(2);

    kolejka.display();

    std::cout << "Top kolejki: " << kolejka.front() << std::endl;
    std::cout << "Tyl kolejki: " << kolejka.back() << std::endl;

    for(auto item : {3, 4, 5}){
        kolejka.push(item);
    }

    kolejka.display();

    kolejka.pop();

    std::cout << "Kolejka po pop(): " << std::endl;
    kolejka.display();

    kolejka.push(6);



    kolejka.display();

    try {
        kolejka.push(7);
    } catch (const std::overflow_error& e) {
        std::cout << "Proba dodania elementu o 1 za duzo: " << e.what() << std::endl;
    }

    assert(kolejka.size() == 5);


    try {
        for(int i = 0; i < 5; i++){
            kolejka.pop();
        }
        kolejka.pop();
    } catch (const std::overflow_error& e) {
        std::cout << "Proba usuniecia elementu o 1 za duzo: " << e.what() << std::endl;
    }
    return 0;
}
