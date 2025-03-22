/// 평범한 배낭
/// https://www.acmicpc.net/problem/12865
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 입력
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> items; // weight, value
	for (int i = 0; i < N; i++)
	{
		int w, v;
		cin >> w >> v;
		items.push_back({ w, v });
	}

	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		int weight = items[i - 1].first;
		int value = items[i - 1].second;
		for (int j = 1; j <= K; j++)
		{
			if (weight <= j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K];
	return 0;
}