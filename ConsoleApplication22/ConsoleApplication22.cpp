

#include <iostream>
#include<string>
using namespace std;
class Base {
//protected:
	//std::string = base;
public:
	Base() {//обычный конструктор
		printf("Base()\n");
	}
	Base(Base* obj) { 
		printf("Base(Base* obj)\n");
	}

	Base(Base& obj) {//копирующий конструктор
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
	virtual~Base() { 
		printf("~Base()\n");
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
	virtual~Desc() { 
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
	obj.classname();
	printf("func1\n");
};

void func2(Base* obj) { 
	obj->classname();
	printf("func2\n");
};

void func3(Base& obj) {
	obj.classname();
	printf("func3\n");
};

int main()
{
	setlocale(LC_ALL, "Rus");
	
	//в указатель на объект класса Base помещаем адрес объекта класса Desc
	printf("obj1: ");
	Base* obj1 = new Desc;
	//в указатель на объект класса Desc помещаем адрес объекта класса Desc
	printf("obj2: ");
	Desc* obj2 = new Desc;
	//в указатель на объект класса Base помещаем адрес объекта класса Base
	printf("obj3: ");
	Base* obj3 = new Base;
	//Base obj0(*obj3);
	printf("Вызов функции 1, передаем в функцию объект\n");
	printf("\n obj1: \n");
	func1(*obj1);
	printf("\n obj2: \n");
	func1(*obj2);
	printf("\n obj3: \n");
	func1(*obj3);

	printf("Вызов функции 1, передаем в функцию указатель на объект\n");
	printf("\n obj1: \n");
	func1(obj1);
	printf("\n obj2: \n");
	func1(obj2);
	printf("\n obj3: \n");
	func1(obj3);
	
	printf("Вызов функции 2, передаем в функцию указатель на объект\n");
	printf("\n obj1: \n");
	func2(obj1);
	printf("\n obj2: \n");
	func2(obj2);
	printf("\n obj3: \n");
	func2(obj3);
	
	printf("Вызов функции 3, передаем в функцию объект\n");
	printf("\n obj1: \n");
	func3(*obj1);
	printf("\n obj2: \n");
	func3(*obj2);
	printf("\n obj3: \n");
	func3(*obj3);

	printf("obj1: \n");
	delete obj1;
	printf("obj2: \n");
	delete obj2;
	printf("obj3: \n");
	delete obj3;
	//if (base2->classname() == "Desc")
		//((Desc*)base2)->classname();

	/*if (obj1->isA("Desc"))
		printf("\n ");

	Desc* d = dynamic_cast<Desc*>(obj1);
	if (d != NULL)
		d->classname();*/
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
