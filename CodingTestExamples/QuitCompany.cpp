/// 퇴사
/// https://www.acmicpc.net/problem/14501
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<vector<int>> schedules;
	for (int i = 0; i < n; ++i)
	{
		int t, p;
		cin >> t >> p;
		schedules.push_back({ t, p });
	}

	// 풀이
	vector<int> dp(n + 1, 0);
	for (int i = n - 1; i >= 0; --i)
	{
		int t = schedules[i][0];
		int p = schedules[i][1];
		if (i + t > n) // 퇴사날까지 상담을 끝낼 수 없는 경우
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			// 상담을 하는 경우 dp[i] = dp[i+t] + p
			// 상담을 안 하는 경우 dp[i] = dp[i + 1];
			dp[i] = max(dp[i + t] + p, dp[i + 1]);
		}
	}

	cout << dp[0];
	return 0;
}