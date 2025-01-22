/// 토마토
/// https://www.acmicpc.net/problem/7576
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[1000][1000];
bool isVisited[1000][1000];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

int main()
{
	int N, M;
	cin >> M >> N;

	int answer = 0;
	queue<pair<pair<int, int>, int>> q; // 익은 토마토 위치
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int num;
			cin >> num;
			map[i][j] = num;
			if (num == 1)
			{
				q.push({ { i, j }, answer });
				isVisited[i][j] = true;
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int count = q.front().second;
		answer = count;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0 && !isVisited[nx][ny])
			{
				isVisited[nx][ny] = true;
				map[nx][ny] = 1;
				q.push({ {nx, ny}, count + 1 });
			}
		}
	}

	bool flag = true; // 모든 토마토가 익었는지
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == 0)
			{
				flag = false;
				break;
			}
		}
	}

	flag ? cout << answer : cout << -1;

	return 0;
}