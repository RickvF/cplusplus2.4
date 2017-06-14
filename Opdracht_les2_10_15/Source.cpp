#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cstdlib>
#include <ctime>

using namespace std;

string words[] = { "time", "cup", "monkey", "lion", "tyfoon", "game" };
bool play = true;

void playHangman()
{
	srand(time(NULL));
	int word = rand() % (words->size()*2);
	if (word > 5)
		word = 5;
	int missed = 0;

	string wordToShow;
	for (int i = 0; i < words[word].length(); i++)
	{
		wordToShow += "*";
	}

	while (wordToShow != words[word])
	{
		cout << endl;
		cout << "Enter a letter in word " << wordToShow << " > " << endl;
		string str;
		getline(cin, str);

		if (str.size() < 2)
		{
			vector<int> positions;
			int currentPosition = 0;
			if (words[word].find(str) != std::string::npos)
			{
				if (wordToShow.find(str) != std::string::npos)
				{
					cout << str << " is already in the word" << endl;
				}
				else
				{
					/* word contains str */
					while (currentPosition < words[word].length())
					{
						int position = words[word].find(str, currentPosition);
						if (position != string::npos)
						{
							positions.push_back(position);
							currentPosition = position + 1;
						}
						else
						{
							currentPosition++;
						}
					}

					for (int i = 0; i < positions.size(); i++)
					{
						wordToShow.replace(positions.at(i), 1, str);
					}
				}

			}
			else
			{
				cout << str << " is not in the word" << endl;
				missed++;
			}
		}
		else
		{
			cout << "Do not enter more than 1 character" << endl;
		}
	}

	cout << "The word is " << wordToShow << ". You missed " << missed << " time" << endl;
}


int main()
{
	
	while (play)
	{
		playHangman();
		cout << endl;
		cout << "Do you want to guess for another word? Enter Y or N" << endl;

		string INPUT;
		getline(cin, INPUT);
		if (INPUT == "Y")
		{
			play = true;
		}
		else
		{
			play = false;
		}
	}

	string INPUT2;
	getline(cin, INPUT2
	);
	return 0;
}