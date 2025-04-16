/// House Robber
/// https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int sz = nums.size();
		vector<int> dp(sz, 0);
		if (sz == 1)
		{
			return nums[0];
		}

		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < sz; i++)
		{
			dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
		}
		return dp[sz - 1];
	}
};

int main()
{

	return 0;
}