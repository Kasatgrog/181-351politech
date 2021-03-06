// Lab6_nasledovanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Наследование-заимствование родительского класса в произвольный
//синтаксис
//class имя_произв_класса : [тип наследования] имя_родительского_класса {
//}; где тип наследования public


//в классе           public:            protected:           private:
//public:            public:            protected:           private:
//protected:         protected:         protected:           protected:
//private:           недоступ           недоступ             недоступ


//Метод,переопределенный в дочернем классе полностью заменит унаследованный родительский метод
//в родительском классе void weapon::reload() {};
//в дочернем классе void rifle::reload():weapon::reload(),...{};


//Если объявить метод со словом virtual то в данном классе можно не приводить
//реализацию метода,и определить его(провести реализацию) только в дочерних классах


// Объявление константного метода класса запрещает менять ему какое-либо свойство объекта
//void fnc1(const тип1 параметр1, тип2 параметр2)
//{
//	параметр1 = 10;
//}

//void fnc1(const тип1 параметр1, тип2 параметр2) const
//{
//параметр1 = 10;
//}

//Приведение типов
//int i = -15;
//double d = 1000.5e03;// равно 1000.5 * 10^3 = pow(10, 3)
// float result1;
//long long result2;
//result1 = i + d;
//result2 = i / d;
//
//const char *ch1 = "123";
//"123" + "456"
//string "123456"
//char * char * 

//d = atof(ch2);//преобразование в double
//i = atoi(ch1);//преобразование в int или long



#include "pch.h"
#include <iostream>
using namespace std;



int main()
{
	int i = -15;
	double d = 1000.5e03;// равно 1000.5 * 10^3 = pow(10, 3)
    float result1;
	long long result2;
	result1 = i + d;
	result2 = i / d;
	const char *ch1 = "123.4";
	const char *ch2 = "456.7";
	//"123" + "456"
	//string "123456"
	//char * char * 
	cin >> ch1;
	cout << endl;
	cin >> ch2;
	cout << endl;
		d = atof(ch2)*10/10;//преобразование в double
        i = atoi(ch1);//в int или long
		i += d;
		cout << i << endl;
		getchar();
		return 0;

}


