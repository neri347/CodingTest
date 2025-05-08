/// ³ì»ö ¿Ê ÀÔÀº ¾Ö°¡ Á©´ÙÁö?
/// https://www.acmicpc.net/problem/4485
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 999999999;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int board[125][125];

struct Cmp
{
	bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b)
	{
		return a.second > b.second;
	}
};

int main()
{
	int t = 0;
	while (true)
	{
		int N;
		cin >> N;
		t++;
		if (N == 0)
		{
			break;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
			}
		}

		vector<vector<int>> costs(N, vector<int>(N, MAX));
		priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, Cmp> pq;
		pq.push({ {0, 0}, board[0][0] });
		costs[0][0] = board[0][0];

		while (!pq.empty())
		{
			int x = pq.top().first.first;
			int y = pq.top().first.second;
			int c = pq.top().second;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)
				{
					if (costs[nx][ny] > c + board[nx][ny])
					{
						costs[nx][ny] = c + board[nx][ny];
						pq.push({ {nx, ny}, costs[nx][ny] });
					}
				}
			}
		}

		cout << "Problem " << t << ": " << costs[N - 1][N - 1] << '\n';
	}
	return 0;
}