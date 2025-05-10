/// ¡÷¿Øº“
/// https://www.acmicpc.net/problem/13305
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> dist;
	vector<int> prices;
	for (int i = 0; i < N - 1; i++)
	{
		int v;
		cin >> v;
		dist.push_back(v);
	}
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		prices.push_back(v);
	}

	long long answer = 0;
	int m = prices[0];
	for (int i = 0; i < N - 1; i++)
	{
		if (prices[i] < m)
		{
			m = prices[i];
		}
		answer += (long long)m * dist[i];
	}
	cout << answer;
	return 0;
}