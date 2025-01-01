/// 설탕 배달
/// https://www.acmicpc.net/problem/2839
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[5001];

int main()
{
	int n;
	cin >> n;
	
	dp[3] = dp[5] = 1;

	// 5 다음인 6부터 순회
	for (int i = 6; i <= n; ++i)
	{
		// 3의 배수라면 -> 현재 수에 3을 뺐을 때 dp에 값이 있을 것이다.
		if (dp[i - 3])
		{
			dp[i] = dp[i - 3] + 1;
		}

		// 5의 배수라면 -> 현재 수에 5를 뺐을 때 dp에 값이 있을 것이다.
		// 3과 5 공배수? -> dp[i-3]업데이트 때 값이 갱신되었을 것
		if (dp[i - 5])
		{
			dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
		}
	}
	cout << (dp[n] == 0 ? -1 : dp[n]);
	
	return 0;
}