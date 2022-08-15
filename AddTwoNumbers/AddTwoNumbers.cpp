// AddTwoNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Leetcode output:
// 2/09/2019
//Success
//Details
//Runtime : 20 ms, faster than 87.90 % of C++ online submissions for Add Two Numbers.
//Memory Usage : 10.4 MB, less than 57.71 % of C++ online submissions for Add Two Numbers.

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution {
public:


	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		if (nullptr == l1 || nullptr == l2) return nullptr;

		// add (copy) the first list
		ListNode* listOut{ nullptr };
		ListNode* listOutCurr{ nullptr };
		int carryOver = 0;
		while (l1 || l2)
		{
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;

			ListNode* tmp = new ListNode(0);
			int sum = val1 + val2 + carryOver;
			if (sum < 10)
			{
				tmp->val = sum;
				carryOver = 0;
			}
			else
			{
				tmp->val = sum % 10;
				carryOver = 1;
			}
			
			if (!listOut)
			{
				listOut = tmp;
				listOutCurr = tmp;
			}
			else
			{
				listOutCurr->next = tmp;
				listOutCurr = tmp;
			}

			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}

		// carry over handling
		if (1 == carryOver)
		{
			ListNode* tmp = new ListNode(1);
			listOutCurr->next = tmp;
		}

		return listOut;
	}

};

ListNode* createListFromVector(const vector<int>& v)
{
	ListNode* ptrRoot{ new ListNode(0) };
	ListNode* curr{ ptrRoot };
	for (int i : v)
	{
		curr->next = new ListNode(i);
		curr = curr->next;
	}
	curr = ptrRoot->next;
	delete ptrRoot;
	return curr;
}

void releaseList(ListNode* list)
{
	ListNode* curr = list;
	while (curr)
	{
		ListNode* tmp = curr;
		curr = curr->next;
		delete tmp;
	}
}

void printList(ListNode* list)
{
	std::cout << "printList:\n";
	ListNode* curr = list;
	while (curr)
	{
		std::cout << curr->val << " ";
		curr = curr->next;
	}

	std::cout << std::endl;
}

vector<int> createVectorFromList(ListNode* list)
{
	vector<int> res;
	while (list)
	{
		res.emplace_back(list->val);
		list = list->next;
	}

	return res;
}

void Test0Lists()
{
	vector<int> n1{ 0 };
	vector<int> n2{ 0 };
	vector<int> res{ 0 };

	ListNode* l1 = createListFromVector(n1);
	ListNode* l2 = createListFromVector(n2);

	ListNode* lOut = Solution::addTwoNumbers(l1, l2);
	vector<int> vOut = createVectorFromList(lOut);
	_ASSERT(res == vOut);
	releaseList(l1);
	releaseList(l2);
	releaseList(lOut);
}

void TestDefaultInput()
{
	vector<int> n1{ 2,4,3 };
	vector<int> n2{ 5,6,4 };
	vector<int> res{ 7,0,8 };
	ListNode* l1 = createListFromVector(n1);
	ListNode* l2 = createListFromVector(n2);

	ListNode* lOut = Solution::addTwoNumbers(l1, l2);
	vector<int> vOut = createVectorFromList(lOut);
	_ASSERT(res == vOut);

	releaseList(l1);
	releaseList(l2);
	releaseList(lOut);
}

void TestCarryOver1()
{
	vector<int> n1{ 9,9,9 };
	vector<int> n2{ 1 };
	vector<int> res{ 0,0,0,1 };
	ListNode* l1 = createListFromVector(n1);
	ListNode* l2 = createListFromVector(n2);

	ListNode* lOut = Solution::addTwoNumbers(l1, l2);
	vector<int> vOut = createVectorFromList(lOut);
	_ASSERT(res == vOut);

	releaseList(l1);
	releaseList(l2);
	releaseList(lOut);
}

void TestCarryOver2()
{
	vector<int> n1{ 1 };
	vector<int> n2{ 9,9,9,9 };
	
	vector<int> res{ 0,0,0,0,1 };
	ListNode* l1 = createListFromVector(n1);
	ListNode* l2 = createListFromVector(n2);

	ListNode* lOut = Solution::addTwoNumbers(l1, l2);
	vector<int> vOut = createVectorFromList(lOut);
	_ASSERT(res == vOut);

	releaseList(l1);
	releaseList(l2);
	releaseList(lOut);
}

void TestCarryOver3()
{
	vector<int> n1{ 5,5,5,5 };
	vector<int> n2{ 5,5,5,5 };

	vector<int> res{ 0,1,1,1,1 };
	ListNode* l1 = createListFromVector(n1);
	ListNode* l2 = createListFromVector(n2);

	ListNode* lOut = Solution::addTwoNumbers(l1, l2);
	vector<int> vOut = createVectorFromList(lOut);
	_ASSERT(res == vOut);

	releaseList(l1);
	releaseList(l2);
	releaseList(lOut);
}

int main()
{
	Test0Lists();
	TestDefaultInput();
	TestCarryOver1();
	TestCarryOver2();
	TestCarryOver3();
}

