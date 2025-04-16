/// ���ο� ����
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

// 0 : ��, 1 : ��, 2 : ��, 3 : ��
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
	// �̵� ���� �ݴ�� �ٲ۴�.
	dir = ReverseDir(dir);
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	// �̵� ������ �ݴ�� �� �Ŀ��� �� ĭ �̵��Ѵ�. 
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
		// ������ �ݴ�� �� �Ŀ� �̵��Ϸ��� ĭ�� �Ķ����� ��쿡�� �̵����� �ʰ� ���⸸ �ݴ�� �ٲ۴�.
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

			// ���� �Ʒ��� �ִ� ���� �̵��� �� �ִ�.
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