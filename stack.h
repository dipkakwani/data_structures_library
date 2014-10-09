#ifndef STACK_H
#define STACK_H
#include<iostream>
#include"exceptions.h"
using namespace std;
template<class T, int size = 100>
class stack
{
	int top;
	T *nodes;
	public:
		bool isEmpty()
		{
			return (top == -1);
		}
		bool isFull()
		{
			return (top == size - 1);
		}
		void push(T);
		void pop();
		T get_top();
		stack()
		{
			top = -1;
			nodes = new T[size];
		}
		~stack()
		{
			delete nodes;
		}
};
template <class T, int size> void stack<T, size>::push(T item)
{
	if(isFull())
		throw Error("Stack Overflow");
	nodes[++top] = item;
}
template <class T, int size> void stack<T, size>::pop()
{
	if(isEmpty())
		throw Error("Stack Underflow");
	top--;
}
template <class T, int size> T stack<T, size>::get_top()
{
	if(isEmpty())
		throw Error("Empty Stack");
	return nodes[top];
}
#endif
