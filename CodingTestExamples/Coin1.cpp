/// µ¿Àü 1
/// https://www.acmicpc.net/problem/2293
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> coins;
	for (int i = 0; i < n; ++i)
	{
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}

	vector<int> dp(k + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = coins[i]; j <= k; ++j)
		{
			dp[j] += dp[j - coins[i]];
		}
	}

	cout << dp[k];

	return 0;
}