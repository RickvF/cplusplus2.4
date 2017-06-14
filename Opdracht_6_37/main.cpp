#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

bool isValid(const string& cardNumber);
int sumOfDoubleEvenPlace(const string& cardNumber);
int getDigit(int number);
int sumOfOddPlace(const string& cardNumber);
bool startsWith(const string& cardNumber, const string& substr);

int main()
{
	string cardNumber;
	cout << "cardnumber: " << endl;
	std::getline(cin, cardNumber);

	bool valid = isValid(cardNumber);
	cout << "The cardnumber is valid " << valid << endl;

	std::getline(cin, cardNumber);
	cin.get();


	return 0;
}

bool isValid(const string& cardNumber)
{
	string starts = "45376";
	if (startsWith(cardNumber, starts))
	{
		int sumEven = sumOfDoubleEvenPlace(cardNumber);
		int sumOdd = sumOfOddPlace(cardNumber);

		int totalSum = sumEven + sumOdd;

		if (totalSum % 10 == 0)
		{
			cout << "return startwith true " << endl;
			return true;
		}
		else
		{
			cout << "return % false " << endl;
			return false;
		}

	}
	else
	{
		cout << "return startwith false " << endl;
		return false;
	}
}

int sumOfDoubleEvenPlace(const string& cardNumber)
{
	int lengte = cardNumber.size();
	int c = lengte - 2;
	int total = 0;

	for (int i = c; i >= 0; i-=2)
	{
		string character = cardNumber.substr(i, 1);
		int digit = atoi(character.c_str());
		total += getDigit(digit);
	}

	cout << "return Even total " << total << endl;

	return total;
}

int getDigit(int number)
{
	int newDigit = number * 2;
	if (newDigit > 9)
	{
		int f = newDigit / 10;
		int l = newDigit % 10;
		newDigit = f + l;
	}

	return newDigit;
}

int sumOfOddPlace(const string& cardNumber)
{
	int lengte = cardNumber.size();
	int c = lengte - 1;
	int total = 0;

	for (int i = c; i >= 0; i-=2)
	{
		string character = cardNumber.substr(i, 1);
		int digit = atoi(character.c_str());
		total += digit;
	}

	cout << "return Odd total " << total << endl;

	return total;
}

bool startsWith(const string& cardNumber, const string& substr)
{
	if (cardNumber.substr(0, 1) == substr.substr(0, 1))
	{
		return true;
	}
	else if (cardNumber.substr(0, 1) == substr.substr(1, 1))
	{
		return true;
	}
	else if (cardNumber.substr(0, 1) == substr.substr(2, 2))
	{
		return true;
	}
	else if (cardNumber.substr(0, 1) == substr.substr(3, 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

