/// 내려가기
/// https://www.acmicpc.net/problem/2096
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int board[100001][3];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int value;
			cin >> value;
			board[i][j] = value;
		}
	}
	// 최대 점수 구하기
	int dp[6]; // 0~2 : max , 3~5 : min
	dp[0] = board[0][0];
	dp[1] = board[0][1];
	dp[2] = board[0][2];
	dp[3] = board[0][0];
	dp[4] = board[0][1];
	dp[5] = board[0][2];
	int temp[6];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			temp[j] = dp[j];
		}
		dp[0] = max(temp[0], temp[1]) + board[i][0];
		dp[1] = max({ temp[0], temp[1], temp[2] }) + board[i][1];
		dp[2] = max(temp[1], temp[2]) + board[i][2];

		dp[3] = min(temp[3], temp[4]) + board[i][0];
		dp[4] = min({ temp[3], temp[4], temp[5] }) + board[i][1];
		dp[5] = min(temp[4], temp[5]) + board[i][2];
	}

	int maxValue = max({ dp[0], dp[1], dp[2] });
	int minValue = min({ dp[3], dp[4], dp[5] });
	cout << maxValue << " " << minValue;

	return 0;
}