/// 경사로
/// https://www.acmicpc.net/problem/14890
/// 경사로 깔린 위치에는 다른 경사로를 깔 수 없다.
/// 경사로 방향 확인
/// 경사로 길이만큼 땅 확보 필요
#include <iostream>
#include <vector>
using namespace std;

int N, L;
int board[100][100];

bool CheckRoad(int x, int y, int height, int dir, vector<bool>& isSloped)
{
	if (dir == 1) // 왼쪽으로 체크
	{
		int ny = y - 1;
		int count = 1;
		while (ny >= 0 && ny < N && !isSloped[ny] && board[x][ny] == height && count < L)
		{
			isSloped[ny] = true;
			--ny;
			++count;
		}
		if (count >= L)
		{
			isSloped[y] = true;
			return true;
		}
	}
	else if (dir == 2) // 오른쪽으로 체크
	{
		int ny = y + 1;
		int count = 1;
		while (ny >= 0 && ny < N && !isSloped[ny] && board[x][ny] == height && count < L)
		{
			isSloped[ny] = true;
			++ny;
			++count;
		}
		if (count >= L)
		{
			isSloped[y] = true;
			return true;
		}
	}
	else if (dir == 3) // 밑으로 체크
	{
		int nx = x + 1;
		int count = 1;
		while (nx >= 0 && nx < N && !isSloped[nx] && board[nx][y] == height && count < L)
		{
			isSloped[nx] = true;
			++nx;
			++count;
		}
		if (count >= L)
		{
			isSloped[x] = true;
			return true;
		}
	}
	else // 위로 체크
	{
		int nx = x - 1;
		int count = 1;
		while (nx >= 0 && nx < N && !isSloped[nx] && board[nx][y] == height && count < L)
		{
			isSloped[nx] = true;
			--nx;
			++count;
		}
		if (count >= L)
		{
			isSloped[x] = true;
			return true;
		}
	}
	return false;
}

int main()
{
	int answer = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int n;
			cin >> n;
			board[i][j] = n;
		}
	}

	// 가로 길
	for (int i = 0; i < N; i++)
	{
		vector<bool> isSloped(N, false); // 경사로 깔려있는지
		bool flag = true;
		for (int j = 1; j < N; j++)
		{
			if (isSloped[j])
			{
				continue;
			}
			if (board[i][j - 1] != board[i][j])
			{
				// 높이차 1이면 경사로 깔 수 있다.
				// 경사로는 낮은 곳에 깐다.
				if (board[i][j - 1] - board[i][j] == -1) // 전의 칸이 더 낮은 경우
				{
					if (isSloped[j - 1] || !CheckRoad(i, j - 1, board[i][j - 1], 1, isSloped))
					{
						flag = false;
						break;
					}
				}
				else if (board[i][j - 1] - board[i][j] == 1) // 지금 칸이 더 낮은 경우
				{
					if (isSloped[j] || !CheckRoad(i, j, board[i][j], 2, isSloped))
					{
						flag = false;
						break;
					}
				}
				else // 높이 차 2 이상이면 길이 될 수 없다.
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{
			++answer;
		}
	}

	// 세로 길
	for (int i = 0; i < N; i++)
	{
		vector<bool> isSloped(N, false);
		bool flag = true;
		for (int j = 1; j < N; j++)
		{
			if (isSloped[j])
			{
				continue;
			}

			if (board[j - 1][i] != board[j][i])
			{
				// 높이차 1이면 경사로 깔 수 있다.
				if (board[j - 1][i] - board[j][i] == -1)
				{
					if (isSloped[j - 1] || !CheckRoad(j - 1, i, board[j - 1][i], 4, isSloped))
					{
						flag = false;
						break;
					}
				}
				else if (board[j - 1][i] - board[j][i] == 1)
				{
					if (isSloped[j] || !CheckRoad(j, i, board[j][i], 3, isSloped))
					{
						flag = false;
						break;
					}
				}
				else
				{
					flag = false;
					break;
				}
			}
		}

		if (flag)
		{
			++answer;
		}
	}

	cout << answer;
	return 0;
}