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
	vector<vector<pair<int, int>>> connected(V);
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		connected[u - 1].push_back({ v - 1, w });
	}

	vector<int> distances(V, INT_MAX);
	distances[start - 1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // distance, vertex
	pq.push({ 0, start - 1 });

	while (!pq.empty())
	{
		int d = pq.top().first;
		int v = pq.top().second;
		pq.pop();

		// 현재 정점과 연결된 정점 거리 갱신
		for (auto& [vertex, weight] : connected[v])
		{
			int nd = d + weight;
			if (nd < distances[vertex])
			{
				distances[vertex] = nd;
				pq.push({ nd, vertex });
			}
		}
	}

	for (int i = 0; i < distances.size(); i++)
	{
		if (distances[i] == INT_MAX)
		{
			printf("INF\n");
		}
		else
		{
			printf("%d\n", distances[i]);
		}
	}

	return 0;
}