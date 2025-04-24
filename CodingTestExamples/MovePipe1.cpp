/// 파이프 옮기기 1
/// https://www.acmicpc.net/problem/17070
#include <iostream>
#include <vector>
using namespace std;

int N;
int board[16][16];
int dp[16][16][3];

void Recur(int x, int y, int type)
{
	if (type == 0) // 가로
	{
		if (y + 1 < N && board[x][y+1] == 0)
		{
			dp[x][y + 1][0]++;
			Recur(x, y + 1, 0);
		}
		if (x + 1 < N && y + 1 < N && board[x][y + 1] == 0 && board[x + 1][y] == 0 && board[x + 1][y + 1] == 0)
		{
			dp[x + 1][y + 1][2]++;
			Recur(x + 1, y + 1, 2);
		}
	}
	else if (type == 1) // 세로
	{
		if (x + 1 < N && board[x + 1][y] == 0)
		{
			dp[x + 1][y][1]++;
			Recur(x + 1, y, 1);
		}
		if (x + 1 < N && y + 1 < N && board[x][y + 1] == 0 && board[x + 1][y] == 0 && board[x + 1][y + 1] == 0)
		{
			dp[x + 1][y + 1][2]++;
			Recur(x + 1, y + 1, 2);
		}
	}
	else
	{
		if (y + 1 < N && board[x][y + 1] == 0)
		{
			dp[x][y + 1][0]++;
			Recur(x, y + 1, 0);
		}
		if (x + 1 < N && board[x + 1][y] == 0)
		{
			dp[x + 1][y][1]++;
			Recur(x + 1, y, 1);
		}
		if (x + 1 < N && y + 1 < N && board[x][y + 1] == 0 && board[x + 1][y] == 0 && board[x + 1][y + 1] == 0)
		{
			dp[x + 1][y + 1][2]++;
			Recur(x + 1, y + 1, 2);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	
	dp[0][1][0] = 1;
	Recur(0, 1, 0);
	cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
	return 0;
}