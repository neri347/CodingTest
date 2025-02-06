/// 적록색약
/// https://www.acmicpc.net/problem/10026
#include <iostream>
#include <vector>
using namespace std;

int N;
char board[100][100];
bool isVisited[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void DFSNormal(int x, int y, char ch)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !isVisited[nx][ny] && board[nx][ny] == ch)
		{
			isVisited[nx][ny] = true;
			DFSNormal(nx, ny, ch);
		}
	}
}

void DFSBlindness(int x, int y, char ch)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !isVisited[nx][ny])
		{
			// 빨간색 구역 = 초록색 구역
			if (ch == 'R' || ch == 'G')
			{
				if (board[nx][ny] == 'R' || board[nx][ny] == 'G')
				{
					isVisited[nx][ny] = true;
					DFSBlindness(nx, ny, ch);
				}
			}
			else
			{
				if (board[nx][ny] == ch)
				{
					isVisited[nx][ny] = true;
					DFSBlindness(nx, ny, ch);
				}
			}
		}
	}
}

int CountForNormal()
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!isVisited[i][j])
			{
				++count;
				isVisited[i][j] = true;
				DFSNormal(i, j, board[i][j]);
			}
		}
	}
	return count;
}

int CountForBlindness()
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			isVisited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!isVisited[i][j])
			{
				++count;
				isVisited[i][j] = true;
				DFSBlindness(i, j, board[i][j]);
			}
		}
	}
	return count;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c;
		}
	}

	cout << CountForNormal() << " " << CountForBlindness();
	return 0;
}