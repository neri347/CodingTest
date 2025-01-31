/// 가장 긴 증가하는 부분 수열
/// https://www.acmicpc.net/problem/11055
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> nums;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}

	vector<int> dp(N, 0);
	dp[0] = nums[0];
	for (int i = 1; i < N; i++)
	{
		dp[i] = nums[i];
		for (int j = 0; j < i; j++)
		{
			if (dp[i] > dp[j])
			{
				dp[i] = max(dp[i], dp[j] + nums[i]);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}