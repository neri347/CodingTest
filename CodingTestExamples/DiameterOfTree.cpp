/// Ʈ���� ����
/// https://www.acmicpc.net/problem/1167
#include <iostream>
#include <vector>
using namespace std;

int N;
pair<int, int> deepest; // node, depth
vector<vector<pair<int, int>>> graph;

void DFS(int node, int parent, int length)
{
	if (length > deepest.second)
	{
		deepest.first = node;
		deepest.second = length;
	}

	for (auto& p : graph[node])
	{
		int child = p.first;
		int weight = p.second;
		if (child == parent)
		{
			continue;
		}
		DFS(child, node, length + weight);
	}
}

int main()
{
	cin >> N;
	graph.resize(N + 1);
	// �Է�
	for (int i = 0; i < N; i++)
	{
		int node;
		cin >> node;
		bool flag = true;
		while (flag)
		{
			pair<int, int> p;
			for (int j = 0; j < 2; j++)
			{
				int v;
				cin >> v;
				if (v == -1)
				{
					flag = false;
					break;
				}

				if (j == 0)
				{
					p.first = v;
				}
				else
				{
					p.second = v;
				}
			}

			if (flag)
			{
				graph[node].push_back(p);
			}
		}
	}

	// Ǯ��
	// �ƹ� ���κ��� ���� �ָ� ������ ��带 ���Ѵ�.
	DFS(1, 1, 0);
	deepest.second = 0;
	// ���� ���κ��� ���� �ָ� ������ �������� �Ÿ��� ���Ѵ�.
	DFS(deepest.first, deepest.first, 0);
	cout << deepest.second;
	return 0;
}