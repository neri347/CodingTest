/// 서강그라운드
/// https://www.acmicpc.net/problem/14938
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 99999999;
int dist[100][100];
int items[100];

int main()
{
	int N, M, R;
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
	{
		cin >> items[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)	continue;
			dist[i][j] = MAX;
		}
	}

	for(int i = 0; i < R; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		dist[from - 1][to - 1] = min(dist[from - 1][to - 1], weight);
		dist[to - 1][from - 1] = min(dist[to - 1][from - 1], weight);
	}
	
	for (int connected = 0; connected < N; connected++)
	{
		for (int start = 0; start < N; start++)
		{
			for (int end = 0; end < N; end++)
			{
				if (dist[start][connected] + dist[connected][end] < dist[start][end])
				{
					dist[start][end] = dist[start][connected] + dist[connected][end];
				}
			}
		}
	}

	int answer = 0;
	for (int start = 0; start < N; start++)
	{
		int count = 0;
		for (int end = 0; end < N; end++)
		{
			if (dist[start][end] <= M)
			{
				count += items[end];
			}
		}
		answer = max(answer, count);
	}
	cout << answer;
	return 0;
}