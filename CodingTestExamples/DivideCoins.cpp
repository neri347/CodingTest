/// 동전 분배
/// https://www.acmicpc.net/problem/1943
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int dp[101][100001];
vector<pair<int, int>> coins;

// coins[0]~coins[index] 까지의 동전들로 value를 만들 수 있는가
int Recur(int index, int value)
{
	if (value < 0)
	{
		return 0;
	}

	if (index == N)
	{
		return value == 0;
	}

	if (dp[index][value] != -1)
	{
		return dp[index][value];
	}

	int ret = 0;
	for (int i = 0; i <= coins[index].second; i++)
	{
		ret = max(ret, Recur(index + 1, value - coins[index].first * i));
		dp[index][value] = ret;
	}

	return ret;
}

int main()
{
	for (int t = 0; t < 3; t++)
	{
		cin >> N;
		coins.resize(N);
		int sum = 0;
		
		for (int i = 0; i < N; i++)
		{
			int value, count;
			cin >> value >> count;
			sum += value * count;
			coins[i].first = value;
			coins[i].second = count;
		}

		// 금액이 반으로 나누어 떨어지지 않으면 반으로 나누어 가질 수 없다.
		if (sum % 2 == 1)
		{
			cout << 0 << '\n';
			continue;
		}

		memset(dp, -1, sizeof(dp));
		int answer = Recur(0, sum / 2);
		cout << answer << '\n';
	}
	return 0;
}