/// 연결 요소의 개수
/// https://www.acmicpc.net/problem/11724
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> graph;
bool isVisited[1001];

void DFS(int node, int parent)
{
	for (auto& connected : graph[node])
	{
		if (connected == parent)	continue;
		if (!isVisited[connected])
		{
			isVisited[connected] = true;
			DFS(connected, node);
		}
	}
}

int main()
{
	cin >> N >> M;
	graph.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!isVisited[i])
		{
			++answer;
			isVisited[i] = true;
			DFS(i, i);
		}
	}
	cout << answer;
	return 0;
}