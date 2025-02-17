/// 완전범죄
/// https://school.programmers.co.kr/learn/courses/30/lessons/389480
/// 처음에는 DFS를 이용한 완전 탐색 알고리즘으로 풀었으나, 시간초과가 났다.
/// 물건의 개수가 40개이므로, 완전 탐색 알고리즘을 이용하면 2^40번의 결과를 확인해야 하므로 시간초과가 날 수 밖에 없을 것이다.
/// 그래서 DP를 통해 풀었다.
/// dp값의 저장은 (물건의 개수) * (b가 남길 수 있는 최대 흔적 개수) 만큼 해주었다.
/// b가 n개(n >= 0 && n < m)의 흔적을 남겼을 때 a가 남긴 흔적의 개수를 저장한다.
/// 그래서 dp[info.size()][i] (i >= 0 && i < m) 중 최소값을 찾으면 그것이 답이 된다.
/// dp 값을 저장할 때는 a가 흔적을 남겼을 경우와 b가 흔적을 남겼을 경우 2가지를 dp벡터에 기록을 해준다.
/// a가 흔적을 남기는 경우 이전에 남긴 흔적개수에 이번에 남긴 흔적의 개수를 더해주면 된다.
/// b가 흔적을 남기는 경우, b가 남긴 흔적이 m보다 작아야 하고, 확인해서 흔적을 남길 수 있다면
/// 이전에 a가 흔적을 남긴 개수를 그대로 저장하면 된다. (dp에 기록하는 값은 a가 남기는 흔적 개수이기 때문)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
	const int INF = 1000000;
	vector<vector<int>> dp(info.size() + 1, vector<int>(m, INF)); // a가 남긴 흔적 개수
	for (int i = 0; i < m; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= info.size(); i++)
	{
		int a = info[i - 1][0];
		int b = info[i - 1][1];
		for (int j = 0; j < m; j++)
		{
			// a 선택
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);
			// b 선택
			if (j + b < m)
			{
				dp[i][j + b] = min(dp[i][j + b], dp[i - 1][j]);
			}
		}
	}

	int answer = INF;
	for (int i = 0; i < m; i++)
	{
		answer = min(answer, dp[info.size()][i]);
	}
	return answer < n ? answer : -1;
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