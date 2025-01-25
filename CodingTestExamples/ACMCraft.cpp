#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N, K;
		int endPoint;
		cin >> N >> K;
		vector<int> times(N + 1, 0);
		vector<vector<int>> connected(N + 1);
		vector<int> degree(N + 1, 0); // 시작건물은 차수가 0이다.
		vector<int> dp(N + 1, 0);
		// 입력
		for (int j = 1; j <= N; j++)
		{
			int time;
			cin >> time;
			times[j] = time;
		}
		for (int j = 0; j < K; ++j)
		{
			int from, to;
			cin >> from >> to;
			connected[from].push_back(to);
			degree[to]++;
		}
		cin >> endPoint;

		// 풀이
		queue<int> q;
		for (int j = 1; j < degree.size(); j++)
		{
			if (degree[j] == 0)
			{
				q.push(j);
				dp[j] = times[j];
			}
		}

		while (!q.empty())
		{
			int idx = q.front();
			q.pop();

			for (int node : connected[idx])
			{
				dp[node] = max(dp[node], dp[idx] + times[node]);
				if (--degree[node] == 0)
				{
					q.push(node);
				}
			}
		}

		cout << dp[endPoint] << "\n";
	}
	return 0;
}