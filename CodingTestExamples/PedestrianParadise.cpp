/// 보행자 천국
/// https://school.programmers.co.kr/learn/courses/30/lessons/1832
#include <iostream>
#include <vector>
using namespace std;

#include <vector>

using namespace std;

int MOD = 20170805;
int EMPTY = 0;
int NOTALLOWED = 1;
int STRAIGHT = 2;

int UP = 0;
int LEFT = 1;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));

	// 0행 채우기
	for (int i = 0; i < n; i++)
	{
		if (city_map[0][i] == NOTALLOWED)
		{
			break;
		}
		dp[0][i][LEFT] = 1;
	}
	// 0열 채우기
	for (int i = 0; i < m; i++)
	{
		if (city_map[i][0] == NOTALLOWED)
		{
			break;
		}
		dp[i][0][UP] = 1;
	}


	// 나머지 채우기
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (city_map[i][j] == NOTALLOWED)    continue;

			// 상단 데이터
			int up = dp[i - 1][j][UP];
			if (city_map[i - 1][j] == EMPTY)
			{
				up = (up + dp[i - 1][j][LEFT]) % MOD;
			}

			// 좌측 데이터
			int left = dp[i][j - 1][LEFT];
			if (city_map[i][j - 1] == EMPTY)
			{
				left = (left + dp[i][j - 1][UP]) % MOD;
			}

			dp[i][j][UP] = up;
			dp[i][j][LEFT] = left;
		}
	}

	return (dp[m - 1][n - 1][UP] + dp[m - 1][n - 1][LEFT]) % MOD;
}

int main()
{

	return 0;
}