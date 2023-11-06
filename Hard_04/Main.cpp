#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;
//--------------------- ������� -------------------------------------------------
/*
���� ���������� ������� �������� nxn.
����� ����������� ������� ����� ���������, ������������� ���� ������� ���������,
����� ������������ �������, ����� ��������� ������������� ���� �������� ���������.
��������� ����������� � ������������ �������� �������� ������� � ������� �� �������.
*/
//---------------------������� � ���������---------------------------------------





//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------���� �����-------------------------------------

	int n;
	cout << "������� ����������� �������: " << endl;
	cin >> n;

	int** arr = new int* [n];           // ������� ������������ ��������� ������
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];                   // ������� ������� ��� �������
	}
	/////////////// ���������� �������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 1 + rand() % 99;
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//---------------------- ������---------------------------------------------------

	int min = 101;
	int i_min = 0, j_min = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i][j] < min)
			{
				min = arr[i][j];
				i_min = i;
				j_min = j;
	        }
		}
	}

	cout << "min[" << i_min + 1 << "][" << j_min + 1 << "] = " << min << endl;

	int max = -1;
	int i_max = 0, j_max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				i_max = i;
				j_max = j;
			}
		}
	}

	cout << "max[" << i_max + 1 << "][" << j_max + 1 << "] = " << max << endl << endl;

	//----������ �������--

	int buff = 0;

	buff = arr[i_min][j_min];
	arr[i_min][j_min] = arr[i_max][j_max];
	arr[i_max][j_max] = buff;

	cout << "������ ����� ������������ ������������� � ������������ ���������: " << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "min[" << i_max + 1 << "][" << j_max + 1 << "] = " << min << endl;
	cout << "max[" << i_min + 1 << "][" << j_min + 1 << "] = " << max << endl << endl;

	system("pause");
	return 0;
}
