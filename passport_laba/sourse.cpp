#include <iostream>
#include<fstream>
#include <string>
#include "base.h"

int main() {
	/*ofstream fout;
	fout.open("data.txt");
	fout << "aaaa";
	fout.close();
	ifstream fin;
	fin.open("data.txt");
	ofstream fout1("data1.txt");
	char buffer[1000];          
	while (!fin.eof())        
	{
		fin.getline(buffer, sizeof(buffer));  
		fout1 << buffer << endl;                  
	}
	fin.close();     
	fout1.close();    
	base a;

	//getchar();	*/
	base a;
	while (a.rab)
	{
		a.start();
	}

}