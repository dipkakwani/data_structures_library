#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include"exceptions.h"
using namespace std;
template<class T, int size = 100>
class queue
{
	int front, rear;
	T* nodes;
	public:
		bool isEmpty()
		{
			return (front > rear);
		}
		bool isFull()
		{
			return (rear == size - 1);
		}
		queue()
		{
			front = 0;
			rear = -1;
			nodes = new T[size];
		}
		void enqueue(T);
		void dequeue();
		T get_front();
		~queue()
		{
			delete nodes;
		}
};
template <class T, int size> void queue<T, size>::enqueue(T item)
{
	if (isFull())
		throw Error("Queue Overflow");
	nodes[++rear] = item;
}
template <class T, int size> void queue<T, size>::dequeue()
{
	if (isEmpty())
		throw Error("Queue Underflow");
	front++;
	if (front > rear)
	{
		front = 0;
		rear = -1;
	}
}
template <class T, int size> T queue<T, size>::get_front()
{
	if (isEmpty())
		throw Error("Empty Queue");
	return nodes[front];
}
#endif
