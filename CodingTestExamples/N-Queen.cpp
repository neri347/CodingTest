/// N-Queen
/// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>
using namespace std;

int N;
int board[15][15];
int answer;

bool IsValid(int x, int y)
{
	// 십자모양 체크
	// 가로
	for (int i = 0; i < N; i++)
	{
		if (board[x][i] == 1)
		{
			return false;
		}
	}
	// 세로
	for (int i = 0; i < N; i++)
	{
		if (board[i][y] == 1)
		{
			return false;
		}
	}
	// x자모양 체크
	// 왼쪽 위
	for (int i = 1; i <= x; i++)
	{
		int nx = x - i;
		int ny = y - i;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
		{
			if (board[nx][ny] == 1)
			{
				return false;
			}
		}
	}
	// 오른쪽 위
	for (int i = 1; i <= x; i++)
	{
		int nx = x - i;
		int ny = y + i;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
		{
			if (board[nx][ny] == 1)
			{
				return false;
			}
		}
	}
	// 왼쪽 아래
	for (int i = 1; i < N - x; i++)
	{
		int nx = x + i;
		int ny = y - i;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
		{
			if (board[nx][ny] == 1)
			{
				return false;
			}
		}
	}
	// 오른쪽 아래
	for (int i = 1; i < N - x; i++)
	{
		int nx = x + i;
		int ny = y + i;
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
		{
			if (board[nx][ny] == 1)
			{
				return false;
			}
		}
	}

	return true;
}

void Backtrack(int count)
{
	if (count == N)
	{
		++answer;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (IsValid(i, count))
		{
			board[i][count] = 1;
			Backtrack(count + 1);
			board[i][count] = 0;
		}
	}
}

int main()
{
	cin >> N;
	Backtrack(0);
	cout << answer;
	return 0;
}