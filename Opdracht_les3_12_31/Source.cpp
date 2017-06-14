#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
void removeDuplicate(vector<T>& v)
{
	vector<T> tempVec;
	for (auto &t : v)
	{
		if (!(find(tempVec.begin(), tempVec.end(), t) != tempVec.end()))
		{
			tempVec.push_back(t);
		}
	}

	v = tempVec;
}

template<typename T>
vector<T> intersect(const vector<T>& v1, const vector<T>& v2)
{
	vector<T> result;
	for (auto &t : v1)
	{
		if (find(v2.begin(), v2.end(), t) != v2.end())
		{
			result.push_back(t);
		}
	}

	return result;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(8);
	v1.push_back(6);
	v1.push_back(2);

	vector<int> v2;
	v2.push_back(9);
	v2.push_back(3);
	v2.push_back(5);

	vector<int> result = intersect(v1, v2);

	for (auto &i : result)
	{
		cout << i << endl;
	}

	cout << "------------------------" << endl;
	cout << "Remove Duplicate" << endl;
	cout << endl;

	vector<int> v3;
	v3.push_back(9);
	v3.push_back(3);
	v3.push_back(5);
	v3.push_back(5);
	v3.push_back(9);
	v3.push_back(8);
	v3.push_back(7);
	v3.push_back(6);
	v3.push_back(5);

	removeDuplicate(v3);

	for (auto &i : v3)
	{
		cout << i << endl;
	}

	std::string INPUT;
	std::getline(std::cin, INPUT);

	return 0;
}