#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "exceptions.hpp"
#include "vector.hpp"
#include "list.hpp"
#include "doubly_list.hpp"
using namespace std;
template<class T, class Container = vector<T> >
class queue
{
	Container v;
public:
	
	//Check for Empty Queue - Returns true if empty, else false
	bool isEmpty()
	{
		return v.isEmpty();
	}

	//Returns size of the queue
	size_t size()
	{
		return v.size();
	}

	//Insert element at rear
	void enqueue(T item)
	{
		v.insert_rear(item);
	}

	//Delete element from front
	T dequeue()
	{
		return v.pop_front();
	}

	//Returns reference of the first element of queue
	T& front()
	{
		return v[0];
	}
};
#endif
