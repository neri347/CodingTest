/// 백조의 호수
/// https://www.acmicpc.net/problem/3197
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int R, C;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
char board[1500][1500];
bool isVisited[1500][1500];
queue<pair<int, int>> swan_cur;
queue<pair<int, int>> swan_next;
queue<pair<int, int>> water;
queue<pair<int, int>> melted;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	pair<int, int> swan;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 'X')
			{
				water.push({ i, j });
			}
			if (board[i][j] == 'L')
			{
				swan = { i, j };
			}
		}
	}

	int answer = 0;
	swan_cur.push({ swan.first, swan.second });
	isVisited[swan.first][swan.second] = true;
	while (true)
	{
		// 백조가 만날 수 있는지 검사		
		while (!swan_cur.empty())
		{
			int x = swan_cur.front().first;
			int y = swan_cur.front().second;
			swan_cur.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && !isVisited[nx][ny])
				{
					isVisited[nx][ny] = true;
					if (board[nx][ny] == 'X')
					{
						swan_next.push({ nx, ny });
					}
					else
					{
						if (board[nx][ny] == 'L')
						{
							cout << answer;
							return 0;
						}
						else
						{
							swan_cur.push({ nx, ny });
						}
					}
				}
			}
		}
		swan_cur = swan_next;
		while (!swan_next.empty())
		{
			swan_next.pop();
		}

		// 빙판 녹이기		
		while (!water.empty())
		{
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && board[nx][ny] == 'X')
				{
					board[nx][ny] = '.';
					melted.push({ nx, ny });
				}
			}
		}
		water = melted;
		while (!melted.empty())
		{
			melted.pop();
		}

		++answer;
	}

	return 0;
}