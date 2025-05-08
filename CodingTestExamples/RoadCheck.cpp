/// 도로검문
/// https://www.acmicpc.net/problem/2307
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 999999999;
int N, M;
vector<vector<pair<int, int>>> graph;

struct Cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

int CalcDist()
{
	vector<int> dist(N, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	pq.push({ 0, 0 });
	dist[0] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().first;
		int d = pq.top().second;
		pq.pop();

		for (auto& [next, weight] : graph[cur])
		{
			if (dist[next] > d + weight)
			{
				dist[next] = d + weight;
				pq.push({ next, dist[next] });
			}
		}
	}
	return dist[N - 1];
}

int main()
{
	cin >> N >> M;
	graph.resize(N);
	vector<pair<pair<int, int>, int>> edges;
	for (int i = 0; i < M; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from - 1].push_back({ to - 1, weight });
		graph[to - 1].push_back({ from - 1, weight });
		edges.push_back({ { from - 1, to - 1 }, weight });
	}

	int minTime = CalcDist();

	int answer = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int from = edges[i].first.first;
		int to = edges[i].first.second;
		int weight = edges[i].second;
		graph[from].erase(remove_if(graph[from].begin(), graph[from].end(), [&](const pair<int, int>& a) {return a.first == to; }), graph[from].end());
		graph[to].erase(remove_if(graph[to].begin(), graph[to].end(), [&](const pair<int, int>& a) {return a.first == from; }), graph[to].end());
		int t = CalcDist();
		if (t == MAX)
		{
			answer = MAX;
		}
		else
		{
			answer = max(answer, t - minTime);
		}
		graph[from].push_back({ to, weight });
		graph[to].push_back({ from, weight });
	}

	answer == MAX ? cout << -1 : cout << answer;

	return 0;
}