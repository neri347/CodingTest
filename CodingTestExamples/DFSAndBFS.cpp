/// DFS와 BFS
/// https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> connected;
vector<bool> isVisited;

void DFS(int cur, vector<int>& vec)
{
	isVisited[cur] = true;
	vec.push_back(cur);

	for (int i = 0; i < connected[cur].size(); i++)
	{
		int next = connected[cur][i];
		if (!isVisited[next])
		{
			DFS(next, vec);
		}
	}
}

void BFS(int cur, vector<int>& vec)
{
	queue<int> q;
	q.push(cur);
	isVisited[cur] = true;

	while (!q.empty())
	{
		int current = q.front();
		vec.push_back(current);
		q.pop();

		for (auto& e : connected[current])
		{
			if (!isVisited[e])
			{
				isVisited[e] = true;
				q.push(e);
			}
		}
	}
}

int main()
{
	int V, E, start;
	cin >> V >> E >> start;
	--start;
	connected.resize(V);
	for (int i = 0; i < E; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		connected[v1 - 1].push_back(v2 - 1);
		connected[v2 - 1].push_back(v1 - 1);
	}

	// 정점 번호가 작은 순대로 방문하기 위해 정렬
	for (int i = 0; i < connected.size(); i++)
	{
		sort(connected[i].begin(), connected[i].end());
	}

	isVisited.resize(V, false);
	vector<int> dfs;
	DFS(start, dfs);

	vector<int> bfs;
	isVisited.assign(V, false);
	BFS(start, bfs);

	for (auto& e : dfs)
	{
		cout << e + 1 << " ";
	}
	cout << "\n";
	for (auto& e : bfs)
	{
		cout << e + 1 << " ";
	}

	return 0;
}