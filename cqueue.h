#ifndef CQUEUE_H
#define CQUEUE_H
#include<iostream>
#include"exceptions.h"
using namespace std;
template<class T, int size = 100>
class cqueue
{
	int front, rear;
	int count;
	T* nodes;
	public:
		bool isEmpty()
		{
			return (count == 0);
		}
		bool isFull()
		{
			return (count == size);
		}
		cqueue()
		{
			front = 0;
			rear = -1;
			count = 0;
			nodes = new T[size];
		}
		void enqueue(T);
		void dequeue();
		T get_front();
		~cqueue()
		{
			delete nodes;
		}
};
template <class T, int size> void cqueue<T, size>::enqueue(T item)
{
	if (isFull())
		throw Error("Queue Overflow");
	rear = (rear + 1) % size;
	nodes[rear] = item;
	count++;
}
template <class T, int size> void cqueue<T, size>::dequeue()
{
	if (isEmpty())
		throw Error("Queue Underflow");
	front = (front + 1) % size;
	count--;
}
template <class T, int size> T cqueue<T, size>::get_front()
{
	if (isEmpty())
		throw Error("Empty Queue");
	return nodes[front];
}
#endif
