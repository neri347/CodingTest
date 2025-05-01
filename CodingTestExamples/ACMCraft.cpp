/// ACM Craft
/// https://www.acmicpc.net/problem/1005
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, K;
		cin >> N >> K;

		vector<int> times;
		for (int i = 0; i < N; i++)
		{
			int time;
			cin >> time;
			times.push_back(time);
		}

		vector<vector<int>> graph(N + 1);
		vector<int> connected(N + 1, 0);
		vector<int> dp(N + 1, 0);
		for (int i = 0; i < K; i++)
		{
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			connected[to]++;
		}

		int W;
		cin >> W;

		queue<int> q;
		for (int i = 1; i < connected.size(); i++)
		{
			if (connected[i] == 0)
			{
				dp[i] = times[i - 1];
				q.push(i);
			}
		}

		while (!q.empty())
		{
			int num = q.front();
			q.pop();

			for (auto& next : graph[num])
			{
				dp[next] = max(dp[next], dp[num] + times[next - 1]);
				connected[next]--;
				if (connected[next] == 0)
				{
					q.push(next);
				}
			}
		}
		cout << dp[W] << '\n';
	}
	return 0;
}