// Shaiker_sortirovka.cpp 
//Сортировка шейкерным методом с функциями

#include "pch.h"
#include <iostream>
using namespace std;

void Swap(int *a, int *b)
{
	swap(*a, *b);
}

// Вывод массива
void printArray(int array[], int len)
{
	for (int i = 0; i < len; i++)
		cout << array[i] << " ";
}


// Ввод массива
void initArray(int array[], int len)
{
	cout << "Vvedite massiv \n";
	for (int i = 0; i < len; i++)
		cin >> array[i];
}
//Функция сортировки
void shaiker(int array[], int len)
{
	for (int i = 0; i < len / 2; i++) 
	{
		for (int j = i; j < len - i - 1; j++) 
		{
			if (array[j] > array[j + 1])
				Swap(&array[j], &array[j + 1]); 
		}
		for (int j = len - i - 2; j > i; j--) 
			if (array[j] < array[j - 1])
				Swap(&array[j], &array[j - 1]); 
	}
}

int main()
{
	const int len = 5;
	int A[len];
	initArray(A, len);
	shaiker(A, len);
	printArray(A, len);
}