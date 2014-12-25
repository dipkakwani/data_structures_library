#include "../src/stack.hpp"
#include "../src/queue.hpp"
#include "../src/list.hpp"
#include "../src/doubly_list.hpp"
#include "../src/vector.hpp"
#include <cstdlib>
#include <string>
using namespace std;
void vector_test();
void stack_test();
void queue_test();
void list_test();
void doubly_list_test();
int main()
{
	vector_test();
	stack_test();
	queue_test();
	list_test();
	doubly_list_test();
	return 0;
}
void vector_test()
{
	vector<int> L;
	string e1 = "Empty Vector";
	string e2 = "Empty Vector";
	string e3 = "Invalid Position";
	int pass = 0, fail = 0;
	try{
		L.pop();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.pop_front();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}	
	try{
		L.pop_rear();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L[0];
		fail++;
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.get_pos(5);
		fail++;
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.insert(5, -1);
		pass++;
	} catch (Error& x){
		fail++;
	}
	try{
		L.insert(2, 0);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.pop(-1);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.pop();
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.insert_front(10);
		if (L[0] == 10)
			pass++;
		else
			fail++;
	} catch(Error &x){
		fail++;
	}
	try{
		L.insert_rear(30);
		if (L[1] == 30)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.insert(20, 1);
		if (L[1] == 20)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.insert(40, 4);
		cout << "insert fail";
		fail++;
	} catch(Error& x){
		if (!e3.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.pop(4);
		fail++;
		cout << "Pop fail";
	} catch(Error& x){
		if (!e3.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.insert(40, -1);
		if (L[-1] == 40)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[0] == L.pop_front())
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[L.size() - 1] == L.pop_rear())
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[1] == L.pop(1))
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		int i;
		for(i = 3; i < 12; i++)
			L.insert_rear(i * 10);
		for(i = 0; i < 10; i++)
			if (L[i] != (i + 2) * 10)
				fail++;
		for(i = 0; i < 10; i++)
			if (L[-(i + 1)] != L[9 - i])
				fail++;
		if (L.size() == 10)
			pass++;
		else
			fail++;
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[L.get_pos(50)] == 50)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[L.get_pos(200)] == 200)
			fail++;
		fail++;
	} catch(Error& x){
		if (!e3.compare(x.what()))
			pass++;
		else
			fail++;
	}	
	cout << "Vector Test Cases\n";
	cout << "Pass: " << pass << "\tFail: " << fail << endl;
}
void stack_test()
{
	stack<int> S;
	string e1 = "Empty Vector";
	int pass = 0, fail = 0;
	try{
		S.pop();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		S.top();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	if (S.size() == 0)
		pass++;
	else
		fail++;

	try{
		S.push(20);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if(S.top() == 20)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		S.top() = 10;
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if(S.top() == 10)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	for (int i = 2; i < 11; i++)
	{
	try{
		S.push(i * 10);
		pass++;
	} catch(Error& x){
			fail++;
		}
	}
	try{
		if (S.top() == 100)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	if (S.size() == 10)
		pass++;
	else
		fail++;
	for(int i = 0; i < 10; i++)
	{
		try{
			S.pop();
			pass++;
		} catch(Error& x){
			fail++;
		}
	}
	cout << "Stack Test cases\n";
	cout << "PASS: " << pass << "\tFAIL: " << fail << endl;
}
void queue_test()
{
	queue< int, list<int> > Q;
	string e1 = "Empty List";
	int pass = 0, fail = 0;
	try{
		Q.dequeue();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		Q.front();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	if (Q.size() == 0)
		pass++;
	else
		fail++;

	try{
		Q.enqueue(20);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if(Q.front() == 20)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		Q.front() = 10;
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if(Q.front() == 10)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	for (int i = 2; i < 11; i++)
	{
		try{
			Q.enqueue(i * 10);
			pass++;
		} catch(Error& x){
			fail++;
		}
	}
	try{
		if (Q.front() == 10)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	if (Q.size() == 10)
		pass++;
	else
		fail++;

	for(int i = 0; i < 10; i++)
	{
		try{
			Q.dequeue();
			pass++;
		} catch(Error& x){
			fail++;
		}
	}
	for(int i = 1; i < 11; i++)
	{
		try{
			Q.enqueue(i * 10);
			pass++;
		} catch(Error& x){
			fail++;
		}
	}
	try{
		Q.dequeue();
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		Q.enqueue(10);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (Q.front() == 20)
			pass++;

		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	cout << "Queue Test cases\n";
	cout << "PASS: " << pass << "\tFAIL: " << fail << endl;
}
void list_test()
{
	list<int> L;
	string e1 = "Empty List";
	string e2 = "Invalid Position";
	int pass = 0, fail = 0;
	try{
		L.pop();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.pop_front();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}	
	try{
		L.pop_rear();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L[0];
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.get_pos(5);
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.insert(5, -1);
		pass++;
	} catch (Error& x){
		fail++;
	}
	try{
		L.insert(2, 0);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.pop(-1);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.pop();
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.insert_front(10);
		if (L[0] == 10)
			pass++;
		else
			fail++;
	} catch(Error &x){
		fail++;
	}
	try{
		L.insert_rear(30);
		if (L[1] == 30)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.insert(20, 1);
		if (L[1] == 20)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.insert(40, 4);
		fail++;
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.pop(4);
		fail++;
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.insert(40, -1);
		if (L[-1] == 40)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[0] == L.pop_front())
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[L.size() - 1] == L.pop_rear())
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[1] == L.pop(1))
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		int i;
		for(i = 3; i < 12; i++)
			L.insert_rear(i * 10);
		for(i = 0; i < 10; i++)
			if (L[i] != (i + 2) * 10)
				fail++;
		for(i = 0; i < 10; i++)
			if (L[-(i + 1)] != L[9 - i])
				fail++;
		if (L.size() == 10)
			pass++;
		else
			fail++;
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[L.get_pos(50)] == 50)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[L.get_pos(200)] == 200)
			fail++;
		fail++;
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}	
	cout << "Linked List Test Cases\n";
	cout << "Pass: " << pass << "\tFail: " << fail << endl;
}
void doubly_list_test()
{
	doubly_list<int> L;
	string e1 = "Empty List";
	string e2 = "Invalid Position";
	int pass = 0, fail = 0;
	try{
		L.pop();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.pop_front();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}	
	try{
		L.pop_rear();
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L[0];
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.get_pos(5);
		fail++;
	} catch(Error& x){
		if (!e1.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.insert(5, -1);
		pass++;
	} catch (Error& x){
		fail++;
	}
	try{
		L.insert(2, 0);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.pop(-1);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.pop();
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.insert_front(10);
		if (L[0] == 10)
			pass++;
		else
			fail++;
	} catch(Error &x){
		fail++;
	}
	try{
		L.insert_rear(30);
		if (L[1] == 30)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.insert(20, 1);
		if (L[1] == 20)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		L.insert(40, 4);
		cout << "insert fail";
		fail++;
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.pop(4);
		fail++;
		cout << "Pop fail";
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		L.insert(40, -1);
		if (L[-1] == 40)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[0] == L.pop_front())
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[L.size() - 1] == L.pop_rear())
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[1] == L.pop(1))
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		int i;
		for(i = 3; i < 12; i++)
			L.insert_rear(i * 10);
		for(i = 0; i < 10; i++)
			if (L[i] != (i + 2) * 10)
				fail++;
		for(i = 0; i < 10; i++)
			if (L[-(i + 1)] != L[9 - i])
				fail++;
		if (L.size() == 10)
			pass++;
		else
			fail++;
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[L.get_pos(50)] == 50)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	try{
		if (L[L.get_pos(200)] == 200)
			fail++;
		fail++;
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}	
	cout << "Doubly Linked List Test Cases\n";
	cout << "Pass: " << pass << "\tFail: " << fail << endl;
}
