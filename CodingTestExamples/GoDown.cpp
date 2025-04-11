/// 내려가기
/// https://www.acmicpc.net/problem/2096
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[100000][3];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> board[i][j];
		}
	}

	vector<int> dp(3, 0);
	vector<int> temp(3, 0);
	dp[0] = board[0][0];
	dp[1] = board[0][1];
	dp[2] = board[0][2];

	for (int i = 1; i < N; i++)
	{
		temp[0] = dp[0];
		temp[1] = dp[1];
		temp[2] = dp[2];
		dp[0] = max(temp[0], temp[1]) + board[i][0];
		dp[1] = max({ temp[0], temp[1], temp[2]}) + board[i][1];
		dp[2] = max(temp[1], temp[2]) + board[i][2];
	}
	cout << *max_element(dp.begin(), dp.end()) << ' ';

	dp[0] = board[0][0];
	dp[1] = board[0][1];
	dp[2] = board[0][2];

	for (int i = 1; i < N; i++)
	{
		temp[0] = dp[0];
		temp[1] = dp[1];
		temp[2] = dp[2];
		dp[0] = min(temp[0], temp[1]) + board[i][0];
		dp[1] = min({ temp[0], temp[1], temp[2] }) + board[i][1];
		dp[2] = min(temp[1], temp[2]) + board[i][2];
	}

	cout << *min_element(dp.begin(), dp.end());
	return 0;
}