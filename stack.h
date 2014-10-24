#ifndef STACK_H
#define STACK_H
#include<iostream>
#include"exceptions.h"
using namespace std;
template<class T, int sz = 100>
class stack
{
	int t;
	T* nodes;
	public:
		//Check for Empty Stack - Returns true if empty, else false
		bool isEmpty()
		{
			return (t == -1);
		}
		//Check for Full Stack - Returns true if full, else false
		bool isFull()
		{
			return (t == sz - 1);
		}
		//Returns size of the stack
		int size()
		{
			return (t + 1);
		}
		//Insert element at top
		void push(T item)
		{
			if(isFull())
				throw Error("Stack Overflow");
			nodes[++t] = item;
		}
		//Delete element from top
		void pop()
		{
			if(isEmpty())
				throw Error("Stack Underflow");
			t--;
		}
		//Returns reference of the first element of stack
		T& top()
		{
			if(isEmpty())
				throw Error("Empty Stack");
			return nodes[t];
		}
		//Default Constructor
		stack() : t(-1)
		{
			nodes = new T[sz];
		}
		//Destructor
		~stack()
		{
			delete [] nodes;
		}
};
#endif
