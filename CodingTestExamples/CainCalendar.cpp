/// Ä«À× ´Þ·Â
/// https://www.acmicpc.net/problem/6064
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Gcd(int a, int b)
{
	int bigger = max(a, b);
	int smaller = min(a, b);
	while (bigger % smaller != 0)
	{
		int r = bigger % smaller;
		bigger = smaller;
		smaller = r;
	}
	return smaller;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int maxYear = M * N / Gcd(M, N);
		bool flag = false;
		while (x <= maxYear)
		{
			if (x % N == y || (x % N == 0 && y == N))
			{
				cout << x << '\n';
				flag = true;
				break;
			}
			x += M;
		}
		if (!flag)
		{
			cout << -1 << '\n';
		}
	}
	return 0;
}