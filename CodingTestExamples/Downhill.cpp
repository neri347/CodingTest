/// 내리막길
/// https://www.acmicpc.net/problem/1520
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int map[500][500];
int dp[500][500];

int DFS(int x, int y)
{
	if (dp[x][y] != -1)	return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[x][y] < map[nx][ny])
		{
			dp[x][y] += DFS(nx, ny);
		}
	}
	return dp[x][y];
}

int main()
{
	cin >> N >> M; // 세로, 가로
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int h;
			cin >> h;
			map[i][j] = h;
			dp[i][j] = -1;
		}
	}

	dp[0][0] = 1;
	cout << DFS(N - 1, M - 1);
	return 0;
}