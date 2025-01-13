/// 게임 개발
/// https://www.acmicpc.net/problem/1516
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> connected(n);
	vector<int> degree(n, 0);
	vector<int> time(n, 0);
	vector<int> dp(n, 0);
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		time[i] = t;
		while (true)
		{
			int num;
			cin >> num;
			if (num == -1)
			{
				break;
			}
			connected[num - 1].push_back(i);
			degree[i]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (degree[i] == 0)
		{
			q.push(i);
			dp[i] = time[i];
		}
	}

	// 위상정렬
	for (int i = 0; i < n; ++i)
	{
		int idx = q.front();
		q.pop();
		
		// 이 노드와 연결된 노드들과의 연결을 끊는다 -> 연결된 노드들의 차수가 1씩 낮아진다
		// A 건물을 짓기 위해 걸리는 시간은
		// A 건물을 짓기 위해 먼저 지어야 하는 건물들 중에서 가장 오래 걸리는 시간 + A 건물 짓는데 걸리는 시간
		for (int j = 0; j < connected[idx].size(); ++j)
		{
			int connectedNode = connected[idx][j];
			dp[connectedNode] = max(dp[connectedNode], dp[idx] + time[connectedNode]);
			// 차수가 0이 된 노드를 큐에 삽입
			if (--degree[connectedNode] == 0)
			{
				q.push(connectedNode);
			}
		}		
	}

	// 출력
	for (int i = 0; i < n; ++i)
	{
		cout << dp[i] << "\n";
	}

	return 0;
}