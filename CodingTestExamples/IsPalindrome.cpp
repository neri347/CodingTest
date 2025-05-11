/// ÆÓ¸°µå·Ò
/// https://www.acmicpc.net/problem/10942
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> nums(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}

	vector<vector<bool>> dp(N + 1, vector<bool>(N + 1, false));
	for (int i = 1; i <= N; i++)
	{
		dp[i][i] = true;
	}
	for (int i = 1; i <= N - 1; i++)
	{
		if (nums[i] == nums[i + 1])
		{
			dp[i][i + 1] = true;
		}
	}
	for (int i = N - 2; i >= 1; i--)
	{
		for (int j = i + 2; j <= N; j++)
		{
			if (nums[i] == nums[j] && dp[i + 1][j - 1])
			{
				dp[i][j] = true;
			}
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		cout << dp[S][E] << '\n';
	}

	return 0;
}