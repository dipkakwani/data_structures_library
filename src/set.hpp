#ifndef SET_H
#define SET_H
#include <iostream>
#include <vector>
#include <list>
#include <doubly_list>
#include <functional>
using namespace std;
/*
   Unordered set implemented using hash table.
   Each hash table slot contains doubly linked list (collision resolution by chaining) 
*/
template <class T>
class set
{
	size_t count;

	/*
	   Grow the hash table. Rehash all the elements already in the set.
	*/
	void grow()
	{}
public:

	/*
	   Iterate through the elements of the set
	*/
	class iterator;
	
	iterator begin() const
	{}

	iterator end() const
	{}

	/*
	   Default constructor
	*/
	set() : count(0)
	{}
	
	/*
	   Copy constructor
	*/
	set(const set<T>& other);

	/*
	  Assignment operator 
	*/
	set& operator= (const set<T>& other);

	/*
	   Create a set from a sequential container, removing duplicates.
	*/
	template <class Container>
	set(Container& v);

	/*
	   Is the set empty?
	*/
	bool empty() const
	{
		return (count == 0);
	}

	/*
	   Search a key in the set. Worst case O(N), average case O(1)
	*/
	bool find(T& key) const;

	/*
	   Insert a key in the set, avoiding duplicates.
	   Worst case O(N), average case O(1).
	*/
	void insert(T& key);

	/*
	   Delete a key from the set. Exception thrown if key not found.
	   Worst case O(N), average case O(1).
	*/
	T pop(T& key);

	/*
	   Delete all elements from the set
	*/
	void clear();

	/*
	   Returns union of two sets.
	*/
	set& join(set<T>& other);

	/*
	   Returns intersection of two sets.
	*/
	set& intersection(set<T>& other);

	/*
	   Destructor
	*/
	~set()
	{}
};
#endif
