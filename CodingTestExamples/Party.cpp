/// ÆÄÆ¼
/// https://www.acmicpc.net/problem/1238
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 99999999;

struct Cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

int main()
{
	int N, M, X;
	cin >> N >> M >> X;
	vector<vector<pair<int, int>>> graph(N);
	vector<vector<pair<int, int>>> graph2(N);
	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from - 1].push_back({ to - 1, cost });
		graph2[to - 1].push_back({ from - 1, cost });
	}

	vector<int> dist(N, MAX);
	dist[X - 1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	pq.push({ X - 1, 0 });

	while (!pq.empty())
	{
		int cur = pq.top().first;
		int d = pq.top().second;
		pq.pop();

		for (auto& [next, cost] : graph[cur])
		{
			if (dist[next] > d + cost)
			{
				dist[next] = d + cost;
				pq.push({ next, dist[next] });
			}
		}
	}

	vector<int> dist2(N, MAX);
	dist2[X - 1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq2;
	pq2.push({ X - 1, 0 });

	while (!pq2.empty())
	{
		int cur = pq2.top().first;
		int d = pq2.top().second;
		pq2.pop();

		for (auto& [next, cost] : graph2[cur])
		{
			if (dist2[next] > d + cost)
			{
				dist2[next] = d + cost;
				pq2.push({ next, dist2[next] });
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer = max(answer, dist[i] + dist2[i]);
	}

	cout << answer;

	return 0;
}