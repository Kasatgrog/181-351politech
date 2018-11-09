// lab6_matrix.cpp 

#include "pch.h"
#include <iostream>
using namespace std;
class matrix
{
private:
	//свойства класса
	double matr[10][10];
	int rows; //строки
	int columns; //столбцы
public:
	matrix(){}
	~matrix();
	
	//void setMatrix(int p_rows, int p_colums, int p_matr[10][10]);

	int getRows()
	{
		return rows;
	}


	int getColumns()
	{
		return columns;
	}

	bool summMatrix(matrix matr2); //сумма матриц
	bool input();

	bool multMatrix(matrix matr2); //произведение матриц
/////////////////////////////////////////////////////////////////	
	bool transp()
	{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matr[i][j] = matr[j][i];
			}
		}
		return true;
	}


	/////////////////////////////////////////////////////////////////	
	double getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		std::cout << "Connot get elenent. Index Error!\n";
		return	-1;
	}

	////////////////////////////////////////////////////////////////
	void print(); //печать
	/*{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << matr[i][j] << endl;
			}
		}

	}*/
	////////////////////////////////////////////////////////////////
};


int main()
{
	//	matrix matrA, matrB;
	//	matrA.input();
	//	matrB.input();
	//	matrA.transp(); matrA.print();
	//	matrA.summMatrix(matrB); matrA.print();
	//	matrA.multMatrix(matrB); matrA.print();
	   // return 0;
	matrix Matrica;
	cout<<Matrica.transp();
	return 0;
}

bool matrix::summMatrix(matrix matr2)
{
	if ((rows == matr2.getRows()) && (columns == matr2.getColumns()) )
	{
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < columns; j++) 
			{
				matr[i][j] += matr2.getElem(i, j);
			}
		}
	}

	return true;
}


matrix::~matrix()
{

}


bool matrix::input()
{
	cin >> rows;

	if ((rows >= 10) || (rows <= 0))
	{
		return false; //иначе вернуть ошибку
	}

	cin >> columns;
	if ((columns >= 10) || (columns <= 0))
	{
		return false; //иначе вернуть ошибку
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cin >> matr[i][j];
		}
	}
	//считать элементы матрицы
	return true;
}

void matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i][j];
		}
		cout << endl;
	}
}
