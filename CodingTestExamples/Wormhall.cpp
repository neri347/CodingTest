/// ¿úÈ¦
/// https://www.acmicpc.net/problem/1865
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 99999999;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, M, W;
		cin >> N >> M >> W;
		vector<vector<pair<int, int>>> graph(N + 1);
		for (int i = 0; i < M; i++)
		{
			int from, to, cost;
			cin >> from >> to >> cost;
			graph[from].push_back({ to, cost });
			graph[to].push_back({ from, cost });
		}
		for (int i = 0; i < W; i++)
		{
			int from, to, cost;
			cin >> from >> to >> cost;
			graph[from].push_back({ to, -cost });
		}

		// Bellman-Ford
		vector<int> dist(N + 1, MAX);
		dist[1] = 0;

		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				for (auto& [to, cost] : graph[j])
				{
					if (dist[to] > dist[j] + cost)
					{
						dist[to] = dist[j] + cost;
					}
				}
			}
		}

		bool flag = false;
		for (int j = 1; j <= N; j++)
		{
			for (auto& [to, cost] : graph[j])
			{
				if (dist[to] > dist[j] + cost)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}

		flag == true ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}