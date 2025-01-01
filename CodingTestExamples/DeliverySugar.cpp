/// ���� ���
/// https://www.acmicpc.net/problem/2839
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[5001];

int main()
{
	int n;
	cin >> n;
	
	dp[3] = dp[5] = 1;

	// 5 ������ 6���� ��ȸ
	for (int i = 6; i <= n; ++i)
	{
		// 3�� ������ -> ���� ���� 3�� ���� �� dp�� ���� ���� ���̴�.
		if (dp[i - 3])
		{
			dp[i] = dp[i - 3] + 1;
		}

		// 5�� ������ -> ���� ���� 5�� ���� �� dp�� ���� ���� ���̴�.
		// 3�� 5 �����? -> dp[i-3]������Ʈ �� ���� ���ŵǾ��� ��
		if (dp[i - 5])
		{
			dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
		}
	}
	cout << (dp[n] == 0 ? -1 : dp[n]);
	
	return 0;
}