/// 미세먼지 안녕!
/// https://www.acmicpc.net/problem/17144
#include <iostream>
#include <vector>
using namespace std;

int map[50][50];
int origin[50][50];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };
vector<int> machine; //[0] 위의 줄, [1] 아랫줄

int main()
{
	int R, C, T;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int v;
			cin >> v;
			map[i][j] = v;
			if (v == -1)
			{
				machine.push_back(i);
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				origin[i][j] = map[i][j];
				if (map[i][j] == -1)
				{
					map[i][j] = -1;
				}
				else
				{
					map[i][j] = 0;
				}
			}
		}
		// 확산
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (origin[i][j] > 0)
				{
					// 네 방향으로 확산
					int value = origin[i][j] / 5;
					int sum = 0;
					for (int k = 0; k < 4; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx >= 0 && nx < R && ny >= 0 && ny < C && origin[nx][ny] != -1)
						{
							map[nx][ny] += value;
							sum += value;
						}
					}
					map[i][j] += origin[i][j] - sum;
				}
			}
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				origin[i][j] = map[i][j];
			}
		}

		// 작동
		// 0번째 줄 = 왼쪽으로
		// 왼쪽 끝 줄 아래로
		for (int i = 1; i < machine[0]; i++)
		{
			map[i][0] = origin[i-1][0];
		}
		
		// 윗줄 왼쪽으로
		for (int i = 0; i < C - 1; i++)
		{
			map[0][i] = origin[0][i + 1];
		}
		
		// 오른쪽 끝 줄 위로
		for (int i = 0; i < machine[0]; i++)
		{
			map[i][C - 1] = origin[i + 1][C - 1];
		}
		
		// machine[0]번째 줄 = 오른쪽으로
		for (int i = 2; i < C; i++)
		{
			map[machine[0]][i] = origin[machine[0]][i - 1];
		}
		map[machine[0]][1] = 0;
		// machine[1]번째 줄 = 오른쪽으로
		for (int i = 2; i < C; i++)
		{
			map[machine[1]][i] = origin[machine[1]][i - 1];
		}
		map[machine[1]][1] = 0;
		// 왼쪽 끝 줄 위로
		for (int i = machine[1] + 1; i < R - 1; i++)
		{
			map[i][0] = origin[i + 1][0];
		}
		
		// 오른쪽 끝 줄 아래로
		for (int i = machine[1] + 1; i < R; i++)
		{
			map[i][C - 1] = origin[i - 1][C - 1];
		}
		
		// R-1번째 줄 = 왼쪽으로
		for (int i = 0; i < C - 1; i++)
		{
			map[R - 1][i] = origin[R - 1][i + 1];
		}
	}

	int answer = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] > 0)
			{
				answer += map[i][j];
			}
		}
	}
	cout << answer;

	return 0;
}