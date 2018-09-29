// lab4.cpp 
//Указатель-переменная,харнящая адрес(смещение) каких-либо данных и переменных в оперативной памяти
//Переменная называется pointer
/* Указатель объявляется как обычная переменная с добавлением звездочки
int * ptr_int;
Фактически указатель это unsigned int или unsigned long long с адресом так как дробных
или отрицательных адресов нет
sizeof-указатель
Все указатели одной и той же разрядности(размера)
cout << "int pointer size =" << sizeof(ptr_int) << endl;
cout << "double pointer size =" << sizeof(ptr_dbl) << endl;
cout << "char pointer size =" << sizeof(char *) << endl;
cout << "long long pointer size =" << sizeof(long long *) << endl;
cout << "bool pointer size =" << sizeof(bool *) << endl;
*/



#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int * ptr_int;
	double * ptr_dbl;
	
	cout << "int pointer size =" << sizeof(ptr_int) << endl;
	cout << "double pointer size =" << sizeof(ptr_dbl) << endl;
	cout << "char pointer size =" << sizeof(char *) << endl;
	cout << "long long pointer size =" << sizeof(long long *) << endl;
	cout << "bool pointer size =" << sizeof(bool *) << endl;
	
	int arr1D[5] = { 1, 2, 3, 4, 5 };
	cout << "arr = " << arr1D << endl;
	cout << "*arr = arr[0] = " << *arr1D << endl;
	cout << "*(arr+4) = arr[4] = " << *(arr1D + 4) << endl;

		
}

