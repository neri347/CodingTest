/// ÃÖ¼Ò Èü
/// https://www.acmicpc.net/problem/1927
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		if (v == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				cout << v << "\n";
			}
		}
		else
		{
			pq.push(v);
		}
	}
	return 0;
}