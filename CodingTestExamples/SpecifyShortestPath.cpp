/// Ư���� �ִ� ���
/// https://www.acmicpc.net/problem/1504
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

int N, E;
vector<vector<pair<int, int>>> graph;

int GetShortestDist(int start, int end)
{
	vector<int> dist(N + 1, INT_MAX);
	vector<bool> isVisited(N + 1, false);
	dist[start] = 0;

	priority_queue<pair<int, int>> pq; // dist, node
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curDist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (isVisited[node])
		{
			continue;
		}

		isVisited[node] = true;

		for (auto& p : graph[node])
		{
			int next = p.first;
			int weight = p.second;

			// ���� ��带 ���ļ� ���� ���� ���� ���� �� ª�ٸ� ����
			if (curDist + weight < dist[next])
			{
				dist[next] = curDist + weight;
				pq.push({ -dist[next], next });
			}
		}
	}

	return dist[end];
}

int main()
{
	cin >> N >> E;
	graph.resize(N + 1);
	for (int i = 0; i < E; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({ to, weight });
		graph[to].push_back({ from, weight });
	}
	int dest1;
	int dest2;
	cin >> dest1 >> dest2;

	int ret1 = 0;
	// 1��~dest1 ���� �ִܰŸ�
	int temp = GetShortestDist(1, dest1);
	if (temp == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	ret1 += temp;
	// dest1~dest2 ���� �ִܰŸ�
	temp = GetShortestDist(dest1, dest2);
	if (temp == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	ret1 += temp;
	// dest2~N ���� �ִܰŸ�
	temp = GetShortestDist(dest2, N);
	if (temp == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	ret1 += temp;

	int ret2 = 0;
	// 1��~dest2 ���� �ִܰŸ�
	int temp2 = GetShortestDist(1, dest2);
	if (temp2 == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	ret2 += temp2;
	// dest2~dest1 ���� �ִܰŸ�
	temp2 = GetShortestDist(dest2, dest1);
	if (temp2 == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	ret2 += temp2;
	// dest1~N ���� �ִܰŸ�
	temp2 = GetShortestDist(dest1, N);
	if (temp2 == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	ret2 += temp2;

	cout << min(ret1, ret2);
	return 0;
}