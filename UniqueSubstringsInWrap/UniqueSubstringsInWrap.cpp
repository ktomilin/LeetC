// UniqueSubstringsInWrap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std; 

class Solution {
public:
	int findSubstringInWraproundString(string p) {
		int len = p.length();
		if (len == 0) return 0;
		if (len == 1) return 1;
		vector<int> dp(len);
		vector<int> res(26, 0);
		dp[0] = 1;
		res[p[0] - 'a'] = 1;
		for (int i = 1; i < len; i++) {
			if (p[i] == p[i - 1] + 1 || (p[i] == 'a' && p[i - 1] == 'z')) {
				dp[i] = dp[i - 1] + 1;
				res[p[i] - 'a'] = max(res[p[i] - 'a'], dp[i]);
			}
			else {
				res[p[i] - 'a'] = max(res[p[i] - 'a'], 1);
				dp[i] = 1;
			}
		}
		int cnt = 0;
		for (int num : res) {
			cnt += num;
		}
		return cnt;
	}
};

void testSubstrings()
{
	Solution sol;
	int res = sol.findSubstringInWraproundString("bc");
}


int main()
{
	testSubstrings();
}

