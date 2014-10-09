#ifndef DLIST_H
#define DLIST_H
#include<iostream>
#include"exceptions.h"
using namespace std;
template <class T>
class doubly_list
{
	class Node
	{
		public:
			T info;
			Node* next, *prev;
			Node(T in, Node* n = 0, Node* p = 0)
			{
				info = in;
				next = n;
				prev = p;
			}
	}* front, * rear;
	int count;
	public:
		bool isEmpty()
		{
			return (front == 0);
		}
		doubly_list()
		{
			front = 0;
			rear = 0;
			count = 0;
		}
		int size()
		{
			return count;
		}
		void insert_front(T);
		void insert_rear(T);
		T pop_front();
		T pop_rear();
		T& operator[] (int pos);
		int get_pos(T);
		~doubly_list()
		{
			Node* temp;
			while (!isEmpty())
			{
				temp = front->next;
				delete front;
				front = temp;
				
			}
		}
};
template <class T> void doubly_list<T>::insert_front(T item)
{
	if(isEmpty())
		front = rear = new Node(item);
	else
	{
		front->prev = new Node(item, front);
		if (front == rear)					//Only one element in list
			rear->prev = front->prev;
		front = front->prev;
	}
	if (front == 0)
		throw Error("Memory can not be allocated");
	count++;
}
template <class T> void doubly_list<T>::insert_rear(T item)
{
	if (!isEmpty())
	{
		rear->next = new Node(item, 0, rear);
		if (rear->next == 0)
			throw Error("Memory can not be allocated");
		rear = rear->next;
	}
	else								//Empty list
	{
		rear = new Node(item);
		if (rear == 0)
			throw Error("Memory can not be allocated");
		front = rear;
	}
	count++;
}
template <class T> T doubly_list<T>::pop_front()
{
	if (isEmpty())
		throw Error("List Underflow");
	T del = front->info;
	Node* temp = front;
	if (front == rear)						//Only one element in list
		front = rear = 0;
	else
	{
		front = front->next;
		front->prev = 0;
	}
	delete temp;
	count--;
	return del;
}
template <class T> T doubly_list<T>::pop_rear()
{
	if (isEmpty())
		throw Error("List Underflow");
	T del = rear->info;
	if (front == rear)						//Only one element in list
	{
		delete front;
		front = rear = 0;
	}
	else
	{
		Node* temp = rear->prev;
		delete rear;
		rear = temp;
		rear->next = 0;
	}
	count--;
	return del;
}
template <class T> T& doubly_list<T>::operator[] (int pos)
{
	if (isEmpty())
		throw Error("Empty List");
	if (pos == -1)							//Last element
		return (rear->info);
	if (pos < -1)
		pos += count;
	if (pos < 0 || pos >= count)
		throw Error("Invalid Position");
	Node* cur;
	if (pos < count / 2)						//In the first half
	{
		cur = front;
		for (int i = 0; i < pos; i++)
			cur = cur->next;
	}
	else
	{
		cur = rear;
		for (int i = count - 1; i > pos; i--)
			cur = cur->prev;
	}
	return cur->info;
}
template <class T> int doubly_list<T>::get_pos(T item)
{
	if (isEmpty())
		throw Error("Empty List");
	Node* cur = front;
	int i;
	for(i = 0; cur->info != item && cur->next != 0; i++)
		cur = cur->next;
	if (cur->info == item)
		return i;
	return -(count + 1);
}
#endif
