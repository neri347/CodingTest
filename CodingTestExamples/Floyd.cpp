/// �÷��̵�
/// https://www.acmicpc.net/problem/11404
/// �÷��̵�-���� �˰��� : ��� �������� ��� ���������� �ִ� ��θ� ���ϴ� �˰���
/// ���ͽ�Ʈ�� �˰����� �� �������� �ٸ� ��� ���������� �ִ� ��θ� ���ϴ� �˰���
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

	// k = ���İ��� ���
	for (int k = 0; k < N; k++)
	{
		// i = ���� ���
		for (int i = 0; i < N; i++)
		{
			// j = ���� ���
			for (int j = 0; j < N; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// ���
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