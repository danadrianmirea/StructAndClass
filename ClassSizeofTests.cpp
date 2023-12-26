#include <iostream>
#include <stdexcept>

using namespace std;

class Empty
{};

class EmptyWithVirtual
{
	virtual void f() {};
};

class EmptyWithMultipleVirtuals
{
	virtual void f() {};
	virtual void g() {};
};

class EmptyWithVirtualButAbstract
{
	virtual void f() = 0;
};

class Children : public Empty
{
};

class Children2 : public Empty
{
	virtual void f() {};
};

class BaseWithFunction {
	void f() {};
};

class BaseWithThreeFunctions {
	void f() {};
	void g() {};
	void h() {};
};

class BaseWithData {
	int i;
	float f;
};

class BaseWithDataAndVirtual {
public:
	BaseWithDataAndVirtual() : i(0), d(0.0) {};
	int i;
	double d;

	virtual void Calculate() = 0;
	virtual void PrintInfo() = 0;

	void TheseFunctionsDontIncreaseSize() {}
};

class InheritedFromBaseWithDataAndVirtual : public BaseWithDataAndVirtual {

	virtual void Calculate() { cout << i * d << endl; };
	virtual void PrintInfo() { cout << "i = " << i << ", d = " << d << endl; };

	void NeitherWillThis() {}

	virtual void SomeMoreFunctions() {} // and at this point neither will virtual functions
};

int main()
{
	int i = 0;
	float f = 0.0;
	BaseWithData bwd;
	cout << sizeof(int) << endl;
	cout << sizeof(i) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(f) << endl;
	cout << sizeof(bwd) << endl;
	cout << sizeof(BaseWithData) << endl;
	cout << sizeof(Empty) << endl;
	cout << sizeof(BaseWithFunction) << endl;
	cout << sizeof(BaseWithThreeFunctions) << endl;
	cout << sizeof(Children) << endl;
	cout << sizeof(Children2) << endl;
	cout << sizeof(EmptyWithVirtual) << endl;
	cout << sizeof(EmptyWithMultipleVirtuals) << endl;
	cout << sizeof(EmptyWithVirtualButAbstract) << endl;

	cout << sizeof(BaseWithDataAndVirtual) << endl;
	InheritedFromBaseWithDataAndVirtual ib;
	cout << sizeof(ib) << endl;

	return 0;
}