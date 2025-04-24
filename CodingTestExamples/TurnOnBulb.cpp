/// 전구를 켜라
/// https://www.acmicpc.net/problem/2423
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 99999999;

struct Info
{
	int x;
	int y;
	int count;
};

struct Cmp
{
	bool operator()(const Info& a, const Info& b)
	{
		return a.count > b.count;
	}
};

vector<Info> graph[501][501];
int rotates[501][501];
int sx[4] = { 1,0,0,-1 };
int sy[4] = { 0,1,-1,0 };
int dx[4] = { -1,-1,1,1 };
int dy[4] = { -1,1,-1,1 };

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '/')
			{
				graph[i][j + 1].push_back({ i + 1, j, 0 });
				graph[i + 1][j].push_back({ i, j + 1, 0 });
				graph[i][j].push_back({ i + 1, j + 1, 1 });
				graph[i + 1][j + 1].push_back({ i, j, 1 });
			}
			else
			{
				graph[i][j].push_back({ i + 1, j + 1, 0 });
				graph[i + 1][j + 1].push_back({ i, j, 0 });
				graph[i][j + 1].push_back({ i + 1, j, 1 });
				graph[i + 1][j].push_back({ i, j + 1, 1 });
			}
		}
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			rotates[i][j] = MAX;
		}
	}

	priority_queue<Info, vector<Info>, Cmp> pq;
	pq.push({ 0, 0, 0});
	rotates[0][0] = 0;

	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int count = pq.top().count;
		pq.pop();

		if (rotates[x][y] < count)
		{
			continue;
		}

		for (auto& next : graph[x][y])
		{
			int nx = next.x;
			int ny = next.y;
			int nc = next.count;
			if (rotates[nx][ny] > count + nc)
			{
				rotates[nx][ny] = count + nc;
				pq.push({ nx, ny, count + nc });
			}
		}
	}
	rotates[N][M] == MAX ? (cout << "NO SOLUTION") : (cout << rotates[N][M]);
	return 0;
}