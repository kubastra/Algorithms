#ifndef LISTSTACK_H
#define LISTSTACK_H

#include <iostream>
#include <forward_list>
#include <stdexcept>

template <typename T>
class ListStack{

    std::forward_list<T> my_list;
    size_t position_of_top;
    std::size_t N;

    public:
        ListStack(){ position_of_top = 0; N = 10; }

        void push(T &&item){
            if(!full()){
                my_list.push_front(std::move(item));
                position_of_top++;
            }else{
                throw std::overflow_error("Brak miejsca na liscie");
            }
        }

        void push(T &item){
            if(!full()){
                my_list.push_front(item);
                position_of_top++;
            }else{
                throw std::overflow_error("Brak miejsca na liscie");
            }
        }

        T top() {
            if(!empty()){
                return my_list.front();
            }else{
                throw std::underflow_error("Brak elementow na liscie");
            }
        }

        void pop(){
            if(!empty()){
                my_list.pop_front();
                --position_of_top;
            }else{
                throw std::underflow_error("Lista jest pusta");
            }
        }

        std::size_t size(){
            return position_of_top;
        }

        void display(){
	    if(!empty()){
            	for(const T &i : my_list){
                	std::cout << i << " ";
            	}
	    }
            std::cout << std::endl;
        }

        void clear(){
            if(!empty()){
                my_list.clear();
            }else{
                throw std::underflow_error("Lista jest pusta wiec nie da sie wyczyscic");
            }
        }

        bool full(){ return position_of_top == N; }
        bool empty(){ return position_of_top == 0; }
};


#endif
