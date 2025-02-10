/// øÂΩ…¿Ô¿Ã ∆«¥Ÿ
/// https://www.acmicpc.net/problem/1937
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int map[500][500];
vector<vector<int>> dp;

int DFS(int x, int y)
{
	if (dp[x][y] != -1)	return dp[x][y];

	dp[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] > map[x][y])
		{
			dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
		}
	}
	return dp[x][y];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int v;
			cin >> v;
			map[i][j] = v;
		}
	}

	dp.assign(N, vector<int>(N, -1));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			DFS(i, j);
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer = max(answer, dp[i][j]);
		}
	}
	cout << answer;

	return 0;
}