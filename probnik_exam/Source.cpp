#include <iostream>
#include <string>
#include "Header.h"

int main() {
	myClass a;
	a.input(); a.print();
	char b[5] = "123";
	a.add(b);
	a.print();
	system("pause");
	return 0;
}

myClass::myClass() {
	p = new char[0];
}
myClass::myClass(char *p1) {
	p = new char[strlen(p1)];
	for (int i = 0; i < strlen(p1); i++) {
		p[i] = p1[i];
	}
}
myClass::myClass(std::string &sl) {
}

myClass::~myClass()
{
}

void myClass::clear()
{
	p = nullptr;
	length = 0;
}

void myClass::add(char *p1)
{
	int size;
	char *a;
	size = strlen(p1) + length;
	a = new char[size];
	for (int i = 0; i < length; i++) {
		a[i] = p[i];
	}
	for (int i = length; i < size; i++) {
		a[i] = p1[i - length];
	}
	length = size;
	p = new char[length];
	for (int i = 0; i < size; i++) {
		p[i] = a[i];
	}
	delete[] a;
	/*strcpy(a, p);
	strcat(a, p1);
	p = new char[size];
	strcpy(p, a);*/
}

void myClass::add(std::string sl)
{
	//	strcat(p, sl);
}

void myClass::insert(int pos, char *p1)
{
	if (pos > length) {
		std::cout << "error";
	}
	else {
		char *a;
		length += strlen(p1);
		a = new char[length + 1];
		for (int i = 0; i < pos; i++) {
			a[i] = p[i];
		}
		a[pos] = '\0';
		for (int i = pos; i < pos + strlen(p1); i++) {
			a[i] = p1[i - pos];
		}
		a[pos + strlen(p1)] = '\0';
		for (int i = pos + strlen(p1); i < length; i++) {
			a[i] = p[i - strlen(p1)];
		}
		a[length] = '\0';
		p = new char[length + 1];
		for (int i = 0; i < length + 1; i++) {
			p[i] = a[i];
		}
		delete[] a;
	}
}

void myClass::cut(int pos, int num)
{
	if ((pos <= length) || (num <= (length - pos))) {
		for (int i = pos - 1; i < pos + num - 1; i++) {
			p[i] = 0;
		}
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length - 1; j++) {
				if (p[j + 1] == 0) {
					p[j + 1] = p[j];
					p[j] = 0;
				}
			}
		}
		char *a;
		length -= num;
		a = new char[length];
		for (int i = 0; i < length; i++) {
			a[i] = p[i + num];
		}
		p = new char[length];
		for (int i = 0; i < length; i++) {
			p[i] = a[i];
		}
		delete[] a;

	}
	else {
		std::cout << "error";
	}
}

void myClass::input()
{
	std::cin >> length;
	p = new char[length];
	for (int i = 0; i < length; i++) {
		std::cin >> p[i];
	}
	p[length] = '\0';
}

void myClass::print()
{
	for (int i = 0; i < length; i++) {
		std::cout << p[i] << '\t';
	}
	std::cout << '\n';
}