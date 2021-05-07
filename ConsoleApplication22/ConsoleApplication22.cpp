

#include <iostream>
#include<string>
using namespace std;
class Base {
//protected:
	//std::string = base;
public:
	Base() {
		printf("Base()\n");
	}
	Base(Base* obj) { 
		printf("Base(Base* obj)\n");
	}

	Base(Base& obj) {
		printf("Base(Base& obj)\n");
	}

	virtual string classname() {//базовый виртуальный метод string classname(), перекрыть его в потомках, проверить работу и показать, какие проблемы возникают при его использовании;
		printf("classname_Base\n");
		return "Base";
	}
	virtual bool isA(std::string classname) {//базовый виртуальный метод bool isA(string classname), перекрыть его в потомках и показать отличие от метода classname.
		printf("bool isA");
		if (this->classname() == classname)
			return 1;
		else return 0;		
	}//Продемонстрировать опасное приведение типов и предварительную проверку типа с помощью реализованного метода isA.
	~Base() { 
		printf("\n");
	}
};

class Desc : public Base  {
public:
	Desc() {
		printf("Desc()\n");
	}
	Desc(Desc* obj) {
		printf("Desc(Desc* obj)\n");
	}

	Desc(Desc& obj) {
		printf("Desc(Desc& obj)\n");
	}
	string classname() {
		printf("classname_Desc\n");
		return "Desc";		
	}
	bool isA(std::string classname) {//базовый виртуальный метод bool isA(string classname), перекрыть его в потомках и показать отличие от метода classname.
		printf("bool isA\n");
		if (this->classname() == classname || Base::isA(classname))
			return 1;
		else return 0;
	}
	~Desc() { 
		printf("~Desc()\n");
	}
};

/*class Desc2 : public Base {
public:
	void foo() {
		printf("wow\n");

	}
};*/
void func1(Base  obj) { 
	printf("func1\n");
};

void func2(Base* obj) { 
	printf("func2\n");
};

void func3(Base& obj) {
	printf("func3\n");
};

int main()
{
	Base* obj1 = new Desc;
	Desc* obj2 = new Desc;
	Base* obj3 = new Base;

	func1(obj1);
	func1(obj2);
	func1(obj3);
	func2(obj1);
	func2(obj2);
	func2(obj3);
	func3(*obj1);
	func3(*obj2);
	func3(*obj3);



	//if (base2->classname() == "Desc")
		//((Desc*)base2)->classname();

	if (obj1->isA("Desc"))
		printf("\n ");

	Desc* d = dynamic_cast<Desc*>(obj1);
	if (d != NULL)
		d->classname();
	//После этого необходимо создавать объекты классов Base и Desc, и передавать их в каждую из трех функций, объясняя при этом, когда и почему вызывается какой конструктор или деструктор.
	/*Base* a[10];
	for (int i = 0;i < 10;i++) {
		if (rand() % 2 == 0)
			a[i] = new Desc;
		else
			a[i] = new Desc2;
	}
	for (int i = 0;i < 10;i++)
		a[i]->foo();
	*/

}
