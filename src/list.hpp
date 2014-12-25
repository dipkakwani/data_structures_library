#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "exceptions.hpp"
using namespace std;
template <class T>
class list
{
	class Node
	{
	public:

		T info;
		Node* next;

		Node(T in, Node* ptr = 0) : info(in), next(ptr)
		{}
	}* front, * rear;
	size_t count;
public:

	class iterator
	{
		friend class list;
		Node* current;
		size_t pos;
	public:

		iterator(Node* ptr = 0, size_t p = 0) : current(ptr), pos(p)
		{}

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

	iterator begin() const
	{
		return iterator(this->front, 0);
	}

	iterator end() const
	{
		return iterator(this->rear->next, count);
	}

	//Returns true if list is empty, else false
	bool isEmpty() const
	{
		return (front == 0);
	}

	//Default constructor
	list() : front(0), rear(0), count(0)
	{}

	//Copy contructor
	list(const list& other);

	//Assignment operator
	const list& operator= (const list& other);

	//Returns size of list
	size_t size() const
	{
		return count;
	}

	//Inserts element at a given position
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

	//Returns position of given element
	long long get_pos(const T&);
	
	//
	void clear()
	{
		Node* temp;
		while (!isEmpty())
		{
			temp = front->next;
			delete front;
			front = temp;				
		}

	}
	//Destructor
	~list()
	{
		clear();
	}
};

template <class T> list<T>::list(const list& other)
{
	count = other.count;
	Node temp, cur;
	front = new Node;
	rear = new Node;
	front->info = other.front->info;
	rear->info = other.rear->info;
	rear->next = 0;
	for (list::iterator it = other.begin(), cur = front; it != other.end(); it++)
	{
		temp = new Node;
		temp->info = (*it);
		cur->next = temp;
		cur = cur->next;
	}
}

template <class T> const list<T>& list<T>::operator=(const list& other)
{
	if (this != &other)
	{
		clear();
		count = other.count;
		Node temp, cur;
		front = new Node;
		rear = new Node;
		front->info = other.front->info;
		rear->info = other.rear->info;
		rear->next = 0;
		for (list::iterator it = other.begin(), cur = front; it != other.end(); it++)
		{
			temp = new Node;
			temp->info = (*it);
			cur->next = temp;
			cur = cur->next;
		}
	}
	return (*this);
}

template <class T> void list<T>::insert(const T& item, long long pos)
{
	if (pos < 0)
		pos += count + 1;
	if (pos > count || pos < 0)		//Handling invalid values of position
		throw Error("Invalid Position");
	Node* cur = front;
	Node* pre = 0;
	size_t i;
	for (i = 0; cur != 0 && i < pos; pre = cur, cur = cur->next, i++);
	if (pre != 0)
	{
		pre->next = new Node(item, cur);
		if (pre->next == 0)
			throw Error("Memory can not be allocated");
		if (pre == rear)				//Inserted after last element
			rear = pre->next;
	}
	else				//Empty List
	{
		front = new Node(item, cur);
		if (front == 0)
			throw Error("Memory can not be allocated");
		if (rear == 0)
			rear = front;
	}
	count++;
}

template <class T> void list<T>::insert_front(const T& item)
{
	front = new Node(item, front);
	if (front == 0)
		throw Error("Memory can not be allocated");
	if (rear == 0)							//Empty list
		rear = front;
	count++;
}

template <class T> void list<T>::insert_rear(const T& item)
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

template <class T> T list<T>::pop(long long pos)
{
	if (isEmpty())
		throw Error("Empty List");
	T del;
	Node* cur = front;
	Node* pre = 0;
	size_t i;
	if (pos < 0)
		pos += count;
	if (pos >= count || pos < 0)
		throw Error("Invalid Position");
	for (i = 0; cur != 0 && i < pos; pre = cur, cur = cur->next, i++);
	del = cur->info;
	if (pre != 0)
		pre->next = cur->next;
	if (cur == rear)
		rear = pre;
	if (cur == front)
		front = 0;
	delete cur;
	count--;
	return del;
}

template <class T> T list<T>::pop_front()
{
	if (isEmpty())
		throw Error("Empty List");
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

template <class T> T list<T>::pop_rear()
{
	if (isEmpty())
		throw Error("Empty List");
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

template <class T> T& list<T>::operator[] (long long pos)
{
	if (isEmpty())
		throw Error("Empty List");
	if (pos < 0)
		pos += count;
	if (pos >= count || pos < 0)
		throw Error("Invalid Position");
	Node* cur = front;
	for (size_t i = 0; i < pos && cur != 0; i++)
		cur = cur->next;
	return cur->info;
}

template <class T> long long list<T>::get_pos(const T& item)
{
	if (isEmpty())
		throw Error("Empty List");
	Node* cur = front;
	size_t i;
	for(i = 0; cur->info != item && cur->next != 0; i++)
		cur = cur->next;
	if (cur->info == item)
		return i;
	return -(count + 1);
}
#endif
