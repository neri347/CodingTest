/// 최소비용 구하기
/// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 99999999;

struct Cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second == b.second)
		{
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> graph(N + 1);
	for (int i = 0; i < M; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({ to, weight });
	}
	int S, E;
	cin >> S >> E;

	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq; // to, weight
	vector<int> dist(N + 1, MAX);
	vector<bool> isVisited(N + 1, false);
	pq.push({ S, 0 });
	dist[S] = 0;

	while (!pq.empty())
	{
		int node = pq.top().first;
		int curDist = pq.top().second;
		pq.pop();

		if (isVisited[node])
		{
			continue;
		}
		isVisited[node] = true;

		for (auto& [connected, weight] : graph[node])
		{
			if (curDist + weight < dist[connected])
			{
				dist[connected] = curDist + weight;
				pq.push({ connected, dist[connected] });
			}
		}
	}

	cout << dist[E];
	return 0;
}