/// 피보나치 함수
/// https://www.acmicpc.net/problem/1003
#include <iostream>
#include <vector>
using namespace std;

int dp_zero[41];
int dp_one[41];

int main()
{
	dp_zero[0] = 1;
	dp_one[1] = 1;
	for (int i = 2; i <= 40; i++)
	{
		dp_zero[i] = dp_zero[i - 1] + dp_zero[i - 2];
		dp_one[i] = dp_one[i - 1] + dp_one[i - 2];
	}
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		cout << dp_zero[n] << ' ' << dp_one[n] << '\n';
	}
	return 0;
}