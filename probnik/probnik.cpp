// probnik.cpp : Пробный экзамен
//
#include <string.h>
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////
class Test2 
{
public:
	void edit(char *&string) {
			int length = strlen(string);        // Длина входной строки
			char *result = new char[length * 2];// Результирующая строка, не более чем в два раза больше исходной
			int result_size = 0;                // Размер результирующей строки
			result[result_size++] = string[0];  // Копируем первый элемент в строку и увеличиваем ее размер

			char preprev = '\0'; // Позапрошлый символ
			// Проходимся по всем символам
			for (int i = 1; i < length; ++i) {
				// Если какой-то символ встречается в первый раз, добавляем его
				if (string[i] != string[i - 1]) {
					// Если прошлый символ был 'a' и он не равен позапрошлому, добавляем его
					if (string[i - 1] == 'a' && preprev != 'a') {
						result[result_size++] = 'a';
					}
					result[result_size++] = string[i];
				}
				// Обновляем позапрошлый символ
				preprev = string[i - 1];
			}
			result[result_size] = '\0'; // Добавляем в конец '\0'

			delete[] string;  //Заменяем входную строку на новую
			string = result;
		}
};

class Test 
{
private:
	int size;
	char *arr;
	char *sum;//для сложения строк
	char *null;
public:
	
	//char arr[100];
	//Test(); //конструктор
	
	
	void message() //вывод сообщения на экран
	{
		cout << "Введите размер массива :" << endl;
	}
	void setSize()
	{
		cin >> size;
	}
	void newChar()
	{
		arr = new char[size];
	}
	void zapolnenie()
	{
		cout << "Заполните массив :" << endl; //заполнение
		for (int i = 0; i < size; i++)
			cin >> arr[i];
		cout << endl;
	}
	void clear() //обнуление
	{
		for (int i = 0; i < size; i++) {
			arr[i] = '\0'  ;
			cout << arr[i] << endl;
		}
	}
	void Deleter()
	{
		for (int i = 0; i < size; i++)
			cout << " " << arr[i];
		delete[] arr;
	}
	/*void add()
	{
		strcat(strcpy(arr, sum), null);
		cout << arr << sum << null << endl;
	}*/
};

//strcat(strcpy(string3, string1), string2); //сложение строк
int main()
{
	setlocale(LC_ALL, "Russian");
	Test2 massivich;
	//massivich.edit();
	char* input = new char[1000];
	cin.getline(input, 1000);
	//edit(input);
	cout << input << endl;
	delete[] input;

	Test dyn_mas;
	dyn_mas.message();
	dyn_mas.setSize();
	dyn_mas.newChar();
	dyn_mas.zapolnenie();
	dyn_mas.Deleter();
	dyn_mas.clear();
	

	///////////////////////////////////////////////////////////////////
		
		
	
	
	system("pause");
	return 0;
}

