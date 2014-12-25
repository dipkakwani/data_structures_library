#ifndef EXCEP_H
#define EXCEP_H
#include<stdexcept>
#include<iostream>
using namespace std;
class Error : public logic_error{
	public:
		Error(const string& msg = "") : logic_error(msg){}
};
#endif
