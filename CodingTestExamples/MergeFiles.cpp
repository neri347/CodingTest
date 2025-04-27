/// 파일 합치기
/// https://www.acmicpc.net/problem/11066
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		vector<int> vec;
		for (int i = 0; i < N; i++)
		{
			int v;
			cin >> v;
			vec.push_back(v);
		}
		vector<vector<int>> dp(N, vector<int>(N, 0));
		// 누적합 구하기
		for (int i = 0; i < N - 1; i++)
		{
			dp[i][i + 1] = vec[i] + vec[i + 1];
			for (int j = i + 2; j < N; j++)
			{
				dp[i][j] = dp[i][j - 1] + vec[j];
			}
		}

		//dp[i][j] = sum[i][j] + min(0~j까지 합한 값)
		for (int count = 2; count < N; count++)
		{
			for (int i = 0; i < N - count; i++)
			{
				int j = i + count;
				int minCost = 99999999;
				for (int x = i; x < j; x++)
				{
					minCost = min(minCost, dp[i][x] + dp[x + 1][j]);
				}
				dp[i][j] += minCost;
			}
		}
		cout << dp[0][N - 1] << '\n';
	}
	return 0;
}