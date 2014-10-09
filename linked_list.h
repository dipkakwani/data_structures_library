#ifndef LLIST_H
#define LLIST_H
#include<iostream>
#include"exceptions.h"
using namespace std;
template <class T>
class linked_list
{
	class Node
	{
		public:
			T info;
			Node* next;
			Node(T in, Node* ptr = 0)
			{
				info = in;
				next = ptr;
			}
	}* front, * rear;
	int count;
	public:
		bool isEmpty()
		{
			return (front == 0);
		}
		linked_list()
		{
			front = 0;
			rear = 0;
			count = 0;
		}
		int size()
		{
			return count;
		}
		void insert(T, int pos = 0);
		void insert_front(T);
		void insert_rear(T);
		T pop(int pos = 0);
		T pop_front();
		T pop_rear();
		T& operator[] (int pos);
		int get_pos(T);
		~linked_list()
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
template <class T> void linked_list<T>::insert(T item, int pos)
{
	if (pos == 0)
		insert_front(item);
	else if (pos == -1)
		insert_rear(item);
	else
	{
		if (pos < -1)
			pos += count;
		Node* cur = front;
		Node* pre = 0;
		int i;
		for (i = 0; cur != 0 && i < pos; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		if (cur == 0 && i < pos || pos < 0 || isEmpty())	//Handling all possible cases
			throw Error("Invalid Position");
		pre->next = new Node(item, cur);
		if (pre->next == 0)
			throw Error("Memory can not be allocated");
		if (pre == rear)					//Inserted after last element
			rear = pre->next;
		count++;
	}
}
template <class T> void linked_list<T>::insert_front(T item)
{
	front = new Node(item, front);
	if (front == 0)
		throw Error("Memory can not be allocated");
	if (rear == 0)							//Empty list
		rear = front;
	count++;
}
template <class T> void linked_list<T>::insert_rear(T item)
{
	if (!isEmpty())
	{
		rear->next = new Node(item);
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
template <class T> T linked_list<T>::pop(int pos)
{
	if (isEmpty())
		throw Error("List Underflow");
	if (pos == 0)
		return pop_front();
	else if (pos == -1)						//Last element
		return pop_rear();
	T del;
	Node* cur = front;
	Node* pre = 0;
	int i;
	if (pos < -1)
		pos += count;
	for (i = 0; cur != 0 && i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	if (cur == 0 && i < pos || pos < 0 || front == rear)
		throw Error("Invalid position");
	del = cur->info;
	pre->next = cur->next;
	if (cur == rear)
		rear = pre;
	delete cur;
	count--;
	return del;
}
template <class T> T linked_list<T>::pop_front()
{
	if (isEmpty())
		throw Error("List Underflow");
	T del = front->info;
	Node* temp = front;
	if (front == rear)						//Only one element in list
		front = rear = 0;
	else
		front = front->next;
	delete temp;
	count--;
	return del;
}
template <class T> T linked_list<T>::pop_rear()
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
		Node* temp = front;
		while (temp->next != rear)
			temp = temp->next;
		delete rear;
		rear = temp;
	}
	count--;
	return del;
}
template <class T> T& linked_list<T>::operator[] (int pos)
{
	if (isEmpty())
		throw Error("Empty List");
	if (pos == -1)							//Last element
		return (rear->info);
	if (pos < -1)
		pos += count;
	Node* cur = front;
	for (int i = 0; i < pos && cur != 0; i++)
		cur = cur->next;
	if (cur == 0 || pos < 0)
		throw Error("Invalid Position");
	return cur->info;
}
template <class T> int linked_list<T>::get_pos(T item)
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
