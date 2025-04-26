/// 미네랄
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
	if (turn % 2 == 0) // 왼쪽에서 던지기
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
	else // 오른쪽에서 던지기
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
	// 바닥에 있는 미네랄부터 탐색
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
				// 이미 움직일 미네랄 있으니 종료
				return INT_MAX;
			}
			else
			{
				// 다른 클러스터와 맞닿음
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
	// 움직일 높이 구하기
	int minHeight = INT_MAX;
	for (auto& [x, y] : floatingMinerals)
	{
		minHeight = min(minHeight, GetHeight(x, y));
	}

	// 원래 있던 자리 '.'로 바꿔주기
	for (auto& [x, y] : floatingMinerals)
	{
		board[x][y] = '.';
	}

	// 미네랄들 높이만큼 내리기
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
		// 미네랄 부수기
		BreakMineral(R - h + 1, n);
		// 공중에 떠있는 클러스터 찾기
		FindFloatingMinerals();
		// 클러스터 떨구기
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