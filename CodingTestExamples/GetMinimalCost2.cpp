/// 최소비용 구하기 2
/// https://www.acmicpc.net/problem/11779
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 99999999;

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
	int start, end;
	cin >> start >> end;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist, node
	vector<int> dist(N + 1, MAX);
	vector<bool> isVisited(N + 1, false);
	vector<int> route(N + 1);
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (isVisited[node])
		{
			continue;
		}

		isVisited[node] = true;

		for (auto& [next, weight] : graph[node])
		{
			if (curDist + weight < dist[next])
			{
				dist[next] = curDist + weight;
				pq.push({ dist[next], next });
				route[next] = node;
			}
		}
	}

	vector<int> answer;
	answer.push_back(end);
	int cur = end;
	while (cur != start)
	{
		int prev = route[cur];
		answer.push_back(prev);
		cur = prev;
	}
	reverse(answer.begin(), answer.end());

	cout << dist[end] << '\n';
	cout << answer.size() << '\n';
	for (auto& e : answer)
	{
		cout << e << " ";
	}

	return 0;
}