/// 퇴사 2
/// https://www.acmicpc.net/problem/15486
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> schedules;
	for (int i = 0; i < N; i++)
	{
		int time, price;
		cin >> time >> price;
		schedules.push_back({ time, price });
	}

	vector<int> dp(N + 1, 0);
	for (int i = N - 1; i >= 0; i--)
	{
		int time = schedules[i].first;
		int price = schedules[i].second;
		if (i + time > N) // 퇴사날까지 상담을 끝낼 수 없는 경우
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			// 상담을 하거나, 안 하거나
			// 상담을 하는 경우 dp[i] = dp[i + t] + p
			// 상담을 안 하는 경우 dp[i] = dp[i + 1]
			dp[i] = max(dp[i + 1], dp[i + time] + price);
		}
	}
	cout << dp[0];
	return 0;
}