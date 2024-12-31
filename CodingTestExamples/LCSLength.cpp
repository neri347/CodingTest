/// p.704 ����70_LCS ���� ����ϱ�
/// LCS = ���� ���� �κ� ����
/// �� ������ � ����� ���� ���ʿ��� �������� �߰��� �� �ִ� ���� �� �κ� ����
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ���ڰ� ���� ���, dp[i][j] = dp[i-1][j-1] + 1
// ���ڰ� �ٸ� ���, dp[i][j] = max(dp[i-1][j], dp[i][j-1])

int solution(string str1, string str2)
{
	int m = str1.length();
	int n = str2.length();
	
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 0~m, 0~n
	
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (str1[i] == str2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	return dp[m][n];
}

int main()
{
	string str1 = "ABCBDAB";
	string str2 = "BDCAB";
	cout << solution(str1, str2);
	return 0;
}