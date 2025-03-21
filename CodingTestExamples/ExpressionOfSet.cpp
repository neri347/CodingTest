/// 집합의 표현
/// https://www.acmicpc.net/problem/1717
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> parent;

int Find(int node)
{
	if (node == parent[node])
	{
		return node;
	}
	parent[node] = Find(parent[node]);
	return parent[node];
}

void Union(int x, int y)
{
	int root1 = Find(x);
	int root2 = Find(y);
	if (root1 != root2)
	{
		parent[root2] = root1;
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	// 초기 각 노드의 부모는 자기자신
	for (int i = 0; i <= N; i++)
	{
		parent.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		int command, node1, node2;
		scanf("%d %d %d", &command, &node1, &node2);
		if (command == 0) // 합집합
		{
			Union(node1, node2);
		}
		else // 파인드
		{
			Find(node1) == Find(node2) ? printf("YES\n") : printf("NO\n");
		}
	}

	return 0;
}