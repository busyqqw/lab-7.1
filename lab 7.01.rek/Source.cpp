#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int i0);
void Change(int** a, const int row1, const int row2, const int colCount, int j);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 11;
	int High = 57;
	int rowCount = 7;
	int colCount = 5;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	Sort(a, rowCount, colCount, 0);
	Print(a, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k, 0, 0);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(a, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	if (i >= rowCount)
		return;
	if (j >= colCount) {
		Create(a, rowCount, colCount, Low, High, i + 1, 0);
		return;
	}
	a[i][j] = Low + rand() % (High - Low + 1);
	Create(a, rowCount, colCount, Low, High, i, j + 1);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	if (i >= rowCount)
	{
		cout << endl;
		return;
	}
	if (j < colCount) {
		cout << setw(4) << a[i][j];
		Print(a, rowCount, colCount, i, j + 1);
	}
	else {
		cout << endl;
		Print(a, rowCount, colCount, i + 1, 0);
	}
}

void Sort(int** a, const int rowCount, const int colCount, int i0) {
	if (i0 >= rowCount - 1) {
		return;
	}

	for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) {
		if (a[i1][0] < a[i1 + 1][0]) {
			Change(a, i1, i1 + 1, colCount, 0);
		}
		else if (a[i1][0] == a[i1 + 1][0]) {
			if (a[i1][1] < a[i1 + 1][1]) {
				Change(a, i1, i1 + 1, colCount, 0);
			}
			else if (a[i1][1] == a[i1 + 1][1]) {
				if (a[i1][2] < a[i1 + 1][2]) {
					Change(a, i1, i1 + 1, colCount, 0);
				}
			}
		}
	}
	Sort(a, rowCount, colCount, i0 + 1);
}

void Change(int** a, const int row1, const int row2, const int colCount, int j) {
	if (j >= colCount) {
		return;
	}

	if (a[row1][j] < a[row2][j]) {
		int tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
	}
	else if (a[row1][j] == a[row2][j]) {
		Change(a, row1, row2, colCount, j + 1);
	}
}


void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
	if (i >= rowCount)
		return;
	if (j >= colCount) {
		Calc(a, rowCount, colCount, S, k, i + 1, 0);
		return;
	}

	if (a[i][j] % 13 == 0 && a[i][j] % 2 == 0)
	{
		S += a[i][j];
		k++;
		a[i][j] = 0;
	}
	Calc(a, rowCount, colCount, S, k, i, j + 1);
}
