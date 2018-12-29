// lab6_matrix.cpp 

#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;
class matrix
{
private:
	int matr[10][10];
	int rows, columns;
	int res[10][10];
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
				cout << matr[i][j] << "\t";
			}
			cout << endl;
		}
	};


};
class vector : public matrix
{
private:
	int vec[10];
	int n;
public:
	int getN() { return n; }
	int getEl(int n);
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
};

int main()
{
	matrix matrA, matrB;
	vector vecA, vecB;
	


	
	vecA.enter();
	vecB.enter();
	vecA.multvec(vecB);
	

	return 0;
}
matrix::matrix() {}
matrix::~matrix() {}

bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i][j] += matr2.getElem(i, j);
			}
		}
		printM();
		return true;
	}
	else { return false; }
}

void matrix::transp()
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{

			cout << matr[j][i] << "  ";
		}
		cout << endl;
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
					sum += matr[i][k] * matr2.getElem(k, j);
				}
				res[i][j] = sum;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
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
		return matr[row][col];
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
	cin >> rows;
	if (rows < 1 || rows>10) { return false; }
	cout << "columns=";
	cin >> columns;
	if (columns < 1 || columns>10) { return false; }
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "matr[" << i << "][" << j << "]=";
			cin >> matr[i][j];
		}
		cout << endl;
	}
	return true;
}

int vector::getEl(int n)
{
	if (n < 10 && n>-1) { return vec[n]; }
	else
	{
		cout << "error";
		return -1;
	}
}

bool vector::enter()
{
	cout << "n=";
	cin >> n;
	if (n < 1 || n>10) { return false; }
	for (int j = 0; j < n; j++)
	{
		cout << "vec[" << j << "]=";
		cin >> vec[j];
	}
	return true;
}

bool vector::multvec(vector vec2)
{
	int scal = 0;
	if (n = vec2.getN()) {
		for (int i = 0; i < n; i++)
		{
			scal += vec[i] * vec2.getEl(i);
		}
		cout << scal;
	}
	else { return false; }
}