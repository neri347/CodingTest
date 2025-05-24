/// 순서대로 방문하기
/// https://softeer.ai/practice/6246
#include <iostream>
#include <vector>
using namespace std;

int N;
int answer;
int board[4][4];
bool isVisited[4][4];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
vector<pair<int, int>> pos;

void DFS(int x, int y, int index)
{
	if (index >= pos.size() - 1)
	{
		answer++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !isVisited[nx][ny])
		{
			if (board[nx][ny] == 0)
			{
				isVisited[nx][ny] = true;
				DFS(nx, ny, index);
				isVisited[nx][ny] = false;
			}
			else if (board[nx][ny] == 2 && nx == pos[index + 1].first && ny == pos[index + 1].second)
			{
				// board == 2이면서 다음 지점이면 방문가능
				isVisited[nx][ny] = true;
				DFS(nx, ny, index + 1);
				isVisited[nx][ny] = false;
			}
		}
	}
}

int main()
{
	int M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = 2;
		pos.push_back({ x - 1, y - 1 });
	}

	DFS(pos[0].first, pos[0].second, 0);
	cout << answer;

	return 0;
}