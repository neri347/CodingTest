/// Á¤¼ö »ï°¢Çü
/// https://school.programmers.co.kr/learn/courses/30/lessons/43105
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int size = triangle.size();
	vector<vector<int>> dp(size, vector<int>(size, 0));
	dp[0][0] = triangle[0][0];

	for (int i = 0; i < triangle.size() - 1; ++i)
	{
		for (int j = 0; j < triangle[i].size(); ++j)
		{
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
			dp[i + 1][j + 1] = dp[i][j] + triangle[i + 1][j + 1];
		}
	}

	return *max_element(dp[size - 1].begin(), dp[size - 1].end());
}

int main()
{

	return 0;
}