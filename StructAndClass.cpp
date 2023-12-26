#include <iostream>
#include <stdexcept>

using namespace std;

class BaseClass
{
public:
	BaseClass() : a(0), b(0) {}
	int a;
	int b;
};

struct DerivedStruct : public BaseClass
{
};

struct BaseStruct
{
	int a;
	int b;
};

class DerivedClass : public BaseStruct
{
};

int main()
{
	// a struct can inherit from a class
	DerivedStruct ds;
	ds.a = 1;
	ds.b = 2;
	cout << ds.a << " " << ds.b << endl;

	// a class can inherit from a struct
	DerivedClass dc;
	dc.a = 3;
	dc.b = 4;
	cout << dc.a << " " << dc.b << endl;

	// however you should not do this, it's bad practice
	// a struct should be used for POD (plain old data)
	// a class should be used for OOP (object oriented programming)
	// structs were kept in C++ to support C compatibility
	// you should not inherit from a struct
	return 0;
}