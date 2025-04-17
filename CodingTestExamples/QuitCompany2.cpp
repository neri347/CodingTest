/// ��� 2
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
		if (i + time > N) // ��糯���� ����� ���� �� ���� ���
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			// ����� �ϰų�, �� �ϰų�
			// ����� �ϴ� ��� dp[i] = dp[i + t] + p
			// ����� �� �ϴ� ��� dp[i] = dp[i + 1]
			dp[i] = max(dp[i + 1], dp[i + time] + price);
		}
	}
	cout << dp[0];
	return 0;
}