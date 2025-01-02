/// ¶¥µû¸Ô±â
/// https://school.programmers.co.kr/learn/courses/30/lessons/12913
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
	int size = land.size();

	vector<vector<int>> dp(size, vector<int>(4, 0));
	dp[0][0] = land[0][0];
	dp[0][1] = land[0][1];
	dp[0][2] = land[0][2];
	dp[0][3] = land[0][3];

	for (int i = 1; i < size; ++i)
	{
		dp[i][0] = max({ dp[i - 1][1] + land[i][0], dp[i - 1][2] + land[i][0], dp[i - 1][3] + land[i][0] });
		dp[i][1] = max({ dp[i - 1][0] + land[i][1], dp[i - 1][2] + land[i][1], dp[i - 1][3] + land[i][1] });
		dp[i][2] = max({ dp[i - 1][0] + land[i][2], dp[i - 1][1] + land[i][2], dp[i - 1][3] + land[i][2] });
		dp[i][3] = max({ dp[i - 1][0] + land[i][3], dp[i - 1][1] + land[i][3], dp[i - 1][2] + land[i][3] });
	}

	return *max_element(dp[size - 1].begin(), dp[size - 1].end());
}

int main()
{

	return 0;
}