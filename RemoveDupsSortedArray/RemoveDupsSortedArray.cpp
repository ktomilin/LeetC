// RemoveDupsSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	if (0 == nums.size()) return 0;

	int currPos{ 0 };

	for (int cmpPos = 1; cmpPos < nums.size(); cmpPos++)
	{
		if (nums[cmpPos] != nums[currPos])
		{
			currPos++;
			nums[currPos] = nums[cmpPos];
		}
	}

	return currPos + 1;
}


int removeDuplicates1(vector<int>& nums)
{
	if (0 == nums.size()) return 0;

	int currPos{ 0 };
	int cmpPos{ 1 };
	int newSize{ 1 };

	while (cmpPos < nums.size())
	{
		if (nums[currPos] == nums[cmpPos])
		{
			cmpPos++;
		}
		else
		{
			if (cmpPos - currPos > 1) nums[currPos + 1] = nums[cmpPos];
			currPos++;
			cmpPos++;
			newSize++;
		}
	}

	return newSize;
}

void TestRemoveDups()
{
	auto printVector = [](vector<int> vec, int size)
	{
		for (int i = 0; i < size; i++) std::cout << vec[i] << " ";
		std::cout << endl;
	};

	std::cout << "Test 2" << endl;
	vector<int> vec1{ 1, 1, 2 };
	vector<int> vec1Test{ 1, 2 };
	printVector(vec1, vec1.size());
	int newSize = removeDuplicates(vec1);
	printVector(vec1, newSize);
	vec1.resize(newSize);
	_ASSERT(vec1 == vec1Test);

	std::cout << "Test 2" << endl;
	vector<int> vec2{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	vector<int> vec2Test{ 0, 1, 2, 3, 4 };
	printVector(vec2, vec2.size());
	newSize = removeDuplicates(vec2);
	printVector(vec2, newSize);
	vec2.resize(newSize);
	_ASSERT(vec2 == vec2Test);

	std::cout << "Test 3" << endl;
	vector<int> vec3{ 1, 1, 1, 1, 1 };
	vector<int> vec3Test{ 1 };
	printVector(vec3, vec3.size());
	newSize = removeDuplicates(vec3);
	printVector(vec3, newSize);
	vec3.resize(newSize);
	_ASSERT(vec3 == vec3Test);

	std::cout << "Test 4" << endl;
	vector<int> vec4{ 1, 3, 5, 7, 9 };
	vector<int> vec4Test{ 1, 3, 5, 7, 9 };
	printVector(vec4, vec4.size());
	newSize = removeDuplicates(vec4);
	printVector(vec4, newSize);
	vec4.resize(newSize);
	_ASSERT(vec4 == vec4Test);
}

int main()
{
	TestRemoveDups();
}

