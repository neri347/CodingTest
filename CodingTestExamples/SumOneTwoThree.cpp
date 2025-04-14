/// 1, 2, 3 ¥ı«œ±‚
/// https://www.acmicpc.net/problem/9095
#include <iostream>
#include <vector>
using namespace std;

int Recur(int n, vector<int>& dp)
{
	if (dp[n] != 0)
	{
		return dp[n];
	}
	dp[n] += Recur(n - 1, dp);
	dp[n] += Recur(n - 2, dp);
	dp[n] += Recur(n - 3, dp);
	return dp[n];
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int num;
		cin >> num;
		vector<int> dp(num + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		int answer = Recur(num, dp);
		cout << answer << '\n';
	}
	return 0;
}