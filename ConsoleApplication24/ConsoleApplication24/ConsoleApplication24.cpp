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
		printf("bool isA\n");
		if ("Base" == classname)
			return 1;
		else return 0;
	}
	virtual~Base() {
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
	string classname() {
		printf("classname_Desc\n");
		return "Desc";
	}
	bool isA(std::string classname) {//базовый виртуальный метод bool isA(string classname), перекрыть его в потомках и показать отличие от метода classname.
		printf("bool isA\n");
		if ("Desc" == classname || Base::isA(classname))
			return 1;
		else return 0;
	}
	virtual~Desc() {
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
	
	//работа метода classname()
	printf("работа метода classname()\n");
	//obj1->classname();
	
	if (obj1->classname() == "Desc")
		printf("obj1 объект класса Desc\n");

	//если нужно будет узнать предка объекта, мы не сможем воспользоваться
	// методом  classname(), например

	if (obj1->classname() == "Base")
		printf("obj1 объект класса Base или его потомка\n");
	
	//теперь сравним с методом isA() 
	printf("\nопасное приведение типов с помощью isA\n");
	if (obj1->isA("Desc"))
		printf("obj1 объект класса Desc\n");

	if (obj1->isA("Base"))
		printf("obj1 объект класса Base или его потомка\n");


	printf("\nприведение типов с помощью dynamic_cast\n");
	Desc* d = dynamic_cast<Desc*>(obj1);
	if (d != NULL)
		printf("obj1 объект класса Desc\n");

	Base* b = dynamic_cast<Base*>(obj1);
	if (d != NULL)
		printf("obj1 объект класса Base или его потомка\n");
		

}
