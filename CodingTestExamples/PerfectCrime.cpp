/// 완전범죄
/// https://school.programmers.co.kr/learn/courses/30/lessons/389480
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Cmp(const vector<int>& a, const vector<int>& b)
{
	if (a[0] == b[0])
	{
		return a[1] < b[1];
	}
	return a[0] > b[0];
}

int solution(vector<vector<int>> info, int n, int m) {	
	// info[i][0] 큰 순으로 정렬
	sort(info.begin(), info.end(), Cmp);
	vector<vector<int>> dp(info.size(), vector<int>(2, 0)); // dp[i][0] = A가 물건을 훔치는 경우, dp[i][1] = B가 물건을 훔치는 경우. 남긴 흔적 개수

	if (info[0][1] >= m) // B가 물건을 훔칠 수 없는 경우
	{
		dp[0][0] = info[0][0];
	}
	else
	{
		dp[0][1] = info[0][1];
	}

	for (int i = 1; i < info.size(); i++)
	{
		if (dp[i - 1][1] + info[i][1] >= m) // B가 물건을 훔칠 수 없는 경우
		{
			dp[i][0] = dp[i - 1][0] + info[i][0];
			dp[i][1] = dp[i - 1][1];
		}
		else
		{
			dp[i][1] = dp[i - 1][1] + info[i][1];
		}
	}

	return dp[info.size() - 1][0] < n ? dp[info.size() - 1][0] : -1;
}

int main()
{
	/*vector<vector<int>> info = { {1,2},{2,3},{2,1} };
	int n = 4;
	int m = 4;*/
	vector<vector<int>> info = { {5,1},{4,1},{3,1}, {2,1}, {1,1} };
	int n = 1;
	int m = 4;
	cout << solution(info, n, m);
	return 0;
}