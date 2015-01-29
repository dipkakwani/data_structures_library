#ifndef BST_H
#define BST_H
#include <cmath>
#include "exceptions.hpp"
#include "vector.hpp"
#include "list.hpp"
#include "doubly_list.hpp"
using namespace std;
template <class T>
class bst
{
	class Node
	{
	public:	
		T info;
		Node* left, *right;
		Node(T in = T(), Node* l = 0, Node* r = 0) : info(in), left(l), right(r)
		{}
	} *root;

	/*
		Helper functions for balance()
	*/

	//Right rotation of child ch about parent par
	void rotate_right(Node* gr, Node* par, Node* ch);	
	
	//Left rotation of child ch about parent
	void rotate_left(Node* gr, Node* par, Node* ch);

	//Transform tree into linked list structure
	void create_backbone();

public:

	bst() : root(0)
	{}
	
	//Copy constructor
	bst(const bst& other)
	{
		root = copy_nodes(other->root);
	}

	bst& operator= (const bst& other)
	{
		root = copy_nodes(other->root);
	}

	//Helper function for copy constructor and assignment operator
	Node* copy_nodes(Node* p);

	//Preorder Traversal
	template <class Collection>
	void preorder(Collection& v);

	//Preorder Traversal starting from node p
	template <class Collection>
	void preorder(Collection& v, Node* p);

	//Inorder Traversal
	template <class Collection >
	void inorder(Collection& v);
	
	//Inorder Traversal starting from node p
	template <class Collection >
	void inorder(Collection& v, Node* p);

	//Postorder Traversal
	template <class Collection>
	void postorder(Collection& v);

	//Postorder Traversal starting from node p
	template <class Collection>
	void postorder(Collection& v, Node* p);

	//Insert an element in the BST
	void insert(const T&);

	//Remove an element from BST
	T pop(const T&);

	//Balance the BST - organise nodes such that all the leaves are on same or adjacent levels
	void balance();
};

template <class T> typename bst<T>:: Node* bst<T>::copy_nodes(Node* p)
{
	if (p != 0)
		return Node(p->info, copy_nodes(p->left), copy_nodes(p->right));
	return 0;
}

template <class T> template <class Collection> void bst<T>::preorder(Collection& v)
{
	preorder(v, root);
}

template <class T> template <class Collection> void bst<T>::preorder(Collection& v, Node* p)
{
	if (p != 0)
	{
		v.insert_rear(p->info);
		preorder(v, p->left);
		preorder(v, p->right);
	}
}

template <class T> template <class Collection > void bst<T>::inorder(Collection& v)
{
	inorder(v, root);
}

template <class T> template <class Collection > void bst<T>::inorder(Collection& v, Node* p)
{
	if (p != 0)
	{
		inorder(v, p->left);
		v.insert_rear(p->info);
		inorder(v, p->right);
	}
}

template <class T> template <class Collection> void bst<T>::postorder(Collection& v)
{
	postorder(v, root);
}

template <class T> template <class Collection> void bst<T>::postorder(Collection& v, Node* p)
{
	if (p != 0)
	{
		postorder(v, p->left);
		postorder(v, p->right);
		v.insert_rear(p->info);
	}
}

template <class T> void bst<T>::insert(const T& item)
{
	Node *cur, *prev, *temp;
	for (cur = root, prev = 0; cur != 0;)
	{
		prev = cur;
		if (cur->info > item)
			cur = cur->left;
		else if(cur->info < item)
			cur = cur->right;
		else
			throw Error("Element already exists");
	}
	temp = new Node(item);
	if (prev == 0)
		root = temp;
	else
	{
		if (prev->info > item)
			prev->left = temp;
		else
			prev->right = temp;
	}
}

template <class T> T bst<T>::pop(const T& item)
{
	Node *cur, *prev, *temp;
	T del;
	for (cur = root, prev = 0; cur != 0 && cur->info != item;)
	{
		prev = cur;
		if (item > cur->info)
			cur = cur->right;
		else
			cur = cur->left;
	}
	if (cur == 0)
		throw Error("Element not found");
	del = cur->info;
	if (cur->right == 0 || cur->left == 0)		//Either Leaf Node or a Node with only one child
	{
		if (cur->right == 0)
			temp = cur->left;
		else
			temp = cur->right;
		if (prev == 0)		//Root Node
			root = temp;
		else
		{
			if (prev->right == cur)
				prev->right = temp;
			else
				prev->left = temp;
		}
		delete cur;
	}	 
	else				// A node with two children
	{
		temp = cur->right;
		while (temp->left != 0)
			temp = temp->left;
		temp->left = cur->left;
		temp = cur;
		if (prev == 0)		//Root Node
			root = cur->right;
		else
		{
			if (prev->right == cur)
				prev->right = cur->right;
			else
				prev->left = cur->right;
		}
		delete temp;
	}
	return del;
}

template <class T> void bst<T>::rotate_right(Node* gr, Node* par, Node* ch)
{
	if (par != root)
		gr->right = ch;
	else
		root = ch;
	par->left = ch->right;
	ch->right = par;
}

template <class T> void bst<T>::rotate_left(Node* gr, Node* par, Node* ch)
{
	if (par != root)
		gr->right = ch;
	else
		root = ch;
	par->right = ch->left;
	ch->left = par;
}

template <class T> void bst<T>::create_backbone()
{
	Node* prev, *cur, *temp;
	for (cur = root, prev = 0; cur != 0;)
	{
		temp = prev;
		prev = cur;
		if (cur->left != 0)
		{
			rotate_right(temp, cur, cur->left);
			if (temp != 0)
				cur = temp->right;
			else
				cur = root;
		}
		else
			cur = cur->right;
	}
}

template <class T> void bst<T>::balance()
{
	create_backbone();
	size_t count = 0;
	Node* cur;
	for (cur = root; cur != 0; count++, cur = cur->right);
	size_t m = (1 << (int)(log(count + 1) / log(2))) - 1;	//2 ^ pow(log(count + 1)) - 1
	for (size_t i = 0; i < count - m; i++)
		rotate_left(0, root, root->right);
	while (m > 1)
	{
		m = m >> 1;
		for (size_t i = 0; i < m; i++)
			rotate_left(0, root, root->right);
	}
}
#endif
