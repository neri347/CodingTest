/// 케빈 베이컨의 6단계 법칙
/// https://www.acmicpc.net/problem/1389
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> graph;
bool isVisited[101];

bool Cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	int N, M;
	cin >> N >> M;
	graph.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	vector<pair<int, int>> kevinBacons;
	for (int start = 1; start < N + 1; start++)
	{
		memset(isVisited, false, sizeof(isVisited));
		queue<pair<int, int>> q; // node, step
		q.push({ start, 0 });
		isVisited[start] = true;
		int kevinBacon = 0;
		
		while (!q.empty())
		{
			int node = q.front().first;
			int step = q.front().second;
			q.pop();

			kevinBacon += step;

			for (auto& connected : graph[node])
			{
				if (!isVisited[connected])
				{
					isVisited[connected] = true;
					q.push({ connected, step + 1 });
				}
			}
		}

		kevinBacons.push_back({ start, kevinBacon });
	}

	sort(kevinBacons.begin(), kevinBacons.end(), Cmp);
	cout << kevinBacons[0].first;

	return 0;
}