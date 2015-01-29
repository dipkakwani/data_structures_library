#ifndef VEC_H
#define VEC_H
#include <iostream>
#include "exceptions.hpp"
using namespace std;
template <class T>
class vector
{
	static const size_t initial_size = 32;
	T* v;
	size_t used;
	size_t max;

	void grow()
	{
		max *= 2;
		T* temp = v;
		v = new T[max];
		for (size_t i = 0; i < used; i++)
			v[i] = temp[i];
		delete[] temp;
	}
public:

	//To iterate through all the elements in the vector
	class iterator;
	
	//Returns true if vector is empty, else false
	bool isEmpty()
	{
		return (used == 0);
	}


	vector() : used(0), max(initial_size)
	{
		v = new T[max];
	}
	
	//Copy constructor
	vector(const vector& other) : used(other.used), max(other.max)
	{
		v = new T[max];
		for (size_t i = 0; i < used; i++)
			v[i] = other.v[i];
	}

	//Returns the size of the vector
	size_t size() const
	{
		return used;
	}

	const vector& operator= (const vector& other)
	{
		if (this != &other)
		{
			delete[] v;
			used = other.used;
			max = other.max;
			v = new T[max];
			for (size_t i = 0; i < used; i++)
				v[i] = other.v[i];
		}
		return (*this);
	}

	iterator begin() const
	{
		return iterator(this, 0);
	}

	iterator end() const
	{
		return iterator(this, used);
	}

	//Inserts element at a given position, negative position to start from end
	void insert(const T& item, long long pos = 0);

	//Insert element at rear
	void insert_rear(const T& item)
	{
		if (used == max)
			grow();
		v[used++] = item;
	}

	//Insert element at front
	void insert_front(const T& item)
	{
		if (used == max)
			grow();
		for (size_t i = used; i > 0; i--)
			v[i] = v[i - 1];
		v[0] = item;
		used++;
	}

	//Deletes element from given position, negative position to start from end
	T pop(long long pos = 0);

	//Deletes element from rear
	T pop_rear()
	{
		if (used == 0)
			throw Error("Empty Vector");
		used--;
		return v[used + 1];
	}

	//Deletes element from front
	T pop_front()
	{
		if (used == 0)
			throw Error("Empty Vector");
		T del = v[0];
		for (size_t i = 0; i < used - 1; i++)
			v[i] = v[i + 1];
		used--;
		return del;
	}

	//Returns reference of element at given position, negative position to start from end
	T& operator[] (long long pos);
	
	//Returns position of given element
	long long get_pos(const T& item);

	//Delete all elements from the vector
	void clear()
	{
		delete[] v;
		v = 0;
		used = 0;
		max = initial_size;
		v = new T[max];
	}

	~vector()
	{
		delete[] v;
		v = 0;
	}
};

template <class T> class vector<T>::iterator
{
	friend class vector;
	const vector* obj;
	size_t pos;
	
public:

	iterator(const vector* ptr = 0, size_t p = 0) : obj(ptr), pos(p)
	{}

	iterator (const iterator& other) : obj(other.obj), pos(other.pos)
	{}

	iterator operator= (const iterator& other)
	{
		obj = other.obj;
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
		pos++;
		return (*this);
	}

	const iterator operator++ (int)
	{
		const iterator temp = (*this);
		pos++;
		return temp;
	}

	const iterator& operator-- ()
	{
		pos--;
		return (*this);
	}

	const iterator operator-- (int)
	{
		const iterator temp = (*this);
		pos--;
		return temp;
	}

	T& operator* ()
	{
		return obj->v[pos];
	}

	T* operator-> ()
	{
		return &(operator*());
	}
};

template <class T> void vector<T>::insert(const T& item, long long pos)
{
	if (pos < 0)
		pos += used + 1;
	if (used == max)
		grow();
	if (pos < 0 || pos > used)
		throw Error("Invalid Position");
	size_t i;
	for (i = used; i > pos; i--)
		v[i] = v[i - 1];
	v[i] = item;
	used++;
}

template <class T> T vector<T>::pop(long long pos)
{
	if (used == 0)
		throw Error("Empty Vector");
	if (pos < 0)
		pos += used;
	if (pos < 0 || pos >= used)
		throw Error("Invalid Position");
	T del = v[pos];
	for (size_t i = pos; i < used - 1; i++)
		v[i] = v[i + 1];
	used--;
	return del;
}

template <class T> T& vector<T>::operator[] (long long pos)
{
	if (used == 0)
		throw Error("Empty Vector");
	if (pos < 0)
		pos += used;
	if (pos < 0 || pos >= used)
		throw Error("Invalid Position");
	return v[pos];
}

template <class T> long long vector<T>::get_pos(const T& item)
{
	if (used == 0)
		throw Error("Empty Vector");
	for (size_t i = 0; i < used; i++)
		if (v[i] == item)
			return i;
	return -(used + 1);
}
#endif
