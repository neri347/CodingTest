/// 2차원 배열과 연산
/// https://www.acmicpc.net/problem/17140
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 1초 지날 때마다 연산 수행
// R 연산: 배열 A의 모든 행에 대해서 정렬을 수행한다. 행의 개수 ≥ 열의 개수인 경우에 적용된다.
// C 연산 : 배열 A의 모든 열에 대해서 정렬을 수행한다.행의 개수 < 열의 개수인 경우에 적용된다.
// A[r][c] = k 가 될때까지 걸리는 시간 구하기

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

	// 매초마다 연산 수행
	for (int i = 0; i <= 100; i++)
	{
		if (A[r][c] == k)
		{
			cout << i;
			return 0;
		}

		// 정렬
		if (maxRow >= maxColumn) // R연산(행개수 >= 열개수)
		{
			for (int i = 1; i < maxRow; i++)
			{
				int C[101] = { 0, };
				// 원소 개수 세기
				for (int j = 1; j < maxColumn; j++)
				{
					C[A[i][j]]++;
				}
				// 정렬
				priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq; // <원소, 개수>
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
		else // C연산
		{
			for (int i = 1; i < maxColumn; i++)
			{
				int C[101] = { 0, };
				// 원소 개수 세기
				for (int j = 1; j < maxRow; j++)
				{
					C[A[j][i]]++;
				}
				// 정렬
				priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq; // <원소, 개수>
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