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

	vector<int> dp1(N, 1);
	vector<int> dp2(N, 1);

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
			if (nums[N - 1 - j] < nums[N - 1 - i])
			{
				dp2[N - 1 - i] = max(dp2[N - 1 - i], dp2[N - 1 - j] + 1);
			}
		}
	}

	int answer = dp1[0] + dp2[0];
	for (int i = 1; i < N; i++)
	{
		answer = max(answer, dp1[i] + dp2[i]);
	}
	cout << answer - 1;

	return 0;
}