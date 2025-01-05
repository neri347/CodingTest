/// RGB 거리
/// https://www.acmicpc.net/problem/1149
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<vector<int>> costs;
	for (int i = 0; i < n; ++i)
	{
		int r, g, b;
		cin >> r >> g >> b;
		costs.push_back({ r, g, b });
	}

	// 풀이
	vector<vector<int>> dp(n + 1, vector<int>(3, 0));
	for (int i = 1; i <= n; ++i)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i-1][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i-1][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i-1][2];
	}

	cout << *min_element(dp[n].begin(), dp[n].end());

	return 0;
}