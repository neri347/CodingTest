/// 2xn ≈∏¿œ∏µ 2
/// https://www.acmicpc.net/problem/11727
#include <iostream>
#include <vector>
using namespace std;

int dp[1001];
const int mod = 10007;

int Recur(int n)
{
	if (dp[n])
	{
		return dp[n];
	}
	return dp[n] = (Recur(n - 1) % mod + Recur(n - 2) * 2 % mod) % mod;
}

int main()
{
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	cout << Recur(n);
	return 0;
}