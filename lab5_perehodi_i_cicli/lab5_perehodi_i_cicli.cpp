// lab5_perehodi_i_cicli.cpp : 
//Операторы переходов и циклов

#include "pch.h"
#include <iostream>
using namespace std;
int func(int num1, int num2);
int arr[10];
int* input_array() {
		int arr[10] = { 0 };
		for (int iter = 0; iter < 10; iter++) {
			cin >> arr[iter];
		}
		return arr;
	}
int main()
{
	input_array();
		for (int iter = 0; iter < 10; iter++) {
			cout << arr[iter];
			getchar();
				return 0;
		}
		

		int num1 = 1, num2 = 2, res = 0;
		res = func( num1, num2 );
		cout << res << " " << num1 << " " << num2 << endl;
}
	
int func(int num1, int num2) 
{
	num1 += 10;
	return num1 + num2;
}

//ДЗ Сделать цезаря в виде фуекции и пузырек в виде функций
