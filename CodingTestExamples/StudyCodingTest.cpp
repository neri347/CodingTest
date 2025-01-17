/// 코딩 테스트 공부
/// https://school.programmers.co.kr/learn/courses/30/lessons/118668
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
	int goalAlp = 0;
	int goalCop = 0;
	for (int i = 0; i < problems.size(); ++i)
	{
		goalAlp = max(goalAlp, problems[i][0]);
		goalCop = max(goalCop, problems[i][1]);
	}

	// 이미 목표치를 달성했으면
	if (alp >= goalAlp && cop >= goalCop)
	{
		return 0;
	}

	// 목표치를 넘어간다면 목표치와 같게 설정
	if (alp > goalAlp)
	{
		alp = goalAlp;
	}
	if (cop > goalCop)
	{
		cop = goalCop;
	}

	vector<vector<int>> dp(goalAlp + 2, vector<int>(goalCop + 2, 10000000));
	dp[alp][cop] = 0;

	for (int i = alp; i <= goalAlp; ++i)
	{
		for (int j = cop; j <= goalCop; ++j)
		{
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
			// 문제 풀기
			for (int k = 0; k < problems.size(); ++k)
			{
				if (i >= problems[k][0] && j >= problems[k][1])
				{
					if (i + problems[k][2] > goalAlp && j + problems[k][3] > goalCop)
					{
						dp[goalAlp][goalCop] =
							min(dp[goalAlp][goalCop], dp[i][j] + problems[k][4]);
					}
					else if (i + problems[k][2] > goalAlp)
					{
						dp[goalAlp][j + problems[k][3]] =
							min(dp[goalAlp][j + problems[k][3]], dp[i][j] + problems[k][4]);
					}
					else if (j + problems[k][3] > goalCop)
					{
						dp[i + problems[k][2]][goalCop] =
							min(dp[i + problems[k][2]][goalCop], dp[i][j] + problems[k][4]);
					}
					else
					{
						dp[i + problems[k][2]][j + problems[k][3]] =
							min(dp[i + problems[k][2]][j + problems[k][3]], dp[i][j] + problems[k][4]);
					}
				}
			}
		}
	}

	return dp[goalAlp][goalCop];
}

int main()
{

	return 0;
}