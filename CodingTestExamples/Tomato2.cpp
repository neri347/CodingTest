/// 토마토
/// https://www.acmicpc.net/problem/7569
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[100][100][100];
bool isVisited[100][100][100];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int dh[2] = { 1,-1 };

struct Pos
{
	int x;
	int y;
	int h;
	int second;
};

int main()
{
	int M, N, H;
	cin >> M >> N >> H;
	queue<Pos> q;
	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[h][i][j];
				if (map[h][i][j] == 1)
				{
					q.push({ i, j, h, 0 });
					isVisited[h][i][j] = true;
				}
			}
		}
	}

	int answer = 0;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int h = q.front().h;
		int s = q.front().second;
		q.pop();

		answer = s;

		// 위, 아래
		for (int i = 0; i < 2; i++)
		{
			int nh = h + dh[i];
			if (nh >= 0 && nh < H && !isVisited[nh][x][y] && map[nh][x][y] == 0)
			{
				isVisited[nh][x][y] = true;
				map[nh][x][y] = 1;
				q.push({ x, y, nh, s + 1 });
			}
		}

		// 상하좌우
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !isVisited[h][nx][ny] && map[h][nx][ny] == 0)
			{
				isVisited[h][nx][ny] = true;
				map[h][nx][ny] = 1;
				q.push({ nx, ny, h, s + 1 });
			}
		}
	}

	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[h][i][j] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << answer;
	return 0;
}