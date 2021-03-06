// lab_9_peregruzka.cpp : 

#include "pch.h"
#include <iostream>
#include<sstream>
using namespace std;
//Перегрузка операторов позволяет определить действия, которые будет выполнять оператор.
//Перегрузка подразумевает создание функции, название которой содержит слово operator и символ перегружаемого оператора.
//Функция оператора может быть определена как член класса, либо вне класса.

class matrix
{
private:
	int * matr = new int[rows*columns];
	int rows, columns;
	int *res = new int[rows*columns];
public:
	matrix();
	~matrix();

	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);

	int getElem(int row, int col);
	int getRows() { return rows; }
	int getColumns() { return columns; }

	bool input();
	void transp();

	void printM()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matr[i*columns + j] << "\t";
			}
			cout << std::endl;
		}
	};
	friend ostream & operator<< (ostream & os, matrix & matr);
	friend matrix & operator + (matrix & matr, matrix & matr2);
	friend matrix & operator - (matrix & matr, matrix & matr2);
	friend matrix & operator *(matrix & matr, matrix & matr2);
};

class  vector :public matrix
{
private:
	int *vec = new int[n];
	int n;
public:
	vector();
	~vector();
	int getN() { return n; }
	int getEl(int i);
	bool enter();
	void kvec(int k)
	{
		for (int i = 0; i < n; i++)
		{
			vec[i] *= k;
			cout << vec[i] << ' ';
		}
	};
	bool multvec(vector vec2);
	friend vector & operator *(vector vec, vector vec2);
	friend vector & operator *(vector vec, int k);
	friend ostream & operator <<(ostream vc, vector vec);
	friend vector & operator+(vector vec, vector vec2);
	friend vector & operator-(vector vec, vector vec2);
};

vector::vector() {}
vector::~vector() {}



int main()
{
	matrix matrA, matrB, res;
	vector vec, vec2;
	int k;
	//cout << "k=";
	//cin >> k;
	//matrA.input();
	//matrB.input();
	//cout << (matrA+matrB);
	//res = matrA * matrB;
	cout << res;
	vec.enter();
	cout << vec;
	return 0;
}

matrix::matrix() {}
matrix::~matrix() { /*delete[] matr; */ }



bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i*columns + j] += matr2.getElem(i, j);
			}
		}
		printM();
		return true;
	}
	else
	{
		cout << "columns and rows are not equal";
		return false;
	}
}

void matrix::transp()
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matr[j * columns + i] << " ";
		}
		cout << std::endl;
	}

}

ostream & operator<<(ostream & os, matrix & matr)
{
	for (int i = 0; i < matr.getRows(); i++)
	{
		for (int j = 0; j < matr.getColumns(); j++)
		{
			os << matr.getElem(i, j) << "\t";
		}
		os << std::endl;
	}
	return os;
}

matrix & operator+(matrix & matr, matrix & matr2)
{
	matrix res;
	//res.columns = matr.columns;
//res.rows = matr.rows;
	//res.matr = new int[res.rows*res.columns];
	if (matr.getRows() == matr2.getRows() && matr.getColumns() == matr2.getColumns())
	{
		for (int i = 0; i < matr.getRows(); i++)
		{
			for (int j = 0; j < matr.getColumns(); j++)
			{
				matr.matr[i*matr.columns + j] = matr.getElem(i, j) + matr2.getElem(i, j);
			}
		}
		return matr;
	}
	else { cout << "error!"; return matr; }
}

matrix & operator-(matrix & matr, matrix & matr2)
{
	if (matr.getRows() == matr2.getRows() && matr.getColumns() == matr2.getColumns())
	{
		for (int i = 0; i < matr.getRows(); i++)
		{
			for (int j = 0; j < matr.getColumns(); j++)
			{
				matr.matr[i*matr.columns + j] = matr.getElem(i, j) - matr2.getElem(i, j);
			}
		}
		return matr;
	}
	else { cout << "error!"; return matr; }
}

matrix & operator*(matrix & matr, matrix & matr2)
{
	matrix res;
	res.columns = matr2.columns;
	res.rows = matr.rows;
	res.matr = new int[res.rows*res.columns];
	if (matr.getColumns() == matr2.getRows())
	{
		for (int i = 0; i < matr.getRows(); i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int sum = 0;
				for (int k = 0; k < matr.getColumns(); k++) {
					sum += matr.getElem(i, k)* matr2.getElem(k, j);
				}
				res.matr[i*matr2.getColumns() + j] = sum;
			}
		}
		/* delete[] matr.matr;
		 matr.matr = nullptr;
		 matr.matr = new int[res.rows*res.columns];
		 for (int i = 0; i < res.rows*res.columns; i++)
		 {
			 matr.matr[i] = res.matr[i];
		 }
		 delete[]  res.matr;*/
		return res;
	}
	else { cout << "error!"; return matr; }

}

// ДЛЯ ВЕКТОРОВ
vector & operator*(vector vec, vector vec2)
{
	int scal = 0;
	if (vec.getN() == vec2.getN())
	{

		for (int i = 0; i < vec2.getN(); i++)
		{
			scal += vec.getEl(i) * vec2.getEl(i);
		}
		cout << scal;
		//delete[]vec;
		return vec;
	}
	else { return vec; }
}

vector & operator*(vector vec, int k)
{
	for (int i = 0; i < vec.getN(); i++)
	{
		vec.vec[i] *= k;
	}
	return vec;
}

ostream & operator<<(ostream vc, vector vec)
{
	for (int i = 0; i < vec.getN(); i++)
	{
		vc << vec.getEl(i) << " ";
	}
	return vc;
}

vector & operator +(vector vec, vector vec2)
{
	if (vec.getN() == vec2.getN())
	{
		for (int i = 0; i < vec2.getN(); i++)
		{
			vec.vec[i] = vec.getEl(i) + vec2.getEl(i);
		}
	}
}

vector & operator -(vector vec, vector vec2)
{
	if (vec.getN() == vec2.getN())
	{
		for (int i = 0; i < vec2.getN(); i++)
		{
			vec.vec[i] = vec.getEl(i) - vec2.getEl(i);
		}
	}
}

bool matrix::multMatrix(matrix matr2)
{
	if (columns == matr2.getRows())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int sum = 0;
				for (int k = 0; k < columns; k++) {
					sum += matr[i*columns + k] * matr2.getElem(k, j);
				}
				res[i*matr2.getColumns() + j] = sum;
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				cout << res[i*matr2.getColumns() + j] << "\t";
			}
			cout << std::endl;
		}
		return true;
	}
	else
	{
		cout << "col1 != row2";
		return false;
	}
}

int matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col>-1)
	{
		return matr[row*columns + col];
	}
	else
	{
		cout << "error";
		return -1;
	}
}

bool matrix::input()
{
	cout << "rows=";
	std::cin >> rows;
	cout << "columns=";
	std::cin >> columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i*columns + j];
		}
		cout << std::endl;
	}
	return true;
}

bool vector::multvec(vector vec2)
{
	int scal = 0;
	if (n = vec2.getN())
	{
		for (int i = 0; i < n; i++)
		{
			scal += vec[i] * vec2.getEl(i);
		}
		cout << scal;
		//delete[]vec;
		return true;
	}
	else { return false; }
}

bool vector::enter()
{
	cout << "n=";
	std::cin >> n;
	for (int j = 0; j < n; j++)
	{
		cout << "vec[" << j << "]=";
		std::cin >> vec[j];
	}
	return true;
}

int vector::getEl(int i)
{
	if (i > -1 && i < n) { return vec[i]; }
	else
	{
		cout << "error!";
		return -1;
	}
}
