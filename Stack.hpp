

#include <iostream>

template <class T>

class MyStack{
    private:

    struct Nodo{
        T& dato;
        Nodo* sig;
        Nodo(const T& valor):dato(valor),sig(NULL){}
    };

    Nodo* top;

    public:
        MyStack() : top(NULL){}

        void push(const T& valor);
        void pop();
        T& peek();
        bool empty();


};