/// 줄 세우기
/// https://www.acmicpc.net/problem/2252
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N + 1);
	vector<int> degree(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		int front, back;
		cin >> front >> back;
		graph[front].push_back(back);
		degree[back]++;
	}

	queue<int> q;
	vector<bool> isVisited(N + 1, false);
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
			isVisited[i] = true;
		}
	}

	vector<int> answer;
	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		answer.push_back(num);

		for (auto& next : graph[num])
		{
			--degree[next];
			if (!isVisited[next] && degree[next] == 0)
			{
				isVisited[next] = true;
				q.push(next);
			}
		}
	}

	for (auto& num : answer)
	{
		cout << num << ' ';
	}

	return 0;
}