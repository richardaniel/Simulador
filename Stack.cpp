#include <iostream>
#include "Stack.hpp"

template <class T>

void MyStack<T>::push(const T& valor){

    Nodo* Temp = new Nodo(valor);
    Temp->sig=top;
    top=Temp;
}

template <class T>
void MyStack<T>::pop(){
    if(empty()){
        std::cout<<"La pila esta vacia"<<std::endl;
        return;
    }
    else{
            Nodo* temp = top;
            top=top->sig;
            delete temp;
    }
}


template <class T>
T& MyStack<T>::peek(){
    if(empty()){
        std::cout<<"La pila esta vacia. No se puede realizar la operacion"<<std::endl;
        exit(1);
    }
    return top->dato;
}

template <class T>
bool MyStack<T>::empty(){
    return (top==NULL);
}


