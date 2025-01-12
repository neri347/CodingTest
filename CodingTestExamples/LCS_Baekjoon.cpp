/// LCS
/// https://www.acmicpc.net/problem/9251
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string a, b;
	cin >> a;
	cin >> b;

	vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
	for (int i = 1; i <= a.size(); ++i)
	{
		for (int j = 1; j <= b.size(); ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[a.size()][b.size()];
	return 0;
}