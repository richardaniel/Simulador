#ifndef QUEUE_H
#define QUEUE_H
#include "nodo.h"

class Queue
{	private:
		nodo* F;
		nodo* I;
		nodo* T;
	public:
		
		void enqueue(int x);
		void dequeue();
		void peek();
		bool empty();
		void print();
	protected:
};

#endif
