/// 가장 긴 바이토닉 부분 수열
/// https://www.acmicpc.net/problem/11054
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

	vector<int> dp1(N, 0);
	dp1[0] = 1;

	for (int i = 1; i < N; i++)
	{
		dp1[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}

	vector<int> dp2(N, 0);
	dp2[N - 1] = 1;
	for (int i = N - 2; i >= 0; i--)
	{
		dp2[i] = 1;
		for (int j = N - 1; j > i; j--)
		{
			if (nums[j] < nums[i])
			{
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}

	int maxLen = 0;
	for (int i = 0; i < N; i++)
	{
		maxLen = max(maxLen, dp1[i] + dp2[i]);
	}

	cout << maxLen - 1;
	return 0;
}