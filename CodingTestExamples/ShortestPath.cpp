/// 최단 경로
/// https://www.acmicpc.net/problem/1753
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
	int V, E;
	scanf("%d %d", &V, &E);
	int start;
	scanf("%d", &start);

	vector<vector<pair<int, int>>> graph(V + 1);
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({ v, w });
	}

	vector<int> dist(V + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int node = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		for (auto& [next, weight] : graph[node])
		{
			if (dist[next] > d + weight)
			{
				dist[next] = d + weight;
				pq.push({ dist[next], next });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INT_MAX)
		{
			printf("INF\n");
		}
		else
		{
			printf("%d\n", dist[i]);
		}
	}

	return 0;
}