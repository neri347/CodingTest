/// �̳׶�
/// https://www.acmicpc.net/problem/2933
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

int R, C;
char board[101][101];
bool isVisited[101][101];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
vector<pair<int, int>> floatingMinerals;

void BreakMineral(int r, int turn)
{
	if (turn % 2 == 0) // ���ʿ��� ������
	{
		int c = 1;
		while (c <= C)
		{
			if (board[r][c] == 'x')
			{
				board[r][c] = '.';
				break;
			}
			c++;
		}
	}
	else // �����ʿ��� ������
	{
		int c = C;
		while (c > 0)
		{
			if (board[r][c] == 'x')
			{
				board[r][c] = '.';
				break;
			}
			c--;
		}
	}
}

void BFS(int r, int c)
{
	queue<pair<int, int>> q;
	q.push({ r, c });
	isVisited[r][c] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= R && ny >= 1 && ny <= C && !isVisited[nx][ny] && board[nx][ny] == 'x')
			{
				isVisited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

void FindFloatingMinerals()
{
	memset(isVisited, false, sizeof(isVisited));
	floatingMinerals.clear();
	// �ٴڿ� �ִ� �̳׶����� Ž��
	for (int i = 1; i <= C; i++)
	{
		if (board[R][i] == 'x' && !isVisited[R][i])
		{
			BFS(R, i);
		}
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (!isVisited[i][j] && board[i][j] == 'x')
			{
				floatingMinerals.push_back({ i, j });
			}
		}
	}
}

int GetHeight(int x, int y)
{
	int ret = 0;
	for (int i = x + 1; i <= R; i++)
	{
		if (board[i][y] == 'x')
		{
			if (!isVisited[i][y])
			{
				// �̹� ������ �̳׶� ������ ����
				return INT_MAX;
			}
			else
			{
				// �ٸ� Ŭ�����Ϳ� �´���
				return ret;
			}
		}
		else
		{
			ret++;
		}
	}
	return ret;
}

void LandingCluster()
{
	// ������ ���� ���ϱ�
	int minHeight = INT_MAX;
	for (auto& [x, y] : floatingMinerals)
	{
		minHeight = min(minHeight, GetHeight(x, y));
	}

	// ���� �ִ� �ڸ� '.'�� �ٲ��ֱ�
	for (auto& [x, y] : floatingMinerals)
	{
		board[x][y] = '.';
	}

	// �̳׶��� ���̸�ŭ ������
	for (auto& [x, y] : floatingMinerals)
	{
		board[x + minHeight][y] = 'x';
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> board[i][j];
		}
	}

	int N;
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		int h;
		cin >> h;
		// �̳׶� �μ���
		BreakMineral(R - h + 1, n);
		// ���߿� ���ִ� Ŭ������ ã��
		FindFloatingMinerals();
		// Ŭ������ ������
		LandingCluster();
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}