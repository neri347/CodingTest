/// ���� 2
/// https://www.acmicpc.net/problem/2294
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
	// �Է�
	int n, k;
	cin >> n >> k;
	vector<int> coins;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		coins.push_back(v);
	}

	// Ǯ��
	vector<int> dp(k + 1, 100000);
	dp[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = coins[i]; j <= k; ++j)
		{
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}

	int ret = (dp[k] == 100000) ? -1 : dp[k];
	cout << ret;
	return 0;
}