#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include"windows.h"
using namespace std;
class base
{
public:
	bool rab = true;
	int id = 0;
	ifstream infile;
	ofstream outfile;
	bool check_name(string name);
	bool check_passport(string passport);
	void add_file(string buff);
	void find(string name);
	void delet(int id_delet);
	void change();
	void start();
	void copy();
	void add();
	void show();
	string data = "data.txt";
	string example(int id, string name, string second_name, string passport);
	base();
	~base();
};
