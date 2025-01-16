/// ÇÕºÐÇØ
/// https://www.acmicpc.net/problem/2225
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int mod = 1000000000;
	int N, K;
	cin >> N >> K;

	vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
	for (int i = 0; i <= N; ++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= K; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			long long sum = 0;
			for (int k = 0; k <= j; ++k)
			{
				sum += dp[i - 1][k];
			}
			dp[i][j] = sum % mod;
		}
	}
	cout << dp[K][N] % mod;
	return 0;
}