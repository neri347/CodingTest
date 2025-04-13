/// 트리의 부모 찾기
/// https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> parents;

void DFS(int x, int parent)
{
	parents[x] = parent;
	for (auto& child : graph[x])
	{
		if (child != parent)
		{
			DFS(child, x);
		}
	}
}

int main()
{
	cin >> N;
	graph.resize(N);
	parents.resize(N);

	for (int i = 0; i < N - 1; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1 - 1].push_back(node2 - 1);
		graph[node2 - 1].push_back(node1 - 1);
	}

	DFS(0, 0);
	for (int i = 1; i < parents.size(); i++)
	{
		cout << parents[i] + 1 << '\n';
	}

	return 0;
}