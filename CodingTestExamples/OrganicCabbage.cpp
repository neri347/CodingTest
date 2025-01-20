/// 유기농 배추
/// https://www.acmicpc.net/problem/1012
#include <iostream>
#include <vector>
using namespace std;

int N, M; // 세로, 가로
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void DFS(int cx, int cy, int ground[][50], bool isVisited[][50])
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			if (ground[nx][ny] == 1 && !isVisited[nx][ny])
			{
				isVisited[nx][ny] = true;
				DFS(nx, ny, ground, isVisited);
			}
		}
	}
}

int main()
{
	vector<int> answer;
	int T;
	cin >> T;
	// 테스트 케이스마다
	for (int i = 0; i < T; ++i)
	{
		int ground[50][50] = { 0, };
		bool isVisited[50][50] = { 0, };
		int count;
		cin >> M >> N >> count;
		// 배추 심어진 위치
		for (int c = 0; c < count; ++c)
		{
			int x, y;
			cin >> x >> y; // 가로 세로
			ground[y][x] = 1;
		}

		int worm = 0;
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				if (ground[r][c] == 1 && !isVisited[r][c])
				{
					// 연결된 곳 세기
					isVisited[r][c] = true;
					DFS(r, c, ground, isVisited);
					++worm;
				}
			}
		}
		answer.push_back(worm);
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}