/// 구슬 탈출 2
/// https://www.acmicpc.net/problem/13460
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

struct Pos
{
	int x_red;
	int y_red;
	int x_blue;
	int y_blue;
	int count;
};

int main()
{
	int answer = 0;
	int N, M;
	cin >> N >> M;
	int board[10][10];
	bool isVisited[10][10][10][10] = { false };
	pair<int, int> redStart;
	pair<int, int> blueStart;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char ch;
			cin >> ch;
			board[i][j] = ch;
			if (ch == 'R')
			{
				redStart = { i, j };
				board[i][j] = '.';
			}
			else if (ch == 'B')
			{
				blueStart = { i, j };
				board[i][j] = '.';
			}
		}
	}

	queue<Pos> q;
	Pos pos = { redStart.first, redStart.second, blueStart.first, blueStart.second, 0 };
	q.push(pos);
	isVisited[redStart.first][redStart.second][blueStart.first][blueStart.second] = true;

	while (!q.empty())
	{
		int cx_red = q.front().x_red;
		int cy_red = q.front().y_red;
		int cx_blue = q.front().x_blue;
		int cy_blue = q.front().y_blue;
		int count = q.front().count;
		q.pop();

		// 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.
		if (count >= 10)
		{
			cout << -1;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			// 빨간 구슬 이동
			int nx_red = cx_red;
			int ny_red = cy_red;
			int moveCount_red = 0;
			while (board[nx_red + dx[i]][ny_red + dy[i]] != '#' && board[nx_red][ny_red] != 'O')
			{
				nx_red += dx[i];
				ny_red += dy[i];
				moveCount_red++;
			}

			// 파란 구슬 이동
			int nx_blue = cx_blue;
			int ny_blue = cy_blue;
			int moveCount_blue = 0;
			while (board[nx_blue + dx[i]][ny_blue + dy[i]] != '#' && board[nx_blue][ny_blue] != 'O')
			{
				nx_blue += dx[i];
				ny_blue += dy[i];
				moveCount_blue++;
			}

			// 파란 구슬 도착
			if (board[nx_blue][ny_blue] == 'O')
			{
				// 같은 count 이동 횟수에서 4방향 확인하고 있는데, 
				// 지금 방향으로 가면 파란 구슬이 도착할 수 있다 하더라도
				// 다른 방향으로 갔을 때 빨간 구슬이 도착할 수도 있기 때문에 continue한다.
				continue;
			}

			// 빨간 구슬 도착
			if (board[nx_red][ny_red] == 'O')
			{
				cout << count + 1;
				return 0;
			}

			// 구슬이 겹치면 더 이동한 쪽을 뒤로 이동
			if (nx_red == nx_blue && ny_red == ny_blue)
			{
				if (moveCount_red > moveCount_blue)
				{
					nx_red -= dx[i];
					ny_red -= dy[i];
				}
				else
				{
					nx_blue -= dx[i];
					ny_blue -= dy[i];
				}
			}

			if (!isVisited[nx_red][ny_red][nx_blue][ny_blue])
			{
				isVisited[nx_red][ny_red][nx_blue][ny_blue] = true;
				q.push({ nx_red, ny_red, nx_blue, ny_blue, count + 1 });
			}
		}
	}

	cout << -1;
	return 0;
}