/// πÏ
/// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int N;
int board[100][100]; // 0 = ∫Ûƒ≠, 1 = πÏ, 2 = ªÁ∞˙
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int answer, dir;

bool IsValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N && board[x][y] != 1;
}

void Snake(queue<pair<int, char>>& time)
{
	deque<pair<int, int>> snake;
	snake.push_front({ 0, 0 });

	while (true)
	{		
		++answer;
		
		// ∏”∏Æ¿Ãµø
		int hx = snake.front().first;
		int hy = snake.front().second;
		hx += dx[dir];
		hy += dy[dir];

		if (!IsValid(hx, hy))
		{
			return;
		}
		snake.push_front({ hx, hy });

		if (board[hx][hy] != 2)
		{
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		board[hx][hy] = 1;

		// »∏¿¸
		if (!time.empty() && answer == time.front().first)
		{
			if (time.front().second == 'L')
			{
				dir = (dir - 1 + 4) % 4;
			}
			else
			{
				dir = (dir + 1) % 4;
			}
			time.pop();
		}
	}
}

int main()
{
	// ¿‘∑¬
	int appleCnt, turnCnt;
	cin >> N;
	cin >> appleCnt;
	for (int i = 0; i < appleCnt; ++i)
	{
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = 2;
	}
	cin >> turnCnt;
	queue<pair<int, char>> time;
	for (int i = 0; i < turnCnt; ++i)
	{
		int second;
		char direction;
		cin >> second >> direction;
		time.push({ second, direction });
	}

	// «Æ¿Ã
	Snake(time);
	cout << answer;

	return 0;
}