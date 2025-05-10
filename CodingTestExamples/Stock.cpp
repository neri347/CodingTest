/// аж╫д
/// https://www.acmicpc.net/problem/11501
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		vector<int> prices;
		for (int i = 0; i < N; i++)
		{
			int p;
			cin >> p;
			prices.push_back(p);
		}

		long answer = 0;
		int m = prices[N - 1];
		for (int i = N - 2; i >= 0; i--)
		{
			if (prices[i] <= m)
			{
				answer += (m - prices[i]);
			}
			else
			{
				m = prices[i];
			}
		}
		cout << answer << '\n';
	}
	return 0;
}