/// ¿îµ¿
/// https://www.acmicpc.net/problem/1956
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 999999999;

int main()
{
	int V, E;
	cin >> V >> E;
	
	vector<vector<int>> dist(V, vector<int>(V, MAX));
	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		dist[from - 1][to - 1] = cost;
	}

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (i == j)
			{
				dist[i][j] = 0;
			}
		}
	}

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int answer = MAX;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (i == j) continue;
			answer = min(answer, dist[i][j] + dist[j][i]);
		}
	}

	if (answer == MAX)
	{
		answer = -1;
	}
	cout << answer;
	return 0;
}