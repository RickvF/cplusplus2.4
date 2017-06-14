#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

std::vector<std::string> endTags;
std::string startTag = "ATG";

std::vector<int> startPositions;
std::vector<int> endPositions;

int currentPosition = 0;

void addEndTags()
{
	endTags.push_back("TAG");
	endTags.push_back("TAA");
	endTags.push_back("TGA");
}

int main()
{

	addEndTags();
	std::string inputGenome;
	std::getline(std::cin, inputGenome);

	while (currentPosition < inputGenome.length())
	{
		int position = inputGenome.find(startTag, currentPosition);
		if (std::find(startPositions.begin(), startPositions.end(), position) != startPositions.end()) {
			/* v contains x */
		}
		else {
			startPositions.push_back(position);
		}
		
		currentPosition++;
	}

	currentPosition = 0;

	while (currentPosition < inputGenome.length())
	{
		for (auto s : endTags)
		{
			int position = inputGenome.find(s, currentPosition);
			if (std::find(endPositions.begin(), endPositions.end(), position) != endPositions.end()) {
				/* v contains x */
			}
			else {
				endPositions.push_back(position);
			}
		}

		currentPosition++;
	}

	std::sort(startPositions.begin(), startPositions.begin() + startPositions.size());
	std::sort(endPositions.begin(), endPositions.begin() + endPositions.size());
	

	for (int i = 0; i < startPositions.size(); i++)
	{
		int eind = 0;
		int begin = startPositions.at(i);
		if (begin > 0)
		{
			if (endPositions.size() > i)
			{
				eind = endPositions.at(i);
				int volgendBegin = 100;
				if (startPositions.size() > i + 1)
					volgendBegin = startPositions.at(i + 1);

				if (eind > volgendBegin && volgendBegin > 0)
				{
					eind = 0;
				}
			}

			if (eind != 0)
				std::cout << inputGenome.substr(begin+3, ((eind-begin)-3)) << std::endl;
		}
	}

	std::string INPUT;
	std::getline(std::cin, INPUT);
	return 0;
}