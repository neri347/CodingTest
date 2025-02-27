/// 2���� �迭�� ����
/// https://www.acmicpc.net/problem/17140
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 1�� ���� ������ ���� ����
// R ����: �迭 A�� ��� �࿡ ���ؼ� ������ �����Ѵ�. ���� ���� �� ���� ������ ��쿡 ����ȴ�.
// C ���� : �迭 A�� ��� ���� ���ؼ� ������ �����Ѵ�.���� ���� < ���� ������ ��쿡 ����ȴ�.
// A[r][c] = k �� �ɶ����� �ɸ��� �ð� ���ϱ�

int A[101][101];

class Cmp
{
public:
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		if (p1.second == p2.second)
		{
			return p1.first > p2.first;
		}
		return p1.second > p2.second;
	}
};

int main()
{
	int r, c, k;
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			int v;
			cin >> v;
			A[i][j] = v;
		}
	}

	int maxRow = 4;
	int maxColumn = 4;

	// ���ʸ��� ���� ����
	for (int i = 0; i <= 100; i++)
	{
		if (A[r][c] == k)
		{
			cout << i;
			return 0;
		}

		// ����
		if (maxRow >= maxColumn) // R����(�ళ�� >= ������)
		{
			for (int i = 1; i < maxRow; i++)
			{
				int C[101] = { 0, };
				// ���� ���� ����
				for (int j = 1; j < maxColumn; j++)
				{
					C[A[i][j]]++;
				}
				// ����
				priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq; // <����, ����>
				for (int m = 1; m < 101; m++)
				{
					if (C[m] > 0)
					{
						pq.push({ m, C[m] });
					}
				}
				// clear
				for (int j = 1; j < 101; j++)
				{
					A[i][j] = 0;
				}

				int m = 1;
				while (!pq.empty())
				{
					int e = pq.top().first;
					int c = pq.top().second;
					pq.pop();
					A[i][m++] = e;
					A[i][m++] = c;
					if (m >= 101)
					{
						break;
					}
				}
				maxColumn = max(maxColumn, m);
			}
		}
		else // C����
		{
			for (int i = 1; i < maxColumn; i++)
			{
				int C[101] = { 0, };
				// ���� ���� ����
				for (int j = 1; j < maxRow; j++)
				{
					C[A[j][i]]++;
				}
				// ����
				priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq; // <����, ����>
				for (int m = 1; m < 101; m++)
				{
					if (C[m] > 0)
					{
						pq.push({ m, C[m] });
					}
				}
				
				// clear
				for (int j = 1; j < 101; j++)
				{
					A[j][i] = 0;
				}

				int m = 1;
				while (!pq.empty())
				{
					int e = pq.top().first;
					int c = pq.top().second;
					pq.pop();
					A[m++][i] = e;
					A[m++][i] = c;
					if (m >= 101)
					{
						break;
					}
				}
				maxRow = max(maxRow, m);
			}
		}
	}

	cout << -1;
	return 0;
}