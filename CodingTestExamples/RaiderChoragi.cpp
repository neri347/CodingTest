/// 습격자 초라기
/// https://www.acmicpc.net/problem/1006
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, W;

void GetDP(int start, const vector<vector<int>>& enemy, vector<vector<int>>& dp)
{
	for (int i = start; i <= N; i++)
	{
		dp[i + 1][2] = min(dp[i][0] + 1, dp[i][1] + 1);

		if (enemy[i][0] + enemy[i - 1][0] <= W && enemy[i][1] + enemy[i - 1][1] <= W)
		{
			dp[i + 1][2] = min(dp[i + 1][2], dp[i - 1][2] + 2);
		}

		if (enemy[i][0] + enemy[i][1] <= W)
		{
			dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + 1);
		}

		dp[i + 1][0] = dp[i + 1][2] + 1;
		dp[i + 1][1] = dp[i + 1][2] + 1;

		if (enemy[i][0] + enemy[i + 1][0] <= W)
		{
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 1);
		}

		if (enemy[i][1] + enemy[i + 1][1] <= W)
		{
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 1);
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> W;
		vector<vector<int>> enemy(N + 2, vector<int>(2, 0));
		for (int i = 1; i <= N; i++)
		{
			int num;
			cin >> num;
			enemy[i][0] = num;
		}

		for (int i = 1; i <= N; i++)
		{
			int num;
			cin >> num;
			enemy[i][1] = num;
		}


		int answer = 0;
		vector<vector<int>> dp(N + 2, vector<int>(3, 0));
		dp[1][0] = 1;
		dp[1][1] = 1;
		dp[1][2] = 0;

		GetDP(1, enemy, dp);
		answer = dp[N + 1][2];

		if (N > 2) // 원형 구조를 이룰 수 있을 때
		{
			// 1, N 행이 아랫줄에 걸침
			if (enemy[1][0] + enemy[N][0] <= W)
			{
				dp[2][0] = 2;
				dp[2][1] = enemy[1][1] + enemy[2][1] <= W ? 1 : 2;
				dp[2][2] = 1;
				GetDP(2, enemy, dp);
				answer = min(answer, dp[N][1] + 1);
			}
			// 1, N 행이 윗줄에 걸침
			if (enemy[1][1] + enemy[N][1] <= W)
			{
				dp[2][0] = enemy[1][0] + enemy[2][0] <= W ? 1 : 2;
				dp[2][1] = 2;
				dp[2][2] = 1;
				GetDP(2, enemy, dp);
				answer = min(answer, dp[N][0] + 1);
			}

			// 위, 아래 둘다 걸침 -> 2 부터 시작하는 원형 큐
			if (enemy[1][0] + enemy[N][0] <= W && enemy[1][1] + enemy[N][1] <= W)
			{
				dp[2][0] = 1;
				dp[2][1] = 1;
				dp[2][2] = 0;
				GetDP(2, enemy, dp);
				answer = min(answer, dp[N][2] + 2);
			}
		}

		cout << answer << "\n";
	}

	return 0;
}