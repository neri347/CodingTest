/// 토마토
/// https://www.acmicpc.net/problem/7569
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dh[2] = { -1,1 };

int main()
{
	int N, M, H;
	cin >> M >> N >> H;
	vector<vector<vector<int>>> tomatoes;
	vector<vector<vector<bool>>> isVisited(H, vector<vector<bool>>(N, vector<bool>(M, false)));
	queue<tuple<int, int, int, int>> q; // h, n, m, count
	int answer = 0;

	for (int h = 0; h < H; h++)
	{
		vector<vector<int>> temp;
		for (int i = 0; i < N; i++)
		{
			vector<int> vec;
			for (int j = 0; j < M; j++)
			{
				int num;
				cin >> num;
				vec.push_back(num);
				if (num == 1)
				{
					q.push({ h, i, j, 0 });
					isVisited[h][i][j] = true;
				}
			}
			temp.push_back(vec);
		}
		tomatoes.push_back(temp);
	}

	while (!q.empty())
	{
		int ch = get<0>(q.front());
		int cx = get<1>(q.front());
		int cy = get<2>(q.front());
		int count = get<3>(q.front());
		answer = count;
		q.pop();

		tomatoes[ch][cx][cy] = 1;

		// 상하좌우
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && tomatoes[ch][nx][ny] == 0 && !isVisited[ch][nx][ny])
			{
				isVisited[ch][nx][ny] = true;
				q.push({ ch, nx, ny, count + 1 });
			}
		}
		// 위, 아래 상자
		for (int i = 0; i < 2; i++)
		{
			int nh = ch + dh[i];
			if (nh >= 0 && nh < H && tomatoes[nh][cx][cy] == 0 && !isVisited[nh][cx][cy])
			{
				isVisited[nh][cx][cy] = true;
				q.push({ nh, cx, cy, count + 1 });
			}
		}
	}

	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (tomatoes[h][i][j] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << answer;

	return 0;
}