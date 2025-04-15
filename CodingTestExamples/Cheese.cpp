/// 치즈
/// https://www.acmicpc.net/problem/2638
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int board[100][100];
bool isVisited[100][100];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
queue<pair<int, int>> air;
queue<pair<int, int>> cheese;
queue<pair<int, int>> deleted;

int main()
{
	int N, M;
	cin >> N >> M;
	int totalCheeseCnt = 0;
	int totalTime = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				totalCheeseCnt++;
			}
		}
	}

	air.push({ 0, 0 });
	board[0][0] = 2;
	isVisited[0][0] = true;

	while (totalCheeseCnt > 0)
	{
		++totalTime;
		// 외부공기 체크
		memset(isVisited, false, sizeof(isVisited));
		while (!air.empty())
		{
			int x = air.front().first;
			int y = air.front().second;
			air.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && !isVisited[nx][ny])
				{
					isVisited[nx][ny] = true;
					if (board[nx][ny] == 2)
					{
						continue;
					}
					if (board[nx][ny] == 1)
					{
						cheese.push({ nx, ny });
						continue;
					}
					board[nx][ny] = 2;
					air.push({ nx, ny });
				}
			}
		}

		while (!cheese.empty())
		{
			int x = cheese.front().first;
			int y = cheese.front().second;
			cheese.pop();

			int count = 0;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (board[nx][ny] == 2)
				{
					++count;
				}
			}

			if (count >= 2)
			{
				deleted.push({ x, y });
			}
		}

		while (!deleted.empty())
		{
			int x = deleted.front().first;
			int y = deleted.front().second;
			deleted.pop();

			board[x][y] = 2;
			air.push({ x, y });
			totalCheeseCnt--;
		}

	}
	cout << totalTime;
	return 0;
}