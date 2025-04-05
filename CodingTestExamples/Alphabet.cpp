/// ¾ËÆÄºª
/// https://www.acmicpc.net/problem/1987
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
int answer;
char board[20][20];
bool isVisited[26];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

void DFS(int x, int y, int count)
{
	answer = max(answer, count);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C)
		{
			char nc = board[nx][ny];
			if (!isVisited[nc - 'A'])
			{
				isVisited[nc - 'A'] = true;
				DFS(nx, ny, count + 1);
				isVisited[nc - 'A'] = false;
			}
		}
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}

	char ch = board[0][0];
	isVisited[ch - 'A'] = true;
	DFS(0, 0, 1);
	cout << answer;
	return 0;
}