/// 쉬운 계단 수
/// https://www.acmicpc.net/problem/10844
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	long long mod = 1000000000;
	vector<vector<int>> dp(n + 1, vector<int>(10, 0));

	for (int i = 1; i <= 9; ++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][1] % mod;
			}
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][8] % mod;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
			}
		}
	}

	long long ret = 0;
	for (int i = 0; i <= 9; ++i)
	{
		ret += dp[n][i];
	}
	cout << ret % mod;

	return 0;
}