#include "StopWatch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main()
{
	StopWatch stopwatch;
	stopwatch.start();

	int myints[100000];
	for (int i = 0; i < 100000; i++)
	{
		myints[i] = (int)i / 10;
	}

	std::sort(myints, myints + 100000);

	/*cout << "Sorted Array looks like this." << endl;
	for (size_t i = 0; i != 100000; ++i)
		cout << myints[i] << " ";*/

	stopwatch.stop();

	cout << "elapsed time: " << stopwatch.getElapsedTime() << " milliseconds" << endl;


	string input;
	std::getline(cin, input);
	return 0;
}