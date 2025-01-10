/// 포도주 시식
/// https://www.acmicpc.net/problem/2156
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<int> wines;
	for (int i = 0; i < 3; ++i)
	{
		wines.push_back(0);
	}
	for (int i = 0; i < n; ++i)
	{
		int w;
		cin >> w;
		wines.push_back(w);
	}

	// 풀이
	vector<int> dp(n + 3, 0);

	for (int i = 3; i < n + 3; ++i)
	{
		// i번째 잔을 마셨을 때
			// i - 1번째 잔을 마셨을 때 = dp[i - 3] + wines[i - 1] + wines[i]
			// i - 1번째 잔을 마시지 않았을 때 = dp[i-1] + wines[i]
		int temp = max(dp[i - 3] + wines[i - 1] + wines[i], dp[i - 2] + wines[i]);
		// i번째 잔을 마시지 않았을 때 dp[i] = dp[i-1]
		dp[i] = max(temp, dp[i - 1]);
	}
	cout << dp.back();
	return 0;
}