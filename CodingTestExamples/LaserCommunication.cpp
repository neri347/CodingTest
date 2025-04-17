/// 레이저 통신
/// https://www.acmicpc.net/problem/6087
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 99999999;

char board[100][100];
int mirror[100][100];
bool isVisited[100][100][4];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> pos;

struct Info
{
	int x;
	int y;
	int dir;
	int count;
	int weight;
};

struct Cmp
{
	bool operator()(const Info& a, const Info& b)
	{
		if (a.count == b.count)
		{
			return a.weight < b.weight;
		}
		return a.count > b.count;
	}
};

int main()
{
	int W, H;
	cin >> W >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'C')
			{
				pos.push_back({ i, j });
			}
			mirror[i][j] = MAX;
		}
	}

	priority_queue<Info, vector<Info>, Cmp> pq;
	pq.push({ pos[0].first, pos[0].second, -1, 0, 1 });
	mirror[pos[0].first][pos[0].second] = 0;

	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int dir = pq.top().dir;
		int count = pq.top().count;
		pq.pop();

		if (mirror[x][y] < count)
		{
			continue;
		}

		if (x == pos[1].first && y == pos[1].second)
		{
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < H && ny >= 0 && ny < W && board[nx][ny] != '*')
			{
				int nc = (dir == -1 || dir == i) ? count : count + 1;
				int nw = (dir == -1 || dir == i) ? 1 : 0;
				if (nc <= mirror[nx][ny])
				{
					mirror[nx][ny] = nc;
					if (!isVisited[nx][ny][i])
					{
						isVisited[nx][ny][i] = true;
						pq.push({ nx, ny, i, nc, nw });
					}
				}
			}
		}
	}
	cout << mirror[pos[1].first][pos[1].second];
	return 0;
}