/// Ÿ�Ӹӽ�
/// https://www.acmicpc.net/problem/11657
#include <iostream>
#include <vector>
using namespace std;

#define INF 999999999

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> adjList(N);
	for (int i = 0; i < M; i++)
	{
		int start, end, time;
		cin >> start >> end >> time;
		adjList[start - 1].push_back({ end - 1, time });
	}

	vector<long long> distance(N, INF);
	// ������ = 0 �� ����
	distance[0] = 0;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (auto& [to, weight] : adjList[j])
			{
				if (distance[j] == INF)	continue;
				// ���� ��带 ���İ��� ���� �� ������ ����
				if (distance[j] + weight < distance[to])
				{
					distance[to] = distance[j] + weight;
				}
			}
		}
	}

	// ���� ��ȯ Ȯ��
	for (int j = 0; j < N; j++)
	{
		for (auto& [to, weight] : adjList[j])
		{
			if (distance[j] == INF)	continue;
			if (distance[j] + weight < distance[to])
			{
				cout << -1;
				return 0;
			}
		}
	}

	for (int i = 1; i < N; i++)
	{
		if (distance[i] == INF)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << distance[i] << "\n";
		}
	}

	return 0;
}