/// 새로운 게임
/// https://www.acmicpc.net/problem/17780
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Horse
{
	int x;
	int y;
	int dir;
};

// 0 : 우, 1 : 좌, 2 : 상, 3 : 하
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int N, K;
int board[12][12];
deque<int> dq[12][12];
Horse horses[10];

bool CheckGameEnd()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dq[i][j].size() >= 4)
			{
				return true;
			}
		}
	}
	return false;
}

int ReverseDir(int dir)
{
	if (dir == 0)
	{
		return 1;
	}
	else if (dir == 1)
	{
		return 0;
	}
	else if (dir == 2)
	{
		return 3;
	}
	else
	{
		return 2;
	}
}

void White(int x, int y, int nx, int ny)
{
	while (!dq[x][y].empty())
	{
		int t = dq[x][y].front();
		dq[x][y].pop_front();
		dq[nx][ny].push_back(t);
		horses[t].x = nx;
		horses[t].y = ny;
	}
}

void Red(int x, int y, int nx, int ny)
{
	while (!dq[x][y].empty())
	{
		int t = dq[x][y].back();
		dq[x][y].pop_back();
		dq[nx][ny].push_back(t);
		horses[t].x = nx;
		horses[t].y = ny;
	}
}

void Blue(int x, int y, int& dir)
{
	// 이동 방향 반대로 바꾼다.
	dir = ReverseDir(dir);
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	// 이동 방향을 반대로 한 후에는 한 칸 이동한다. 
	if (nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] != 2)
	{
		if (board[nx][ny] == 0)
		{
			White(x, y, nx, ny);
		}
		else
		{
			Red(x, y, nx, ny);
		}
	}
	else
	{
		// 방향을 반대로 한 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 방향만 반대로 바꾼다.
		dir = ReverseDir(dir);
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int r, c, dir;
		cin >> r >> c >> dir;
		horses[i] = { r - 1, c - 1, dir - 1, };
		dq[r - 1][c - 1].push_back(i);
	}

	for (int t = 0; t <= 1000; t++)
	{
		if (CheckGameEnd())
		{
			cout << t;
			return 0;
		}

		for (int i = 0; i < K; i++)
		{
			Horse& h = horses[i];
			int x = h.x;
			int y = h.y;
			int dir = h.dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 가장 아래에 있는 말만 이동할 수 있다.
			if (dq[x][y].front() != i)
			{
				continue;
			}

			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				if (board[nx][ny] == 0)
				{
					White(x, y, nx, ny);
				}
				else if (board[nx][ny] == 1)
				{
					Red(x, y, nx, ny);
				}
				else
				{
					Blue(x, y, h.dir);
				}
			}
			else
			{
				Blue(x, y, h.dir);
			}
		}
	}
	cout << -1;
	return 0;
}