// Puzirek.cpp
//Сортировка пузырьком

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	const int n = 5;
	int a[n];
		for (int i = 0; i < n; i++) {
			cout << "vvedite massiv" << endl;
			cin >> a[i];
		}
		for ( int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (a[j] > a[j + 1]) {
					swap(a[j], a[j + 1]);
				}
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i];
}


