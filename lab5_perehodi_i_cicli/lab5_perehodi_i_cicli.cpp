// lab5_perehodi_i_cicli.cpp : 
//Операторы переходов и циклов

#include "pch.h"
#include <iostream>
using namespace std;

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
		}
		
}
	



