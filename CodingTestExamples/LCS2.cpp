/// LCS 2
/// https://www.acmicpc.net/problem/9252
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string a;
	string b;
	cin >> a >> b;
	vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
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

	string answer;
	int i = a.size();
	int j = b.size();

	cout << dp[i][j] << '\n';
	if (dp[i][j] == 0)
	{
		return 0;
	}

	while (i > 0 && j > 0)
	{
		if (a[i - 1] == b[j - 1])
		{
			answer += a[i - 1];
			i--;
			j--;
		}
		else
		{
			if (dp[i - 1][j] > dp[i][j - 1])
			{
				i--;
			}
			else
			{
				j--;
			}
		}
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
	return 0;
}