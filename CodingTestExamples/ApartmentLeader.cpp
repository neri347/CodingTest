/// 부녀회장이 될테야
/// https://www.acmicpc.net/problem/2775
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 입력
	int T;
	cin >> T;
	vector<pair<int, int>> testcase; // k, n
	for (int i = 0; i < T; ++i)
	{
		int k, n;
		cin >> k >> n;
		testcase.push_back({ k, n });
	}

	// 풀이
	vector<vector<int>> dp(15, vector<int>(15, 0));
	vector<int> sums(15, 0);
	// 0층
	for (int i = 1; i < 15; ++i)
	{
		dp[0][i] = i;
		sums[i] = i + sums[i - 1];
	}

	// 1층~
	for (int i = 1; i < 15; ++i)
	{
		for (int j = 1; j < 15; ++j)
		{
			dp[i][j] = sums[j];
			sums[j] = sums[j - 1] + dp[i][j];
		}
	}

	for (const auto& [k, n] : testcase)
	{
		cout << dp[k][n] << "\n";
	}

	return 0;
}