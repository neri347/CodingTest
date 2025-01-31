/// 파이프 옮기기
/// https://www.acmicpc.net/problem/17070
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> map(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			map[i][j] = num;
		}
	}

	// dp[i][j][0] 가로파이프, dp[i][j][1] 세로, dp[i][j][2] 대각선
	vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(3, 0)));
	// 맨 처음은 처음 파이프의 가로, 대각선 방향으로
	queue<pair<pair<int, int>, int>> q; // i,j,dir
	dp[0][1][0] = 1;
	q.push({ {0, 1}, 0 });

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		// 현재 파이프 방향 따라 파이프 옮기기
		if (dir == 0) // 가로 -> 가로 / 대각선
		{
			if (y + 1 < N && map[x][y + 1] != 1)
			{
				dp[x][y + 1][0] = dp[x][y][0] + dp[x][y][2];
				q.push({ {x, y + 1}, 0 });
			}

			if (x + 1 < N && y + 1 < N && map[x + 1][y + 1] != 1 && map[x + 1][y] != 1 && map[x][y + 1] != 1)
			{
				dp[x + 1][y + 1][2] = dp[x][y][0] + dp[x][y][1] + dp[x][y][2];
				q.push({ {x + 1, y + 1}, 2 });
			}
		}
		else if (dir == 1) // 세로 -> 세로 / 대각선
		{
			if (x + 1 < N && map[x + 1][y] != 1)
			{
				dp[x + 1][y][1] = dp[x][y][1] + dp[x][y][2];
				q.push({ {x + 1, y}, 1 });
			}

			if (x + 1 < N && y + 1 < N && map[x + 1][y + 1] != 1 && map[x + 1][y] != 1 && map[x][y + 1] != 1)
			{
				dp[x + 1][y + 1][2]  = dp[x][y][0] + dp[x][y][1] + dp[x][y][2];
				q.push({ {x + 1, y + 1}, 2 });
			}
		}
		else // 대각선 -> 가로, 세로, 대각선
		{
			if (y + 1 < N && map[x][y + 1] != 1)
			{
				dp[x][y + 1][0] = dp[x][y][0] + dp[x][y][2];
				q.push({ {x, y + 1}, 0 });
			}

			if (x + 1 < N && map[x + 1][y] != 1)
			{
				dp[x + 1][y][1] = dp[x][y][1] + dp[x][y][2];
				q.push({ {x + 1, y}, 1 });
			}

			if (x + 1 < N && y + 1 < N && map[x + 1][y + 1] != 1 && map[x + 1][y] != 1 && map[x][y + 1] != 1)
			{
				dp[x + 1][y + 1][2] = dp[x][y][0] + dp[x][y][1] + dp[x][y][2];
				q.push({ {x + 1, y + 1}, 2 });
			}
		}
	}
	cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];

	return 0;
}