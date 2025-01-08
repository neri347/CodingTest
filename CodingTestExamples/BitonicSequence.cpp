/// 가장 긴 바이토닉 부분 수열
/// https://www.acmicpc.net/problem/11054
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<int> numbers;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	vector<vector<int>> dp(2, vector<int>(n, 0));
	dp[0][0] = 1;
	dp[0][1] = 1;
	for (int i = 1; i < n; ++i)
	{
		if (numbers[i] < numbers[i - 1])
		{
			dp[i][1] = dp[i - 1][0] + 1;
		}
		else
		{
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1];
		}
	}

	return 0;
}