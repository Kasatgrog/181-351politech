#include "pch.h"
#include "exam.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


Exam::Exam()
{
	lenght = 0;
}
Exam::Exam(char * wor)
{
	string a = string(wor);
	int len = a.length();
	data = new char[len];
	for (int i = 0; i < len; i++)
	{
		data[i] = a[i];
	}
	lenght = len;

}
Exam::Exam(string a)
{
	int len = a.length();
	data = new char[len];
	for (int i = 0; i < len; i++)
	{
		data[i] = a[i];
	}
	lenght = len;
}

Exam::Exam(Exam & wor)
{
	data = wor.data;
	lenght = wor.lenght;
}

Exam::~Exam()
{
}


int * Exam::add(char * wor)
{
	string buffer;
	if (lenght != 0)
	{
		buffer = string(data);
	}
	int len = buffer.length();
	delete[] data;
	buffer += string(wor);
	data = new char[buffer.length()];
	for (int i = 0; i < len; i++)
	{
		data[i] = buffer[i];
	}
	lenght = int(buffer.length());
	return nullptr;
}

int Exam::add(string dat)
{
	string buffer;
	if (lenght != 0)
	{
		buffer = string(data);
		delete[] data;
	}

	buffer = buffer + dat;
	data = new char[buffer.length()];
	for (int i = 0; i < buffer.length(); i++)
	{
		data[i] = buffer[i];
	}
	lenght = int(buffer.length());
	return 0;
}

int * Exam::insert(char * wor, int a)
{
	if (a > lenght - 1) {
		string buffer;
		if (lenght != 0)
		{
			buffer = string(data);
			delete[] data;
		}

		buffer += string(wor);
		data = new char[buffer.length()];
		data = (char*)buffer.c_str();
		lenght = int(buffer.length());
		return nullptr;
	}
	else {
		if (a < 0) {
			string buffer;
			buffer = string(wor);
			if (lenght != 0)
			{
				buffer += string(data);
			}
			delete[] data;;
			data = new char[buffer.length()];
			for (int i = 0; i < buffer.length(); i++)
			{
				data[i] = buffer[i];
			}
			lenght = int(buffer.length());
			return nullptr;
		}
		string buffer;
		if (lenght != 0)
		{
			buffer += string(data);
		}
		buffer.insert(a, wor);
		delete[] data;;
		data = new char[buffer.length()];
		for (int i = 0; i < buffer.length(); i++)
		{
			data[i] = buffer[i];
		}
		lenght = int(buffer.length());
		return nullptr;
	}
}

int Exam::insert(string wor, int a)
{
	if (a > lenght - 1)
	{
		string buffer;
		if (lenght != 0)
		{
			buffer += std::string(data);
		}
		buffer.insert(lenght - 1, wor);
		delete[] data;;
		data = new char[buffer.length()];
		for (int i = 0; i < buffer.length(); i++)
		{
			data[i] = buffer[i];
		}
		lenght = int(buffer.length());
		return 0;
	}
	else {
		if (a < 0)
		{
			string buffer;
			if (lenght != 0)
			{
				buffer += string(data);
			}
			buffer.insert(0, wor);
			delete[] data;;
			data = new char[buffer.length()];
			for (int i = 0; i < buffer.length(); i++)
			{
				data[i] = buffer[i];
			}
			lenght = int(buffer.length());
			return 0;
		}
		string buffer = "";
		if (lenght != 0)
		{
			buffer += string(data);
		}
		buffer.insert(a, wor);
		delete[] data;;
		data = new char[buffer.length()];
		for (int i = 0; i < buffer.length(); i++)
		{
			data[i] = buffer[i];
		}
		lenght += int(wor.length());
		return 0;
	}

	return 0;
}

void Exam::clear()
{
	delete[]data;
	lenght = 0;
}

ostream & operator	<< (ostream & os, Exam s)
{

	string buffer;
	buffer = string(s.data);
	for (int i = 0; i < s.lenght; i++)
	{
		os << s.data[i];
	}
	os << endl;
	return os;
}