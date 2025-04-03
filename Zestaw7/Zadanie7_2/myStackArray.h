#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <array>

template <typename T, std::size_t N>
class ArrayStack{
    std::array<T, N> my_array;
    std::size_t position_of_top;

    public:
        ArrayStack(){ position_of_top = 0; }

        bool empty(){ return position_of_top == 0; }

        bool full(){ return position_of_top == N; }

        void push(T &&item){
            if(!full()){
                my_array[position_of_top++] = std::move(item);
            }
        }

        void push(T &item){
            if(!full()){
                my_array[position_of_top++] = item;
            }
        }

        T top(){ return my_array[position_of_top - 1]; }

        void pop(){
            if(!empty()) --position_of_top;
        }

        std::size_t size(){ return position_of_top; }

        void display(){
            if(!empty()){
                for(std::size_t i = 0; i < position_of_top; i++){
                    std::cout << my_array[i] << " ";
                }
            }
            std::cout << std::endl;
        }
        void clear(){ position_of_top = 0; }
};


#endif
