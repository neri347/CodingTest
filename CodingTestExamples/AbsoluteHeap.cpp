/// Àý´ñ°ª Èü
/// https://www.acmicpc.net/problem/11286
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Cmp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
		{
			return a > b;
		}
		return abs(a) < abs(b);
	}
};

int main()
{
	int N;
	cin >> N;
	priority_queue<int, vector<int>, Cmp> pq;
	
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
			{
				cout << 0;
				continue;
			}
			cout << pq.top();
			pq.pop();
		}
		else
		{
			pq.push(x);
		}
		cout << '\n';
	}
	return 0;
}