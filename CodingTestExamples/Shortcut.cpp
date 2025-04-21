/// Áö¸§±æ
/// https://www.acmicpc.net/problem/1446
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 999999999;
int dp[10001];
vector<pair<int, int>> roads[10001];

int main()
{
	int N, D;
	cin >> N >> D;

	for (int i = 0; i < N; i++)
	{
		int from, to, len;
		cin >> from >> to >> len;
		roads[to].push_back({ from, len });
	}

	for (int i = 1; i <= 10000; i++)
	{
		dp[i] = MAX;
	}

	for (int i = 1; i <= D; i++)
	{
		if (roads[i].size() == 0)
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			for (auto& p : roads[i])
			{
				int from = p.first;
				int len = p.second;
				dp[i] = min({ dp[i], dp[from] + len, dp[i - 1] + 1 });
			}
		}
	}
	cout << dp[D];
	return 0;
}