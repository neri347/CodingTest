/// 안전 영역
/// https://www.acmicpc.net/problem/2468
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int board[100][100];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,-1,1,0 };

int main()
{
	int N;
	cin >> N;
	int minHeight = 101;
	int maxHeight = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			minHeight = min(minHeight, board[i][j]);
			maxHeight = max(maxHeight, board[i][j]);
		}
	}

	int answer = 0;
	for (int h = 0; h <= maxHeight; h++)
	{
		vector<vector<bool>> isVisited(N, vector<bool>(N, false));
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!isVisited[i][j] && board[i][j] > h)
				{
					count++;
					queue<pair<int, int>> q;
					q.push({ i, j });
					isVisited[i][j] = true;
					while (!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx >= 0 && nx < N && ny >= 0 && ny < N && !isVisited[nx][ny] && board[nx][ny] > h)
							{
								q.push({ nx, ny });
								isVisited[nx][ny] = true;
							}
						}
					}
				}
			}
		}
		answer = max(answer, count);
	}
	cout << answer;
	return 0;
}