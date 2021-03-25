

#include <iostream>
#include<string>
using namespace std;
class Base {
public:
	Base() {

	}
	Base(Base* obj) { 
	}

	Base(Base& obj) { 
	}

	void foo() {
		printf("!\n");
	}
	virtual string classname() {

	}
	virtual bool isA(std::string classname) {

	}
	~Base() { 
	}
};

class Desc : public Base  {
public:
	Desc(Desc* obj) {
	}

	Desc(Desc& obj) {
	}
	void foo() {
		printf("mew\n");

	}
	~Desc() { 
	}
};

class Desc2 : public Base {
public:
	void foo() {
		printf("wow\n");

	}
};
void func1(Base  obj) { 
};

void func2(Base* obj) { 
};

void func3(Base& obj) {
};

int main()
{
	Base* a[10];
	for (int i = 0;i < 10;i++) {
		if (rand() % 2 == 0)
			a[i] = new Desc;
		else
			a[i] = new Desc2;
	}
	for (int i = 0;i < 10;i++)
		a[i]->foo();
	

}
