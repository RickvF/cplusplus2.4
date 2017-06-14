#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cstdlib>
#include <ctime>

using namespace std;

int nmbrRow = 0;

vector<int> findLargestBlock(const vector<vector<int>>& m)
{
	vector<int> result;
	vector<int> grootste;
	int grootsteSize = 0;

	for (int y = 0; y < nmbrRow; y++)
	{
		for (int x = 0; x < nmbrRow; x++)
		{
			if (m.at(y).at(x) == 1)
			{
				//check x
				int xx = x;
				for (xx = x; xx < nmbrRow; xx++)
				{
					if (m.at(y).at(xx) == 0)
					{
						break;
					}
				}
				xx--;

				//check y
				int yy = y;
				for (yy = y; yy < nmbrRow; yy++)
				{
					if (m.at(yy).at(x) == 0)
					{
						break;
					}
				}
				yy--;

				vector<pair<int, int>> ytoppen;
				vector<pair<int, int>> xtoppen;

				for (int x3 = x; x3 < xx + 1; x3++)
				{
					for (int y3 = y; y3 < nmbrRow; y3++)
					{
						if (m.at(y3).at(x3) == 0)
						{
							ytoppen.push_back(pair<int, int>(x3, y3));
							break;
						}
					}
				}

				for (int y4 = y; y4 < yy + 1; y4++)
				{
					for (int x4 = x; x4 < nmbrRow; x4++)
					{
						if (m.at(y4).at(x4) == 0)
						{
							xtoppen.push_back(pair<int, int>(y4, x4));
						}
					}
				}

				for (int position = 0; position < nmbrRow; position++)
				{
					if (position < ytoppen.size() && position < xtoppen.size())
					{
						int ytopX = ytoppen.at(position).first;
						int ytopY = ytoppen.at(position).second;
						int xtopX = xtoppen.at(position).second;
						int xtopY = xtoppen.at(position).first;

						if (ytopY - ytopX >= 0 && xtopX - xtopY >= 0)
						{
							int size = position+1;
							if (size > grootsteSize)
							{
								grootste.clear();
								grootste.push_back(x);
								grootste.push_back(y);
								grootste.push_back(size);
								grootsteSize = size;
							}
						}
					}
					else if (ytoppen.size() == 0 && xtoppen.size() == 0)
					{
						int size = nmbrRow - x;
						if (size > grootsteSize)
						{
							grootste.clear();
							grootste.push_back(x);
							grootste.push_back(y);
							grootste.push_back(size);
							grootsteSize = size;
						}
					}
				}
			}
		}
	}


	result = grootste;

	return result;
}

int main()
{
	string INPUT2;
	cout << "Enter the number of rows for the matrix:" << endl;
	cin >> nmbrRow;
	getline(cin, INPUT2);

	vector<vector<int>> matrix;

	cout << "Enter the matrix row by row:" << endl;
	for (int y = 0; y < nmbrRow; y++)
	{
		vector<int> row;
		for (int i = 0; i < nmbrRow; i++)
		{
			int value;
			cin >> value;
			row.push_back(value);
		}
		getline(cin, INPUT2);
		matrix.push_back(row);
	}

	cout << endl;
	cout << "Please wait....." << endl;
	cout << endl;
	
	vector<int> output = findLargestBlock(matrix);

	cout << "The maximum square submatrix is at (" << output.at(0) << ", " << output.at(1) << ") with size " << output.at(2) << endl;

	getline(cin, INPUT2);
	return 0;
}