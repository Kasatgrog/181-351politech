// Shifr_Cesara.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int key;
	char a[30] /*= { 0 }*/;
	cout << "vvedite stroku" << endl;
	    cin >> a;
		cout << "vvedite sdvig" << endl;
		cin >> key;
	for (int i = 0; i < strlen(a); i++) {

		a[i] += key;
		if (((a[i] > 'Z') && (a[i] < 'a')) || (a[i] > 'z'))
			a[i] = a[i] - 26;
	}
	    cout << a;
}


