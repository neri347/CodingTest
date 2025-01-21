/// 카드 구매하기
/// https://www.acmicpc.net/problem/11052
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> costs(N + 1, 0);
	for (int i = 0; i < N; ++i)
	{
		int val;
		cin >> val;
		costs[i + 1] = val;
	}

	vector<int> dp(N + 1, 0);
	dp[1] = costs[1];
	for (int i = 2; i <= N; ++i)
	{
		dp[i] = costs[i];
		for (int j = 1; j <= i / 2; ++j)
		{
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[N];

	return 0;
}