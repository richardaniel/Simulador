#include "Queue.h"
#include <iostream>
#include "nodo.h"

using namespace std;

void Queue::enqueue(int valor){
	
	nodo* T = new nodo();
	T->dato=valor;

	T->sig =NULL;
	
	if(empty()){
		I=T;
	}
	else{
		F->sig=T;
	}
	F=T;
}

void Queue::dequeue(){
	I=I->sig;
	T=NULL;
}

bool Queue::empty(){
	return(I==NULL);
}

void Queue::print(){
	
	nodo* A=I;
	
	while(A!=NULL){
		cout<<A->dato<<endl;
	
		A=A->sig;
	}

}

void Queue::peek(){
	cout<<"Elemento en cola: "<<I->dato<<endl;
	
	
}
