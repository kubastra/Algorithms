#include "rpn.h"
#include <cassert>


int main() {

    std::vector<std::string> stos;
    stos = {"1", "8" ,"2", "/", "+", "-4", "*"};
    assert(stos.size() == 7);
    std::cout << "Wynik pierwszego wyrazenia ONP: " << rpn(stos) << std::endl;

    try{
        stos.clear();
        stos = {"1", "0", "/"};
        std:: cout << "Wynik drugiego wyrazenie ONP: " << rpn(stos) << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "\033[31mBlad:" << e.what() <<  "\033[0m" << std::endl;
    }

    try {
        stos.clear();
        stos = {"1", "1", "1", "+"};
        std::cout << "Wynik trzeciego wyrazenie ONP: " << rpn(stos) << std::endl;
    }
    catch (const std::invalid_argument& e){
        std::cout << "\033[31mBlad: " << e.what() << "\033[0m" <<std::endl;
    }
    return 0;
}
