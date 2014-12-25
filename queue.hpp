#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include"exceptions.h"
using namespace std;
template<class T, int sz = 100>
class queue
{
	int f, r;
	int count;
	T* nodes;
	public:
		//Check for Empty Queue - Returns true if empty, else false
		bool isEmpty()
		{
			return (count == 0);
		}
		//Check for Full Queue - Returns true if full, else false
		bool isFull()
		{
			return (count == sz);
		}
		//Returns size of the queue
		int size()
		{
			return count;
		}
		//Default Constructor
		queue() : f(0), r(-1), count(0)
		{
			nodes = new T[sz];
		}
		//Insert element at rear
		void enqueue(T);
		//Delete element from front
		void dequeue();
		//Returns reference of the first element of queue
		T& front()
		{
			if (isEmpty())
				throw Error("Empty Queue");
			return nodes[f];
		}
		//Destructor
		~queue()
		{
			delete [] nodes;
		}
};
template <class T, int sz> void queue<T, sz>::enqueue(T item)
{
	if (isFull())
		throw Error("Queue Overflow");
	r = (r + 1) % sz;
	nodes[r] = item;
	count++;
}
template <class T, int sz> void queue<T, sz>::dequeue()
{
	if (isEmpty())
		throw Error("Queue Underflow");
	f = (f + 1) % sz;
	count--;
}
#endif
