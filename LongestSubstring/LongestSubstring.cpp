// LongestSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	int n = s.length();
	int ans = 0;
	int index[128] = { 0 }; // current index of character
	// try to extend the range [i, j]
	for (int j = 0, i = 0; j < n; j++) 
	{
		int tmp = index[s[j]];
		i = max(index[s[j]], i);
		ans = max(ans, j - i + 1);
		index[s[j]] = j + 1;
	}
	return ans;
}

int _lengthOfLongestSubstring(string s)
{
	int pos{ 0 };

	if (1 == s.size()) return 1;

	string reminder = s.substr(1);
	int posPrev = lengthOfLongestSubstring(reminder);

	bool letters[26] = { false };
	for (int i = 0; i < 26; i++) letters[i] = false;

	bool found = false;
	int j = 0;
	while (!found && j < s.size() )
	{
		if (true == letters[s.at(j) - 97]) { found = true; pos = j;  continue; }
		letters[s.at(j) - 97] = true;
		j++;
	}
	if (!found) pos = j;
			

	return pos > posPrev ? pos : posPrev;
}

void testSubstring()
{
	int i = lengthOfLongestSubstring("abcabc");
}

int main()
{
	testSubstring();
    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
