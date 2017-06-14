#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

bool isPalindrome(const std::string& s)
{

	std::cout << "string: " << s << std::endl;

	std::string reversedString(s);
	std::reverse(reversedString.begin(), reversedString.end());

	std::cout << "reserve: " << reversedString << std::endl;

	if (s == reversedString)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	std::string str;
	std::getline(std::cin, str);

	bool palindrome = isPalindrome(str);

	if (palindrome)
	{
		std::cout << str << " is a palindrome" << std::endl;
	}
	else
	{
		std::cout << str << " is a not palindrome" << std::endl;
	}

	std::string INPUT;
	std::getline(std::cin, INPUT);
	return 0;
}