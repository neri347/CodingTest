/// 도시 분할 계획
/// https://www.acmicpc.net/problem/1647
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100000];

int Find(int node)
{
	if (parent[node] == node)
	{
		return node;
	}
	parent[node] = Find(parent[node]);
	return parent[node];
}

bool IsCycle(int node1, int node2)
{
	return Find(node1) == Find(node2);
}

void Union(int node1, int node2)
{
	int root1 = Find(node1);
	int root2 = Find(node2);
	if (root1 != root2)
	{
		parent[root2] = root1;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<pair<int, pair<int, int>>> roads;
	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		roads.push_back({ cost, {from - 1, to - 1} });
	}

	// 처음에 모든 노드의 부모는 자기 자신이다.
	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}

	sort(roads.begin(), roads.end());

	vector<int> costs;
	// 비용 작은 길부터 추가
	for (auto& road : roads)
	{
		int node1 = road.second.first;
		int node2 = road.second.second;
		int cost = road.first;

		if (!IsCycle(node1, node2))
		{
			Union(node1, node2);
			costs.push_back(cost);
		}
	}

	int answer = 0;
	for (int i = 0; i < costs.size() - 1; i++)
	{
		answer += costs[i];
	}
	cout << answer;
	return 0;
}