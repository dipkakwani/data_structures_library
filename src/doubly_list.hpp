#ifndef DLIST_H
#define DLIST_H
#include <iostream>
#include "exceptions.hpp"
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
		{}
	}* head, * tail;
	size_t count;
public:
	
	//To iterate through all the elements in the list
	class iterator;
	
	//Returns iterator object of the first element of the list
	iterator begin() const
	{
		return iterator(this->head->next, 0);
	}
	
	//Returns iterator object of one past the last element 
	iterator end() const
	{
		return iterator(this->tail->next, count);
	}

	//Returns true if doubly list is empty, else false
	bool isEmpty() const
	{
		return (count == 0);
	}

	//Default constructor
	doubly_list() : count(0)
	{
		head = new Node;		//Sentinel node
		tail = new Node;		//Sentinel node
		head->next = tail;
		tail->prev = head;
	}

	//Copy constructor
	doubly_list(const doubly_list& other);
	
	//Assignment operator
	const doubly_list& operator= (const doubly_list& other);

	//Returns size of doubly list
	size_t size() const
	{
		return count;
	}

	//Inserts element at given position
	void insert(const T&, long long pos = 0);

	//Inserts element at front
	void insert_front(const T&);

	//Inserts element at rear
	void insert_rear(const T&);

	//Deletes element from given position
	T pop(long long pos = 0);

	//Deletes element from front
	T pop_front();

	//Deletes element from rear
	T pop_rear();

	//Returns reference of element at given position
	T& operator[] (long long pos);

	//Returns position of given element and returns -(size + 1), if element not found in the list
	long long get_pos(const T&);

	//Delete all nodes in the list
	void clear()
	{
		Node* temp;
		while (head != tail)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
		delete tail;
		head = new Node;		
		tail = new Node;		
		head->next = tail;
		tail->prev = head;
		count = 0;
	}

	//Destructor
	~doubly_list()
	{
		clear();	
		delete head;
		delete tail;
	}
};

template <class T> class doubly_list<T>::iterator
{
	friend class doubly_list;
	Node* current;
	size_t pos;
public:

	iterator(Node* ptr = 0, size_t p = 0) : current(ptr), pos(p)
	{}

	iterator(const iterator& other) : current(other.current), pos(other.pos)
	{}

	iterator& operator= (const iterator& other)
	{
		current = other.current;
		pos = other.pos;
	}

	bool operator== (const iterator& other)
	{
		return (pos == other.pos);
	}

	bool operator!= (const iterator& other)
	{
		return (pos != other.pos);
	}

	const iterator& operator++ ()
	{
		if (current == 0)
			throw Error("Invalid Position");
		pos++;
		current = current->next;
		return (*this); 
	}

	const iterator operator++ (int)
	{
		if (current == 0)
			throw Error("Invalid Position");
		const iterator temp(current, pos);
		pos++;
		current = current->next;
		return temp;
	}

	const iterator& operator-- ()
	{
		if (current == 0)
			throw Error("Invalid Position");
		pos--;
		current = current->prev;
		return (*this);
	}

	const iterator operator-- (int)
	{
		if (current == 0)
			throw Error("Invalid Position");
		const iterator temp(current, pos);
		pos--;
		current = current->prev;
		return temp;
	}

	T& operator* ()
	{
		if (current == 0)
			throw Error("Invalid Position");
		return current->info;
	}

	T* operator-> ()
	{
		return &(operator*());
	}
};

template <class T> doubly_list<T>::doubly_list(const doubly_list& other)
{
	Node temp, cur, pre;
	head = new Node;
	tail = new Node;
	count = other.count;
	head->info = other.head->info;
	head->prev = 0;
	tail->info = other.tail->info;
	tail->next = 0;
	for (doubly_list::iterator it = other.begin(), cur = head, pre = 0; it != other.end(); it++)
	{
		temp = new Node;
		temp->info = (*it);
		cur->next = temp;
		cur->prev = pre;
		pre = cur;
		cur = cur->next;
	}
}

template <class T> const doubly_list<T>& doubly_list<T>::operator=(const doubly_list& other)
{
	if (this != &other)
	{
		clear();
		Node temp, cur, pre;
		head = new Node;
		tail = new Node;
		head->info = other.head->info;
		head->prev = 0;
		tail->info = other.tail->info;
		tail->next = 0;
		for (doubly_list::iterator it = other.begin(), cur = head, pre = 0; it != other.end(); it++)
		{
			temp = new Node;
			temp->info = (*it);
			cur->next = temp;
			cur->prev = pre;
			pre = cur;
			cur = cur->next;
		}
	}
	return (*this);
}

template <class T> void doubly_list<T>::insert(const T &item, long long pos)
{
	if (pos == -1)
		return insert_rear(item);
	if (pos < 0)
		pos += count;
	size_t i;
	if (pos > count || pos < 0)
		throw Error("Invalid Position");
	Node* cur = head;
	for (i = 0; i < pos && cur != tail; i++, cur = cur->next);
	Node* temp = new Node(item, cur->next, cur);
	if (temp == 0)
		throw Error("Memory can not be allocated");
	cur->next->prev = temp;
	cur->next = temp;
	count++;
}

template <class T> void doubly_list<T>::insert_front(const T &item)
{
	Node* old = head->next;
	Node* temp = new Node(item, old, head);
	if (temp == 0)
		throw Error("Memory can not be allocated");
	old->prev = temp;
	head->next = temp;
	count++;
}

template <class T> void doubly_list<T>::insert_rear(const T &item)
{
	Node* old = tail->prev;
	Node* temp = new Node(item, tail, old);
	if (temp == 0)
		throw Error("Memory can not be allocated");
	old->next = temp;
	tail->prev = temp;
	count++;
}

template <class T> T doubly_list<T>::pop(long long pos)
{
	if (isEmpty())
		throw Error("Empty List");
	Node* cur = head->next;
	T del;
	size_t i;
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
		throw Error("Empty List");
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
		throw Error("Empty List");
	Node* temp = tail->prev;
	T del = temp->info;
	temp->prev->next = tail;
	tail->prev = temp->prev;
	delete temp;
	count--;
	return del;
}

template <class T> T& doubly_list<T>::operator[] (long long pos)
{
	if (isEmpty())
		throw Error("Empty List");
	if (pos < 0)
		pos += count;
	if (pos < 0 || pos >= count)
		throw Error("Invalid Position");
	Node* cur1 = head->next;
	Node* cur2 = tail->prev;
	long long i = 0, j = count - 1;
	for (; i < pos && j > pos; i++, j--)
	{
		cur1 = cur1->next;
		cur2 = cur2->prev;
	}
	if (i < pos)
		return cur2->info;
	return cur1->info;
}

template <class T> long long doubly_list<T>::get_pos(const T &item)
{
	if (isEmpty())
		throw Error("Empty List");
	Node* cur1 = head->next;
	Node* cur2 = tail->prev;
	long long i, j;
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
