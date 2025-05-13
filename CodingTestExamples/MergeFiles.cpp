/// 파일 합치기
/// https://www.acmicpc.net/problem/11066
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 999999999;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		vector<int> vec(N + 1, 0);
		for (int i = 1; i <= N; i++)
		{
			cin >> vec[i];
		}
		vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
		vector<int> sums(N + 1, 0);
		// 누적합 구하기
		for (int i = 1; i <= N; i++)
		{
			sums[i] = sums[i - 1] + vec[i];
		}

		for (int count = 1; count <= N; count++)
		{
			for (int start = 1; start <= N - count; start++)
			{
				dp[start][start + count] = MAX;
				for (int mid = start; mid < start + count; mid++)
				{
					dp[start][start + count] = min(dp[start][start + count], dp[start][mid] + dp[mid + 1][start + count] + sums[start + count] - sums[start - 1]);
				}
			}
		}

		cout << dp[1][N] << '\n';
	}
	return 0;
}