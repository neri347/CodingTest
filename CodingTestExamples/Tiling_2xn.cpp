/// 2xn ≈∏¿œ∏µ
/// https://www.acmicpc.net/problem/11726
#include <iostream>
#include <vector>
using namespace std;
// 1 2 3 5 ...
int main()
{
	int n;
	cin >> n;
	vector<int> dp(n+1, 0); //0~n
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	cout << dp[n];

	return 0;
}