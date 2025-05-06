/// ¾Û
/// https://www.acmicpc.net/problem/7579
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> memories;
	vector<int> costs;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		memories.push_back(v);
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		costs.push_back(v);
		sum += v;
	}

	vector<vector<int>> dp(N + 1, vector<int>(sum + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		int m = memories[i - 1];
		int c = costs[i - 1];

		for (int j = 0; j <= sum; j++)
		{
			if (j >= c)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c] + m);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int j = 0; j <= sum; j++)
	{
		if (dp[N][j] >= M)
		{
			cout << j;
			break;
		}
	}

	return 0;
}