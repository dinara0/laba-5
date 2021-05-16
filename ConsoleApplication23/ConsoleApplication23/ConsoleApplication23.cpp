

#include <iostream>
#include<string>
using namespace std;
class Base {
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

	void method() {// этот метод будет наследоватбся в потомке
		printf("Base::method()\n");
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
	virtual ~Base() {
		printf("~Base()\n");
	}
};

class Desc : public Base {
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

	void method() {// наследуемый метод
		printf("Desc::method()\n");
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
	//показать на примере случай, когда вызывается перекрываемый метод,
	//а когда наследуемый
	printf("вызов наследуемого метода: \n");
	obj1->method();//вызываем наследемый метод
	obj2->method();
	obj3->method();
	printf("вызов перекрываемого метода: \n");
	obj1->classname();//вызываем перекрываемый метод
	obj2->classname();
	obj3->classname();
	//базоввый деструктор
	printf("вызов виртуального деструктора: \n");
	printf("obj1: \n");
	delete obj1;
	printf("obj2: \n");
	delete obj2;
	printf("obj3: \n");
	delete obj3;
	/*Base *array[3];
	for (int i = 0; i < 3; i++) {
		array[i] = new Desc;
	}
	for (int i = 0; i < 3; i++) {
		array[i]->method();//вызываем наследемый метод	
	}
	for (int i = 0; i < 3; i++) {		
		array[i]->classname();
	}
	for (int i = 0; i < 3; i++) {
		delete array[i];
	}
		*/



}

