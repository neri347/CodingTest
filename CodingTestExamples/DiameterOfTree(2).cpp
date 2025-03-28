/// Ʈ���� ����
/// https://www.acmicpc.net/problem/1967
#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> graph;
int maxDepth;
int maxDepthNode;

void DFS(int node, int parent, int depth)
{
	if (depth > maxDepth)
	{
		maxDepth = depth;
		maxDepthNode = node;
	}

	for (auto& [next, weight] : graph[node])
	{
		if (next == parent) continue;
		DFS(next, node, depth + weight);
	}
}

int main()
{
	// �Է�
	int N;
	cin >> N;
	graph.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({ to, weight });
		graph[to].push_back({ from, weight });
	}

	// Ǯ��
	// ��Ʈ�κ��� ���� �ָ� ������ ��带 ���Ѵ�.
	DFS(1, 1, 0);
	int node = maxDepthNode;
	maxDepth = 0;
	maxDepthNode = 0;
	// ���� �ָ� ������ ���κ��� ���� �ָ� �ִ� �������� �Ÿ��� ���Ѵ�.
	DFS(node, node, 0);

	cout << maxDepth;

	return 0;
}