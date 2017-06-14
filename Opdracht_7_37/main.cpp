#include <iostream>
#include <string>
#include <locale> 

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::locale;

void count(const char s[], int counts[]);

const int SIZE = 50;

int main()
{
	string word;
	char lowercaseWord[SIZE];
	locale loc;
	int counts[26] = { 0 };

	cout << "Word: " << endl;
	std::getline(cin, word);

	int i = 0;
	for (auto elem : word)
	{
		lowercaseWord[i] = std::tolower(elem, loc);
		i++;
	}

	count(lowercaseWord, counts);


	std::getline(cin, word);
	cin.get();


	return 0;
}

void count(const char s[], int counts[])
{
	for (int i = 0; i < SIZE; i++)
	{
		int position = (s[i] - 97);
		if (position > -1 && position < 26)
		{
			int getal = counts[position];
			getal++;
			counts[position] = getal;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		int getal = counts[i];
		if (getal > 0)
		{
			char letter = (i + 97);
			cout << letter << ": " << getal << endl;
		}
	}
}

