/// 게리맨더링 2
/// https://www.acmicpc.net/problem/17779
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int board[21][21];
int answer = 987654321;
int sumBoard; // 모든 인구 합

void Count(int x, int y, int d1, int d2)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int sum = sumBoard; // 모든 인구 합에서 1,2,3,4 구역 인구 빼면 5구역 인구 남는다.
	// 1번 선거구
	int column = y;
	for (int r = 1; r < x; r++)
	{
		for (int c = 1; c <= column; c++)
		{
			num1 += board[r][c];
			sum -= board[r][c];
		}
	}
	for (int r = x; r < x + d1; r++)
	{
		for (int c = column - 1; c >= 0; c--)
		{
			num1 += board[r][c];
			sum -= board[r][c];
		}
		--column;
	}
	// 2번 선거구
	column = y + 1;
	for (int r = 0; r < x; r++)
	{
		for (int c = column; c <= N; c++)
		{
			num2 += board[r][c];
			sum -= board[r][c];
		}
	}
	for (int r = x; r <= x + d2; r++)
	{
		for (int c = column; c <= N; c++)
		{
			num2 += board[r][c];
			sum -= board[r][c];
		}
		++column;
	}
	// 3번 선거구
	column = y - d1;
	for (int r = x + d1; r <= x + d1 + d2; r++)
	{
		for (int c = 1; c < column; c++)
		{
			num3 += board[r][c];
			sum -= board[r][c];
		}
		++column;
	}
	for (int r = x + d1 + d2 + 1; r <= N; r++)
	{
		for (int c = 1; c < column - 1; c++)
		{
			num3 += board[r][c];
			sum -= board[r][c];
		}
	}
	// 4번 선거구
	column = y + d2;
	for (int r = x + d2 + 1; r <= x + d1 + d2; r++)
	{
		for (int c = column; c <= N; c++)
		{
			num4 += board[r][c];
			sum -= board[r][c];
		}
		--column;
	}
	for (int r = x + d1+d2 + 1; r <= N; r++)
	{
		for (int c = column; c <= N; c++)
		{
			num4 += board[r][c];
			sum -= board[r][c];
		}
	}

	int maxValue = max({ num1, num2, num3, num4, sum });
	int minValue = min({ num1, num2, num3, num4, sum });
	answer = min(answer, maxValue - minValue);
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int v;
			cin >> v;
			board[i][j] = v;
			sumBoard += v;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int d1 = 1; d1 < N; d1++)
			{
				for (int d2 = 1; d2 < N; d2++)
				{
					if (i + d1 + d2 <= N && j - d1 >= 1 && j - d1 < j && j + d2 <= N)
					{
						Count(i, j, d1, d2);
					}
				}
			}
		}
	}

	cout << answer;
	return 0;
}