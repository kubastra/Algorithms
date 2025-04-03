#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>


template <typename T>
class MyStack {
    std::vector<T> lst;
public:
    MyStack(std::size_t s=10) { lst.reserve(s); } // default constructor
    ~MyStack() { lst.clear(); }
    MyStack(const MyStack& other); // copy constructor
    MyStack(MyStack&& other); // move constructor
    MyStack& operator=(const MyStack& other); // copy assignment operator, return *this
    MyStack& operator=(MyStack&& other); // move assignment operator, return *this
    bool empty() const { return lst.empty(); } // checks if the container has no elements
    bool full() const { return lst.size() == lst.capacity(); }
    std::size_t size() const { return lst.size(); }
    std::size_t max_size() const { return lst.capacity(); }
    void push(const T& item) { lst.push_back(item); }
    void push(T&& item) { lst.push_back(std::move(item)); }
    T& top() { return lst.back(); } // zwraca koniec, nie usuwa
    void pop() { lst.pop_back(); } // usuwa koniec
    void clear() { lst.clear(); }
    void display();
};
// for (auto w : input) { /* sprawdzanie w */ }
// std::vector<std::string> input { "-6", "+2", "/" };
// assert( rpn(input) == -3 );
int rpn(const std::vector<std::string>& input){
    MyStack<std::string> stos;

    for ( const auto &w : input ){
        if(isdigit(w[0]) || (w[0] == '-' && w.size() >= 2)) {
            stos.push(w);
        }else if(w == "+" || w == "-" || w == "/" || w == "*"){
            if(stos.size() < 2){
                throw std::invalid_argument("Za malo liczb aby wykonac operacje");
            }
            std::string a1 = stos.top();
            stos.pop();
            std::string b1 = stos.top();
            stos.pop();

            int a = stoi(a1);
            int b = stoi(b1);

            int wynik;

            if(w == "+") wynik = b + a;
            else if(w == "-") wynik = b - a;
            else if(w == "*") wynik = b * a;
            else if(w == "/") {
                if(a == 0){
                    throw std::invalid_argument(" Nie mozna dzielic przez 0 ");
                }
                wynik = b / a;
            }

            std::string wynikAsString = std::to_string(wynik);

            stos.push(wynikAsString);
        }

    }
    if(stos.size() == 1){
        return stoi(stos.top());
    }else{
        throw std::invalid_argument("Bledne argumenty");
    }
    return 0;
}

#endif

