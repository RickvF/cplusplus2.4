#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

void search(string& s, char& key);
	
int main()
{
	string word;
	char key;

	cout << "word: " << endl;
	std::getline(cin, word);
	cout << "key: " << endl;
	cin >> key;

	search(word, key);

	std::getline(cin, word);
	cin.get();


	return 0;
}

void search(string& s, char& key)
{
	if (s.find(key) != string::npos)
	{
		cout << "Key: " << key << " found " << endl;
	}
	else
	{
		cout << "Key: " << key << " not found " << endl;
	}
}

