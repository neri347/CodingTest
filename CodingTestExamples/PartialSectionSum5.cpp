/// 구간 합 구하기 5
/// https://www.acmicpc.net/problem/11660
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		int sum = 0; // i번째 줄 숫자 합계
		for (int j = 1; j <= N; j++)
		{
			int num;
			scanf("%d", &num);
			sum += num;
			dp[i][j] = dp[i - 1][j] + sum;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int value = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		printf("%d\n", value);
	}

	return 0;
}