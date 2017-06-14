#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

const int N = 3;
void multiplyMatrix(const double a[][N], const double b[][N], double c[][N]);

int main()
{
	string matrix1;
	string matrix2;

	double m1[N][N];
	double m2[N][N]; 
	double m3[N][N];

	int row = 0;
	int column = 0;


	cout << "Matrix1: " << endl;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			double digit;
			cin >> digit;
			m1[row][column] = digit;
		}
	}

	cout << "Matrix2: " << endl;
	
	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			double digit;
			cin >> digit;
			m2[row][column] = digit;
		}
	}

	multiplyMatrix(m1, m2, m3);

	std::getline(cin, matrix1);
	cin.get();


	return 0;
}

void multiplyMatrix(const double a[][N], const double b[][N], double c[][N])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			double result = (a[i][0] * b[0][j]) + (a[i][1] * b[1][j]) + (a[i][2] * b[2][j]);
			c[i][j] = result;
		}
	
	}

	cout << endl;
	cout << "Result:" << endl;
	cout << endl;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			cout << c[x][y] << " ";
		}

		cout << endl;
	}
}

