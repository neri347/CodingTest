/// µ¿Àü 0
/// https://www.acmicpc.net/problem/11047
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> coins;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		coins.push_back(v);
	}

	int answer = 0;
	for (int i = coins.size() - 1; i >= 0; i--)
	{
		int value = coins[i];
		while (K >= value)
		{
			K -= value;
			++answer;
		}
	}
	cout << answer;
	return 0;
}