/// 오르막 수
/// https://www.acmicpc.net/problem/11057
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> dp(N + 1, vector<int>(10, 0));
	for (int i = 0; i < 10; ++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			int sum = 0;
			for (int k = j; k <= 9; ++k)
			{
				sum += dp[i - 1][k];
			}
			dp[i][j] = sum % 10007;
		}
	}

	int ret = 0;
	for (int i = 0; i <= 9; ++i)
	{
		ret += dp[N][i];
	}
	cout << ret % 10007;

	return 0;
}