/// 트리의 부모 찾기
/// https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> graph;
int parents[100001];

void DFS(int node, int parent)
{
	parents[node] = parent;

	for (auto& next : graph[node])
	{
		if (parents[next] == 0)
		{
			DFS(next, node);
		}
	}
}

int main()
{
	cin >> N;
	graph.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	DFS(1, 1);

	for (int i = 2; i <= N; i++)
	{
		cout << parents[i] << '\n';
	}

	return 0;
}