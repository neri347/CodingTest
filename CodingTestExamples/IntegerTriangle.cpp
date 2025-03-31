/// 정수 삼각형
/// https://www.acmicpc.net/problem/1932
/// https://school.programmers.co.kr/learn/courses/30/lessons/43105
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<vector<int>> vec(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int v;
			cin >> v;
			vec[i][j] = v;
		}
	}

	// 밑에 줄부터 올라가면서 대각선 요소 탐색
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		dp[n - 1][i] = vec[n - 1][i];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + vec[i][j];
		}
	}
	cout << dp[0][0];
	return 0;
}