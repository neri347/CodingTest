/// 여행 가자
/// https://www.acmicpc.net/problem/1976
#include <iostream>
#include <vector>
using namespace std;

int connected[200][200];
int parents[200];

int Find(int x)
{
	if (parents[x] == x)
	{
		return x;
	}
	parents[x] = Find(parents[x]);
	return parents[x];
}

bool IsCycle(int x, int y)
{
	return Find(x) == Find(y);
}

void Union(int x, int y)
{
	int root1 = Find(x);
	int root2 = Find(y);
	if (root1 != root2)
	{
		parents[root2] = root1;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> connected[i][j];
		}
	}

	vector<int> trip;
	for (int i = 0; i < M; i++)
	{
		int v;
		cin >> v;
		trip.push_back(v - 1);
	}

	for (int i = 0; i < N; i++)
	{
		parents[i] = i;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (connected[i][j] == 1)
			{
				if (!IsCycle(i, j))
				{
					Union(i, j);
				}
			}
		}
	}

	string answer = "YES";
	for (int i = 1; i < M; i++)
	{
		if (!IsCycle(trip[0], trip[i]))
		{
			answer = "NO";
			break;
		}
	}
	cout << answer;
	return 0;
}