/// ���
/// https://www.acmicpc.net/problem/14501
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// �Է�
	int n;
	cin >> n;
	vector<vector<int>> schedules;
	for (int i = 0; i < n; ++i)
	{
		int t, p;
		cin >> t >> p;
		schedules.push_back({ t, p });
	}

	// Ǯ��
	vector<int> dp(n + 1, 0);
	for (int i = n - 1; i >= 0; --i)
	{
		int t = schedules[i][0];
		int p = schedules[i][1];
		if (i + t > n) // ��糯���� ����� ���� �� ���� ���
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			// ����� �ϴ� ��� dp[i] = dp[i+t] + p
			// ����� �� �ϴ� ��� dp[i] = dp[i + 1];
			dp[i] = max(dp[i + t] + p, dp[i + 1]);
		}
	}

	cout << dp[0];
	return 0;
}