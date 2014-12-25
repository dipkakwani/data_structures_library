#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "exceptions.hpp"
#include "vector.hpp"
#include "list.hpp"
#include "doubly_list.hpp"
using namespace std;
template<class T, class Container = vector<T> >
class stack
{
	Container v;
public:	

	//Check for Empty Stack - Returns true if empty, else false
	bool isEmpty()
	{
		return v.isEmpty();
	}

	//Returns size of the stack
	size_t size()
	{
		return v.size();
	}

	//Insert element at top
	void push(T item)
	{
		v.insert_front(item);
	}

	//Delete element from top
	T pop()
	{
		return v.pop_front();
	}

	//Returns reference of the first element of stack
	T& top()
	{
		return v[0];
	}
};
#endif
