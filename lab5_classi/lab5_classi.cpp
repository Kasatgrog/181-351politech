// lab5_classi.cpp Лаб5 классы
//



#include "pch.h"
#include <iostream>
using namespace std;

//class vehicle 
//{
//private:
//public:
//	double speed; //speed
//	char regnumber[6] = { 0 };//госномер
//	unsigned char capacity; //число пассажиров
//	bool check_regnumber()
//		//void add_passenger(int passengers);
//		//void accelerate(double delta_velocity);
//Конструктор и деструктор класса
//В случае если при создании объекта нужно выполнять сложные действия по
//инициализации,установлению сетевого соединения
//Конструктор вызывается автоматически при создании объекта 
//лучае если при исчезновении объекта нужно общие системные ресурсы освобождать:
//закрывать порты,освобождать ОП,сохранять файлы и т.д
//clописываются в методе-деструкторе user_data (вызывается автоматически при исчезновении объекта
{
private:
	char first_name[255];
	char second_name[255];
	char str_passport[10];
	char str_birthdate[10];

public:
	user_data();//конструктор
	~user_data();//деструктор- delete-вызов
	user_data(char p_first_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10]);
	user_data(char p_firstname[255], char p_secondname[255]);
	
	bool set_first_name(char p_first_name[255])
	{
		
		
		for (int i = 0; i < 255; i++)
		{

			
			if ((p_first_name[i] > 32) && (p_first_name[i] < 45) && (p_first_name[i] > 45) && (p_first_name[i] < 65))//проверяем диапазон
				

			return false;
		}

		/*first_name = p_first_name;*/
		for (int i = 0; i < 255; i++)
		{
			for (int j = 0; j < 255; ++j)
				first_name[i][j] = p_first_name[i][j];
		}

	}
	bool set_birthdate(char p_birthdate[10]) //должно соответствовать формату 00.00.0000
	{
		for (int i = 0; i < 2; i++)
		{
			if (p_birthdate[i] < '0' || p_birthdate[i] > '9')
				return false;
		}

		for (int i = 3; i < 5; i++)
		{
			if (p_birthdate[i] < '0' || p_birthdate[i] > '9')
				return false;
		}
		for (int i = 6; i <= 9; i++)
		{
			if (p_birthdate[i] < '0' || p_birthdate[i] > '9')
				return false;
		}
	}
	bool set_passport(char p_passport[10])
	{
		for (int i = 0; i < 10; i++)
		{
			if (p_passport[i] < 48 || p_passport[i] > 57)
				return false;
		}
	}
};

user_data(char p_first_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10] )



int main()
{
	user_data set_passport;
	const char passport[10];
	if (bool set_passport = true)
	{
		cout << "yes" << endl;
	}

	return 0;
}

