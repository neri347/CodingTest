/// 빌런 호석
/// https://www.acmicpc.net/problem/22251
#include <iostream>
#include <vector>
using namespace std;

int N, K, P, X;
bool shapes[10][7] = { 
	{ true, true, true, false, true, true, true },
	{ false, false, true, false, false, true, false },
	{ true, false, true, true, true, false, true },
	{ true, false, true, true, false, true, true },
	{ false, true, true, true, false, true, false },
	{ true, true, false, true, false, true, true },
	{ true, true, false, true, true, true, true },
	{ true, false, true, false, false, true, false },
	{ true, true, true, true, true, true, true },
	{ true, true, true, true, false, true, true }
	};

int Change()
{
	int answer = 0;
	for (int i = 1; i <= N; i++) // 1층부터 N층까지 검사
	{
		if (X == i)	continue;
		int from = X;
		int to = i;
		int count = 0;
		for (int k = 0; k < K; k++) // k 개 디스플레이
		{
			for (int p = 0; p < 7; p++)
			{
				if (shapes[from % 10][p] != shapes[to % 10][p])
				{
					++count;
				}
			}
			from /= 10;
			to /= 10;
		}

		if (count <= P)
		{
			++answer;
		}
	}
	return answer;
}

int main()
{
	cin >> N >> K >> P >> X;
	cout << Change();
	return 0;
}