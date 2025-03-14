/// 플로이드
/// https://www.acmicpc.net/problem/11404
/// 플로이드-워셜 알고리즘 : 모든 정점에서 모든 정점까지의 최단 경로를 구하는 알고리즘
/// 다익스트라 알고리즘은 한 정점에서 다른 모든 정점까지의 최단 경로를 구하는 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 10000000;

int N, M;
int dist[100][100];

int main()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		dist[from - 1][to - 1] = min(dist[from - 1][to - 1], cost);
	}

	// k = 거쳐가는 노드
	for (int k = 0; k < N; k++)
	{
		// i = 시작 노드
		for (int i = 0; i < N; i++)
		{
			// j = 도착 노드
			for (int j = 0; j < N; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dist[i][j] == INF ? cout << 0 : cout << dist[i][j];
			cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}