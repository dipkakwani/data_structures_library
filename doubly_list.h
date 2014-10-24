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
			Node(T in = T(), Node* n = 0, Node* p = 0) : info(in), next(n), prev(p)
			{
			}
	}* head, * tail;
	int count;
	public:
		//Returns true if doubly list is empty, else false
		bool isEmpty()
		{
			return (count == 0);
		}
		//Default constructor
		doubly_list() : count(0)
		{
			head = new Node;		//Sentinal node
			tail = new Node;		//Sentinal node
			head->next = tail;
			tail->prev = head;
		}
		//Returns size of doubly list
		int size()
		{
			return count;
		}
		//Inserts element at given position
		void insert(T, int pos = 0);
		//Inserts element at front
		void insert_front(T);
		//Inserts element at rear
		void insert_rear(T);
		//Deletes element from given position
		T pop(int pos = 0);
		//Deletes element from front
		T pop_front();
		//Deletes element from rear
		T pop_rear();
		//Returns reference of element at given position
		T& operator[] (int pos);
		//Returns position of given element and returns -(size + 1), if element not found in the list
		int get_pos(T);
		//Destructor
		~doubly_list()
		{
			Node* temp;
			while (head != tail)
			{
				temp = head->next;
				delete head;
				head = temp;
			}
			delete tail;
		}
};
template <class T> void doubly_list<T>::insert(T item, int pos)
{
	if (pos == 0)
		insert_front(item);
	else if (pos == -1)
		insert_rear(item);
	else
	{
		if (pos < -1)
			pos += count;
		int i;
		if (pos > count || pos < 0)
			throw Error("Invalid Position");
		Node* cur = head;
		for (i = 0; i < pos && cur != tail; i++, cur = cur->next);
		Node* temp = new Node(item, cur->next, cur);
		cur->next->prev = temp;
		cur->next = temp;
		count++;
	}
}
template <class T> void doubly_list<T>::insert_front(T item)
{
	Node* old = head->next;
	Node* temp = new Node(item, old, head);
	if (temp == 0)
		throw Error("Memory can not be allocated");
	old->prev = temp;
	head->next = temp;
	count++;
}
template <class T> void doubly_list<T>::insert_rear(T item)
{
	Node* old = tail->prev;
	Node* temp = new Node(item, tail, old);
	if (temp == 0)
		throw Error("Memory can not be allocated");
	old->next = temp;
	tail->prev = temp;
	count++;
}
template <class T> T doubly_list<T>::pop(int pos)
{
	if (isEmpty())
		throw Error("List Underflow");
	if (pos == 0)
		return pop_front();
	if (pos == -1)
		return pop_rear();
	Node* cur = head->next;
	T del;
	int i;
	if (pos < 0)
		pos += count;
	if (pos < 0 || pos >= count)
		throw Error("Invalid Position");
	for (i = 0; i < pos && cur != tail; i++, cur = cur->next);
	del = cur->info;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	delete cur;
	count--;
	return del;
}
template <class T> T doubly_list<T>::pop_front()
{
	if (isEmpty())
		throw Error("List Underflow");
	Node* temp = head->next;
	T del = temp->info;
	temp->next->prev = head;
	head->next = temp->next;
	delete temp;
	count--;
	return del;
}
template <class T> T doubly_list<T>::pop_rear()
{
	if (isEmpty())
		throw Error("List Underflow");
	Node* temp = tail->prev;
	T del = temp->info;
	temp->prev->next = tail;
	tail->prev = temp->prev;
	delete temp;
	count--;
	return del;
}
template <class T> T& doubly_list<T>::operator[] (int pos)
{
	if (isEmpty())
		throw Error("Empty List");
	if (pos == -1)							//Last element
		return (tail->prev->info);
	if (pos < -1)
		pos += count;
	if (pos < 0 || pos >= count)
		throw Error("Invalid Position");
	Node* cur1 = head->next;
	Node* cur2 = tail->prev;
	int i = 0, j = count - 1;
	for (; i < pos && j > pos; i++, j--)
	{
		cur1 = cur1->next;
		cur2 = cur2->prev;
	}
	if (i < pos)
		return cur2->info;
	return cur1->info;
}
template <class T> int doubly_list<T>::get_pos(T item)
{
	if (isEmpty())
		throw Error("Empty List");
	Node* cur1 = head->next;
	Node* cur2 = tail->prev;
	int i, j;
	for(i = 0, j = count - 1; cur1->info != item && cur2->info != item && cur1->next != tail; i++, j--)
	{
		cur1 = cur1->next;
		cur2 = cur2->prev;
	}
	if (cur1->info == item)
		return i;
	if (cur2->info == item)
		return j;
	return -(count + 1);
}
#endif
