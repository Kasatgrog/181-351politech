#pragma once
#include <iostream>
#include<string>
class Exam
{
public:
	char*data;
	int lenght;
	Exam();
	Exam(char* wor);
	Exam(std::string a);
	Exam(Exam& wor);
	~Exam();
	friend std::ostream& operator<<(std::ostream& os, Exam s);
	int* add(char*wor);
	int add(std::string);
	int* insert(char*wor, int a);
	int insert(std::string wor, int a);
	void clear();
};
