#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Cmp
{
	bool operator()(int a, int b)
	{
		int aa = abs(a);
		int ab = abs(b);
		if (aa == ab)
		{
			return a > b;
		}
		return aa > ab;
	}
};

int main()
{
	int N;
	cin >> N;
	priority_queue<int, vector<int>, Cmp> pq;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		if (v == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else
		{
			pq.push(v);
		}
	}
	return 0;
}