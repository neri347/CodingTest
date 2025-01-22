/// ¹Ì·Î Å½»ö
/// https://www.acmicpc.net/problem/2178
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

int N, M;
int maze[100][100];
bool isVisited[100][100];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };
int answer;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{	
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0, 0 }, 1 });

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int count = q.front().second;
		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			answer = count;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] == 1 && !isVisited[nx][ny])
			{
				isVisited[nx][ny] = true;
				q.push({ {nx, ny}, count + 1 });
			}
		}
	}

	cout << answer;
	return 0;
}