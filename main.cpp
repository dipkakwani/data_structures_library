#include"stack.h"
#include"queue.h"
#include"cqueue.h"
#include"linked_list.h"
#include<cstdlib>
#include<string>
using namespace std;
void stack_test();
void queue_test();
void cqueue_test();
void linked_list_test();
int main()
{
	stack_test();
	queue_test();
	cqueue_test();
	linked_list_test();
	return 0;
}
void stack_test()
{
	stack<int, 10> S;
	string e1 = "Stack Underflow";
	string e2 = "Stack Overflow";
	string e3 = "Empty Stack";
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
		S.get_top();
		fail++;
	} catch(Error& x){
		if (!e3.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		S.push(10);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if(S.get_top() == 10)
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
		S.push(110);
		fail++;
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		if (S.get_top() == 100)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
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
	queue<int, 10> Q;
	string e1 = "Queue Underflow";
	string e2 = "Queue Overflow";
	string e3 = "Empty Queue";
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
		Q.get_front();
		fail++;
	} catch(Error& x){
		if (!e3.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		Q.enqueue(10);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if(Q.get_front() == 10)
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
		Q.enqueue(110);
		fail++;
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		if (Q.get_front() == 10)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	for(int i = 0; i < 10; i++)
	{
		try{
			Q.dequeue();
			pass++;
		} catch(Error& x){
			fail++;
		}
	}
	cout << "Queue Test cases\n";
	cout << "PASS: " << pass << "\tFAIL: " << fail << endl;
}
void cqueue_test()
{
	cqueue<int, 10> Q;
	string e1 = "Queue Underflow";
	string e2 = "Queue Overflow";
	string e3 = "Empty Queue";
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
		Q.get_front();
		fail++;
	} catch(Error& x){
		if (!e3.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		Q.enqueue(10);
		pass++;
	} catch(Error& x){
		fail++;
	}
	try{
		if(Q.get_front() == 10)
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
		Q.enqueue(110);
		fail++;
	} catch(Error& x){
		if (!e2.compare(x.what()))
			pass++;
		else
			fail++;
	}
	try{
		if (Q.get_front() == 10)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
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
		if (Q.get_front() == 20)
			pass++;
		else
			fail++;
	} catch(Error& x){
		fail++;
	}
	cout << "Circular Queue Test cases\n";
	cout << "PASS: " << pass << "\tFAIL: " << fail << endl;
}
void linked_list_test()
{
	linked_list<int> L;
	string e1 = "List Underflow";
	string e2 = "Empty List";
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
	cout << "Linked List Test Cases\n";
	cout << "Pass: " << pass << "\tFail: " << fail << endl;
}
